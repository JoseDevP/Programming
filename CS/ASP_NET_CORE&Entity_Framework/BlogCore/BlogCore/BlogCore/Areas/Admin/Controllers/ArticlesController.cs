using BlogCore.DataAccess.Data.Repository.IRepository;
using BlogCore.Models.ViewModels;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore.Metadata.Internal;

namespace BlogCore.Areas.Admin.Controllers
{
    [Authorize(Roles = "Administrador")]
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

        [HttpGet]
        public async Task<IActionResult> Edit(int? id)
        {
            ArticleVM articleVM = new ArticleVM()
            {
                Article = new BlogCore.Models.Article(),
                CategoriesList = _unitOfWork.CategoryRepository.GetCategoryList()
            };
            
            if(id != null)
            {
                articleVM.Article = await _unitOfWork.ArticleRepository.GetById(id.GetValueOrDefault());
            }

            return View(articleVM);
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(ArticleVM articleVM)
        {
            if (ModelState.IsValid)
            {
                string primaryRoute = _webHostEnvironment.WebRootPath;
                var files = HttpContext.Request.Form.Files;

                var articleFromDB = await _unitOfWork.ArticleRepository.GetById(articleVM.Article.Id);

                //New image for the article
                if (files.Count > 0)
                {
                    string fileName = Guid.NewGuid().ToString();
                    var uploads = Path.Combine(primaryRoute, @"images\articles");
                    var extension = Path.GetExtension(files[0].FileName);
                    var newExtension = Path.GetExtension(files[0].FileName);

                    var imageRoute = Path.Combine(primaryRoute, articleFromDB.UrlImagen.TrimStart('\\'));

                    if (System.IO.File.Exists(imageRoute))
                    {
                        System.IO.File.Delete(imageRoute);
                    }

                    //upload new file
                    using (var fileStreams = new FileStream(Path.Combine(uploads, fileName + extension), FileMode.Create))
                    {
                        files[0].CopyTo(fileStreams);
                    }

                    articleVM.Article.UrlImagen = @"\images\articles\" + fileName + extension;
                    articleVM.Article.CreationDate = DateTime.Now.ToString();

                    
                }
                else //Didn't change the image
                {
                    articleVM.Article.UrlImagen = articleFromDB.UrlImagen;
                }

                await _unitOfWork.ArticleRepository.Update(articleVM.Article);
                await _unitOfWork.Save();

                return RedirectToAction(nameof(Index));
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
            var articleFromDb = await _unitOfWork.ArticleRepository.GetById(id);

            var primaryRoute = _webHostEnvironment.WebRootPath;
            var imageRoute = Path.Combine(primaryRoute, articleFromDb.UrlImagen.TrimStart('\\'));

            if (System.IO.File.Exists(imageRoute))
            {
                System.IO.File.Delete(imageRoute);
            }

            if (articleFromDb == null)
                return Json(new { success = false, message = "Error Borrando artículo" });

            _unitOfWork.ArticleRepository.Remove(articleFromDb);
            await _unitOfWork.Save();
            return Json(new { success = true, message = "Artículo borrado correctamente" });

        }

        #endregion
    }
}
