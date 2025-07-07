using BlogCore.Models;
using System.Web.Mvc;

namespace Core.ViewModels
{
    public class ArticleVM
    {
        public Article Article { get; set; }

        public IEnumerable<SelectListItem>? CategoriesList { get; set; }
    }
}
