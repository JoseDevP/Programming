using System;
using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;
using Microsoft.EntityFrameworkCore.Metadata;

namespace DB.Models
{
    public partial class DogDBContext : DbContext
    {
        public DogDBContext()
        {
        }

        public DogDBContext(DbContextOptions<DogDBContext> options)
            : base(options)
        {
        }

        public virtual DbSet<Breed> Breeds { get; set; } = null!;
        public virtual DbSet<Dog> Dogs { get; set; } = null!;

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            if (!optionsBuilder.IsConfigured)
            {
#warning To protect potentially sensitive information in your connection string, you should move it out of source code. You can avoid scaffolding the connection string by using the Name= syntax to read it from configuration - see https://go.microsoft.com/fwlink/?linkid=2131148. For more guidance on storing connection strings, see http://go.microsoft.com/fwlink/?LinkId=723263.
                optionsBuilder.UseSqlServer("Server=localhost\\SQLEXPRESS; Database=Prueba; User Id=Jose; Password=1234");
            }
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Breed>(entity =>
            {
                entity.ToTable("Breed");

                entity.Property(e => e.Id).HasColumnName("ID");

                entity.Property(e => e.Name)
                    .HasMaxLength(50)
                    .IsUnicode(false);
            });

            modelBuilder.Entity<Dog>(entity =>
            {
                entity.ToTable("Dog");

                entity.Property(e => e.Id).HasColumnName("ID");

                entity.Property(e => e.BreedId).HasColumnName("BreedID");

                entity.Property(e => e.Name)
                    .HasMaxLength(50)
                    .IsUnicode(false);

                entity.HasOne(d => d.Breed)
                    .WithMany(p => p.Dogs)
                    .HasForeignKey(d => d.BreedId)
                    .OnDelete(DeleteBehavior.ClientSetNull)
                    .HasConstraintName("FK_Dog_Breed");
            });

            OnModelCreatingPartial(modelBuilder);
        }

        partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
    }
}
