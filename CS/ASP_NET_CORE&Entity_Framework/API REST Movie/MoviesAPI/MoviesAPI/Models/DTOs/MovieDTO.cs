using System.ComponentModel.DataAnnotations.Schema;
using static MoviesAPI.Models.ENUMS.Enums;

namespace MoviesAPI.Models.DTOs
{
    public class MovieDTO
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Description { get; set; }
        public int Duration { get; set; }
        public ClasificationType clasification { get; set; }
        public DateTime CreationDate { get; set; }
        public string ImageRoute { get; set; }
        public int CategoryId { get; set; }
    }
}
