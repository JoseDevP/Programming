using System;
using System.Collections.Generic;

namespace DB.Models
{
    public partial class Dog
    {
        public int Id { get; set; }
        public string Name { get; set; } = null!;
        public int BreedId { get; set; }

        public virtual Breed Breed { get; set; } = null!;
    }
}
