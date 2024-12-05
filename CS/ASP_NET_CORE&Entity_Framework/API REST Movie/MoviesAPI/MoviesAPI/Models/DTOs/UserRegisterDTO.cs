using System.ComponentModel.DataAnnotations;

namespace MoviesAPI.Models.DTOs
{
    public class UserRegisterDTO
    {
        [Required(ErrorMessage ="El usuario es obligatorio")]
        public string UserName { get; set; }
        [Required(ErrorMessage = "El nombre es obligatorio")]
        public string Name { get; set; }
        [Required(ErrorMessage = "El password es obligatorio")]
        public string Password { get; set; }
        public string Role { get; set; }

    }
}
