using BlogCore.Models;
using Microsoft.AspNetCore.Mvc;

namespace Web.Areas.Admin.Controllers
{
    [Area("Admin")]
    public class CategoriesController : Controller
    {
        [HttpGet]
        public IActionResult Index()
        {
            return View();
        }

        [HttpGet]
        public IActionResult Create()
        {
            return View(); 
        }

        [HttpGet]
        public async Task<IActionResult> Edit(int id)
        {
            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Create(Category category)
        {
            return RedirectToAction(nameof(Index));
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(Category category)
        {
            return RedirectToAction(nameof(Index));
        }

        #region API Calls

        [HttpGet]
        public async Task<IActionResult> GetAll()
        {
            var categorias = new List<Category>
            {
                new Category { Id = 1, Name = "Categoría 1", Order = 1 },
                new Category { Id = 2, Name = "Categoría 2", Order = 2 }
            };
            return Json(new { data = categorias });
        }

        [HttpDelete]
        public async Task<IActionResult> Delete(int id)
        {
            return Json(new { success = true, message = "Eliminado (simulado)" });
        }

        #endregion

    }
}
