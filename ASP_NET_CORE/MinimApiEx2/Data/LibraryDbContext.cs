using Microsoft.EntityFrameworkCore;

public class LibrayDbContext : DbContext
{
    public LibrayDbContext(DbContextOptions options) : base(options) {}
    public DbSet<Book> Books{ get; set; } //tabla
    public DbSet<Author> Authors{ get; set; }
    public DbSet<Category> Categories{ get; set; }

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        //configurar realciones
        modelBuilder.Entity<Book>().HasOne(b => b.Author).WithMany
        (a => a.Books).HasForeignKey(b => b.AuthorId);

        modelBuilder.Entity<Book>().HasOne(b => b.Category).WithMany
        (c => c.Books).HasForeignKey(b => b.CategoryId);
    }
}