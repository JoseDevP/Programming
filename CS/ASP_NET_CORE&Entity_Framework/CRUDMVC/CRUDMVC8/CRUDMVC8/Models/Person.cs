using System.ComponentModel.DataAnnotations;

namespace CRUDMVC8.Models
{
    public class Person
    {
        [Key]
        public int Id { get; set; }

        [Required(ErrorMessage = "El nombre no puede estar vacio")]
        public string Name { get; set; }

        [Required(ErrorMessage = "El teléfono no puede estar vacio")]
        public string Phone { get; set; }

        [Required(ErrorMessage = "El teléfono movil no puede estar vacio")]
        public string MobilePhone { get; set; }

        [Required(ErrorMessage = "El email no puede estar vacio")]
        public string Email { get; set; }

        public DateTime CreationDate { get; set; }

    }
}
