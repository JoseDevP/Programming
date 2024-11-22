using BlogCore.DataAccess.Data.Repository.IRepository;
using BlogCore.Models;
using BlogCore.Models.ViewModels;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore.Metadata.Internal;

namespace BlogCore.Areas.Admin.Controllers
{
    [Area("Admin")]
    public class SlidersController : Controller
    {
        private readonly IUnitOfWork _unitOfWork;
        private readonly IWebHostEnvironment _webHostEnvironment;
        public SlidersController(IUnitOfWork unitOfWork, IWebHostEnvironment webHostEnvironment)
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
            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public IActionResult Create(Slider slider)
        {
            if(ModelState.IsValid)
            {
                string primaryRoute = _webHostEnvironment.WebRootPath;
                var files = HttpContext.Request.Form.Files;

                if(files.Count > 0)
                {
                    //New Article
                    string fileName = Guid.NewGuid().ToString();
                    var uploads = Path.Combine(primaryRoute, @"images\sliders");
                    var extension = Path.GetExtension(files[0].FileName);

                    using ( var fileStreams = new FileStream(Path.Combine(uploads,fileName + extension), FileMode.Create) )
                    {
                        files[0].CopyTo(fileStreams);
                    }

                    slider.UrlImage = @"\images\sliders\" + fileName + extension;

                    _unitOfWork.SliderRepository.Add(slider);
                    _unitOfWork.Save();

                    return RedirectToAction(nameof(Index));
                }
                else
                {
                    ModelState.AddModelError("Image","Debes seleccionar una imagen");
                }
            }

            return View(slider);
        }

        [HttpGet]
        public async Task<IActionResult> Edit(int? id)
        {   
            if(id != null)
            {
                var slider = await _unitOfWork.SliderRepository.GetById(id.GetValueOrDefault());
                return View(slider);

            }

            return View();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(Slider slider)
        {
            if (ModelState.IsValid)
            {
                string primaryRoute = _webHostEnvironment.WebRootPath;
                var files = HttpContext.Request.Form.Files;

                var sliderFromDb = await _unitOfWork.SliderRepository.GetById(slider.Id);

                if (files.Count > 0)
                {
                    //New image slider
                    string fileName = Guid.NewGuid().ToString();
                    var uploads = Path.Combine(primaryRoute, @"images\sliders");
                    var extension = Path.GetExtension(files[0].FileName);

                    //var newExtension = Path.GetExtension(files[0].FileName);

                    var imageRoute = Path.Combine(primaryRoute, sliderFromDb.UrlImage.TrimStart('\\'));

                    if(System.IO.File.Exists(imageRoute))
                    {
                        System.IO.File.Delete(imageRoute);
                    }

                    using (var fileStreams = new FileStream(Path.Combine(uploads, fileName + extension), FileMode.Create))
                    {
                        files[0].CopyTo(fileStreams);
                    }

                    slider.UrlImage = @"\images\sliders\" + fileName + extension;

                    await _unitOfWork.SliderRepository.Update(slider);
                    await _unitOfWork.Save();

                    return RedirectToAction(nameof(Index));
                }
                else//image exists
                {
                    slider.UrlImage = sliderFromDb.UrlImage;
                }

                await _unitOfWork.SliderRepository.Update(slider);
                await _unitOfWork.Save();

                return RedirectToAction(nameof(Index));
            }

            return View(slider);
        }



        #region API Calls

        [HttpGet]
        public async Task<IActionResult> GetAll()
        {
            return Json(new { data = await _unitOfWork.SliderRepository.GetAll() });
        }

        [HttpDelete]
        public async Task<IActionResult> Delete(int id)
        {
            var sliderFromDb = await _unitOfWork.SliderRepository.GetById(id);

            var primaryRoute = _webHostEnvironment.WebRootPath;
            var imageRoute = Path.Combine(primaryRoute, sliderFromDb.UrlImage.TrimStart('\\'));

            if (System.IO.File.Exists(imageRoute))
            {
                System.IO.File.Delete(imageRoute);
            }

            if (sliderFromDb == null)
                return Json(new { success = false, message = "Error Borrando artículo" });

            _unitOfWork.SliderRepository.Remove(sliderFromDb);
            await _unitOfWork.Save();
            return Json(new { success = true, message = "Artículo borrado correctamente" });

        }

        #endregion
    }
}
