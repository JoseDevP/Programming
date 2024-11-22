using Microsoft.AspNetCore.Identity;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BlogCore.Models
{
    public class ApplicationUser : IdentityUser
    {
        [Required(ErrorMessage = "El nombre es obligatorio")]
        public string Name { get; set; }

        [Required(ErrorMessage = "La dirección es obligatoria")]
        public string Adress { get; set; }

        [Required(ErrorMessage = "La ciudad es obligatoria")]
        public string City { get; set; }

        [Required(ErrorMessage = "El país es obligatorio")]
        public string Country { get; set; }
    }
}
