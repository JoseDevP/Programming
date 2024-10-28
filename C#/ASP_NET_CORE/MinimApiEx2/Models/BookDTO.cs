public class BookDTO
{
    public int Id { get; set; }
    public string? Title { get; set; }
    public int PublishedYear { get; set; }
    
    public int AuthorId { get; set; } 
    public int CategoryId { get; set; }

    public BookDTO() {}

    public BookDTO(Book book)
    {
        Id = book.Id;
        Title = book.Title;
        PublishedYear = book.PublishedYear;
        AuthorId = book.AuthorId;
        CategoryId = book.CategoryId;
    }
}
