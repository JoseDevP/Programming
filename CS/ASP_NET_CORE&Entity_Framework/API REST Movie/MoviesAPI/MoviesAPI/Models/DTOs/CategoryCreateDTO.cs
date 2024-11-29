using System.ComponentModel.DataAnnotations;

namespace MoviesAPI.Models.DTOs
{
    public class CategoryCreateDTO
    {
        [Required(ErrorMessage = "El nombre es obligatorio")]
        [MaxLength(100, ErrorMessage = "El máximo de caracteres es 100")]
        public string Name { get; set; }
    }
}
