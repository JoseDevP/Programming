using System.ComponentModel.DataAnnotations.Schema;
using static MoviesAPI.Models.ENUMS.Enums;

namespace MoviesAPI.Models.DTOs
{
    public class MovieCreateDTO
    {
        public string Name { get; set; }
        public string Description { get; set; }
        public int Duration { get; set; }
        public ClasificationType clasification { get; set; }
        public string ImageRoute { get; set; }
        public int CategoryId { get; set; }
    }
}
