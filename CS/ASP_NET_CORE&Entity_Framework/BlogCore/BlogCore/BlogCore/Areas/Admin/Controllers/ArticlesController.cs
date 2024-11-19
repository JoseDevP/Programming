using BlogCore.DataAccess.Data.Repository.IRepository;
using BlogCore.Models.ViewModels;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore.Metadata.Internal;

namespace BlogCore.Areas.Admin.Controllers
{
    [Area("Admin")]
    public class ArticlesController : Controller
    {
        private readonly IUnitOfWork _unitOfWork;
        private readonly IWebHostEnvironment _webHostEnvironment;
        public ArticlesController(IUnitOfWork unitOfWork, IWebHostEnvironment webHostEnvironment)
        {
            _unitOfWork = unitOfWork;
            _webHostEnvironment = webHostEnvironment;
        }

        [HttpGet]
        public IActionResult Index()
        {
            return View();
        }

        [HttpGet]
        public IActionResult Create()
        {
            ArticleVM articleVM = new ArticleVM()
            {
                Article = new BlogCore.Models.Article(),
                CategoriesList = _unitOfWork.CategoryRepository.GetCategoryList()
            };
            return View(articleVM);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult Create(ArticleVM articleVM)
        {
            if(ModelState.IsValid)
            {
                string primaryRoute = _webHostEnvironment.WebRootPath;
                var files = HttpContext.Request.Form.Files;

                if(articleVM.Article.Id == 0 && files.Count > 0)
                {
                    //New Article
                    string fileName = Guid.NewGuid().ToString();
                    var uploads = Path.Combine(primaryRoute, @"images\articles");
                    var extension = Path.GetExtension(files[0].FileName);

                    using ( var fileStreams = new FileStream(Path.Combine(uploads,fileName + extension), FileMode.Create) )
                    {
                        files[0].CopyTo(fileStreams);
                    }

                    articleVM.Article.UrlImagen = @"\images\articles\" + fileName + extension;
                    articleVM.Article.CreationDate = DateTime.Now.ToString();

                    _unitOfWork.ArticleRepository.Add(articleVM.Article);
                    _unitOfWork.Save();

                    return RedirectToAction(nameof(Index));
                }
                else
                {
                    ModelState.AddModelError("Image","Debes seleccionar una imagen");
                }
            }

            articleVM.CategoriesList = _unitOfWork.CategoryRepository.GetCategoryList();

            return View(articleVM);
        }

        #region API Calls

        [HttpGet]
        public async Task<IActionResult> GetAll()
        {
            return Json(new { data = await _unitOfWork.ArticleRepository.GetAll(includeProperties: "Category") });
        }

        [HttpDelete]
        public async Task<IActionResult> Delete(int id)
        {
            var objFromDb = await _unitOfWork.ArticleRepository.GetById(id);
            if (objFromDb == null)
                return Json(new { success = false, message = "Error Borrando artículo" });

            _unitOfWork.ArticleRepository.Remove(objFromDb);
            await _unitOfWork.Save();
            return Json(new { success = true, message = "Articulo borrado correctamente" });

        }

        #endregion
    }
}
