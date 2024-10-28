using Microsoft.EntityFrameworkCore;

var builder = WebApplication.CreateBuilder(args);
builder.Services.AddDbContext<LibrayDbContext>(options => options.UseInMemoryDatabase("Library") );
builder.Services.AddDatabaseDeveloperPageExceptionFilter();

builder.Services.AddEndpointsApiExplorer();
builder.Services.AddOpenApiDocument(config => 
{
    config.DocumentName = "LibraryAPI";
    config.Title = "LibraryAPI v1";
    config.Version = "v1";
});

var app = builder.Build();

if(app.Environment.IsDevelopment())
{
    app.UseOpenApi();
    app.UseSwaggerUi(c =>
    {
        c.DocumentTitle = "LibraryAPI";
        c.Path = "/swagger";
        c.DocumentPath = "/swagger/{documentName}/swagger.json";
        c.DocExpansion = "list";
    });
}

var books = app.MapGroup("/books");

books.MapGet("/", GetAllBooks);
books.MapPost("/", AddNewBook);
books.MapPut("/{id}", UpdateBook);
books.MapDelete("/{id}", DeleteBook);

var authors = app.MapGroup("/authors");

authors.MapGet("/", GetAllAuthors);
authors.MapPost("/", AddNewAuthor);

var categories = app.MapGroup("/categories");

categories.MapGet("/", GetAllCategories);
categories.MapPost("/", AddNewCategories);

app.Run();


//Books
static async Task<IResult> GetAllBooks(LibrayDbContext librayDbContext)
{
    try
    {
        if(librayDbContext.Books.Count() == 0)
            return TypedResults.NotFound("No books found");
        return TypedResults.Ok(await librayDbContext.Books.Select(x => new BookDTO(x)).ToArrayAsync());
    }
    catch (Exception ex)
    {
        return TypedResults.Problem("An error ocurred while getting all books"+ ex.Message);
    }
    
}

static async Task<IResult> AddNewBook(BookDTO bookDTO, LibrayDbContext librayDbContext)
{
    try
    {
        if (bookDTO == null)
        {
            return TypedResults.BadRequest("BookDTO cannot be null");
        }

        if (bookDTO.AuthorId <= 0)
        {
            return TypedResults.BadRequest("Invalid AuthorId");
        }

        if (bookDTO.CategoryId <= 0)
        {
            return TypedResults.BadRequest("Invalid CategoryId");
        }

        var author = await librayDbContext.Authors.FindAsync(bookDTO.AuthorId);
        if (author == null)
        {
            return TypedResults.NotFound($"Author with ID {bookDTO.AuthorId} not found");
        }

        var category = await librayDbContext.Categories.FindAsync(bookDTO.CategoryId);
        if (category == null)
        {
            return TypedResults.NotFound($"Category with ID {bookDTO.CategoryId} not found");
        }

        // Crear un nuevo libro
        var book = new Book
        {
            Title = bookDTO.Title,
            PublishedYear = bookDTO.PublishedYear,
            AuthorId = bookDTO.AuthorId,
            Author = author,
            CategoryId = bookDTO.CategoryId,
            Category = category
        };

        if (author.Books == null)
        {
            author.Books = new List<Book>(); 
        }
        author.Books.Add(book);

        if (category.Books == null)
        {
            category.Books = new List<Book>(); 
        }

        category.Books.Add(book);

        librayDbContext.Books.Add(book);

        await librayDbContext.SaveChangesAsync();

        return TypedResults.Created($"/books/{book.Id}", new BookDTO(book));
    }
    catch (Exception ex)
    {
        return TypedResults.Problem("An error occurred while adding new book: " + ex.Message);
    }
}


static async Task<IResult> UpdateBook(int id, LibrayDbContext librayDbContext, BookDTO bookDTO)
{
    try
    {
        var book = await librayDbContext.Books.FindAsync(id);

        if(book == null)
            return TypedResults.NotFound();

        var author = await librayDbContext.Authors.FindAsync(bookDTO.AuthorId);
        if(author == null)
        {
            return TypedResults.NotFound($"Author with ID {bookDTO.AuthorId} not found");
        }

        var category = await librayDbContext.Categories.FindAsync(bookDTO.CategoryId);
        if(category == null)
        {
            return TypedResults.NotFound($"Category with ID {bookDTO.CategoryId} not found");
        }

        book.Id = bookDTO.Id;
        book.Title = bookDTO.Title;
        book.PublishedYear = bookDTO.PublishedYear;
        book.AuthorId = bookDTO.AuthorId;
        book.Author = author;
        book.CategoryId = bookDTO.CategoryId;
        book.Category = category;

        await librayDbContext.SaveChangesAsync();

        return TypedResults.NoContent();
    }
    catch (Exception ex)
    {
        return TypedResults.Problem("An error ocurred while updating book"+ ex.Message);
    }
    
}

static async Task<IResult> DeleteBook(int id, LibrayDbContext librayDbContext)
{
    try
    {
        if(await librayDbContext.Books.FindAsync(id) is Book book)
        {
            librayDbContext.Books.Remove(book);
            await librayDbContext.SaveChangesAsync();
            return TypedResults.NoContent();
        }

        return TypedResults.NotFound();
    }
    catch (Exception ex)
    {
        return TypedResults.Problem("An error ocurred while deleting book" + ex.Message);
    }
    
}

static async Task<IResult> GetAllAuthors(LibrayDbContext librayDbContext)
{
    try 
    {
        if(librayDbContext.Authors.Count() == 0)
            return TypedResults.NotFound("No authors found");
        return TypedResults.Ok(await librayDbContext.Authors.Select(x => new AuthorDTO(x)).ToArrayAsync());
    }
    catch (Exception ex)
    {
        return TypedResults.Problem("An error ocurred while getting all authors" + ex.Message);
    }
}

static async Task<IResult> AddNewAuthor(AuthorDTO authorDTO, LibrayDbContext librayDbContext)
{
    try 
    {
        var author = new Author
        {
            Name = authorDTO.Name,
            DateOfBirth = authorDTO.DateOfBirth,
        };

        librayDbContext.Authors.Add(author);

        await librayDbContext.SaveChangesAsync();

        return TypedResults.Created($"/authors/{author.Id}", new AuthorDTO(author));

    }
    catch (Exception ex)
    {
        return TypedResults.Problem("An error ocurred while adding authors" + ex.Message);
    }
}

static async Task<IResult> GetAllCategories(LibrayDbContext librayDbContext)
{
    try 
    {
        if(librayDbContext.Categories.Count() == 0)
            return TypedResults.NotFound("No categories found");
        return TypedResults.Ok(await librayDbContext.Categories.ToArrayAsync());
    }
    catch (Exception ex)
    {
        return TypedResults.Problem("An error ocurred while getting all categories" + ex.Message);
    }
}

static async Task<IResult> AddNewCategories(CategoryDTO categoryDTO, LibrayDbContext librayDbContext)
{
    try 
    {
        var category = new Category
        {
            Name = categoryDTO.Name,
        };

        librayDbContext.Categories.Add(category);

        await librayDbContext.SaveChangesAsync();

        return TypedResults.Created($"/categories/{category.Id}", new CategoryDTO(category));

    }
    catch (Exception ex)
    {
        return TypedResults.Problem("An error ocurred while adding categories" + ex.Message);
    }
}