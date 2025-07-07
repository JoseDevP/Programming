using BlogCore.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Core.ViewModels
{
    public class HomeVM
    {
        public IEnumerable<Slider> Sliders { get; set; }
        public IEnumerable<Article> ArticleList { get; set; }
        
        //pagination 
        public int PageIndex { get; set; }
        public int TotalPages { get; set; }
    }
}
