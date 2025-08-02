using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Core.Models
{
    public class Article
    {
        [Key]
        public int Id { get; set; }
        [Required(ErrorMessage ="El nombre es obligatorio")]
        [Display(Name = "Nombre del Articulo")]
        public string Name { get; set; }

        [Required(ErrorMessage = "La descripción es obligatorio")]
        public string Description { get; set; }

        [Display(Name = "Fecha de creación")]
        public string? CreationDate { get; set; }

        [DataType(DataType.ImageUrl)]
        [Display(Name = "Imagen")]
        public string? UrlImagen { get; set; }

        [Required(ErrorMessage = "La categoria es obligatoria")]
        public int IdCategory { get; set; }

        [ForeignKey("IdCategory")]
        public Category? Category { get; set; }
    }
}
