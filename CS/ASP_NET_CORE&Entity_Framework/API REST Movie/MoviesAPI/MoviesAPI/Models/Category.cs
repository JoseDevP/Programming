using System.ComponentModel.DataAnnotations;

namespace MoviesAPI.Models
{
    public class Category
    {
        [Key]
        public int Id { get; set; }

        [Required]
        public string Name { get; set; }

        [Required]
        [Display(Name = "Fecha de Creación")]
        public DateTime CreationDate { get; set; }
    }
}
