﻿using System.ComponentModel.DataAnnotations;

namespace MoviesAPI.Models.DTOs
{
    public class UserLoggingDTO
    {
        [Required(ErrorMessage = "El usuario es obligatorio")]
        public string UserName { get; set; }
        [Required(ErrorMessage = "El password es obligatorio")]
        public string Password { get; set; }
    }
}
