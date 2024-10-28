using Microsoft.EntityFrameworkCore;

class TodoDb : DbContext
{
    public TodoDb(DbContextOptions options) : base(options) {}

    public DbSet<Todo> Todos => Set<Todo>();
}