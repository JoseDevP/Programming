using System;
using System.Collections.Generic;

namespace DB.Models
{
    public partial class Breed
    {
        public Breed()
        {
            Dogs = new HashSet<Dog>();
        }

        public int Id { get; set; }
        public string Name { get; set; } = null!;

        public virtual ICollection<Dog> Dogs { get; set; }
    }
}
