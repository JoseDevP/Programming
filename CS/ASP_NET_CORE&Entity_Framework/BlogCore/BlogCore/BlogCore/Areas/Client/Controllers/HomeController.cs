using BlogCore.DataAccess.Data.Repository.IRepository;
using BlogCore.Models;
using BlogCore.Models.ViewModels;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;
using System.Drawing.Printing;

namespace BlogCore.Areas.Client.Controllers
{
    [Area("Client")]
    public class HomeController : Controller
    {

        private readonly IUnitOfWork _unitOfWork;

        public HomeController(IUnitOfWork unitOfWork)
        {
            _unitOfWork = unitOfWork;
        }

        //First version InitialPage without pagination
        //[HttpGet]
        //public async Task<IActionResult> Index()
        //{
        //    HomeVM homeVM = new HomeVM()
        //    {
        //        Sliders = await _unitOfWork.SliderRepository.GetAll(),
        //        ArticleList = await _unitOfWork.ArticleRepository.GetAll(),
        //    };

        //    ViewBag.IsHome = true;

        //    return View(homeVM);
        //}

        [HttpGet]
        public async Task<IActionResult> Index(int page = 1, int pageSize = 6)
        {
            var articles = _unitOfWork.ArticleRepository.AsQueryable();
            var paginatedEntries = articles.Skip((page - 1) * pageSize).Take(pageSize);

            HomeVM homeVM = new HomeVM()
            {
                Sliders = await _unitOfWork.SliderRepository.GetAll(),
                ArticleList = paginatedEntries.ToList(),
                PageIndex = page,
                TotalPages = (int)Math.Ceiling(articles.Count() / (double)pageSize)
            };

            ViewBag.IsHome = true;

            return View(homeVM);
        }

        //search
        [HttpGet]
        public IActionResult SearchResult(string searchString, int page = 1, int pageSize = 3)
        {
            var articles = _unitOfWork.ArticleRepository.AsQueryable();

            if(!string.IsNullOrEmpty(searchString))
            {
                articles = articles.Where(e=> e.Name.Contains(searchString));
            }

            var paginatedEntries = articles.Skip((page - 1) * pageSize).Take(pageSize);

            var model = new PaginatedList<Article>(paginatedEntries.ToList(), articles.Count(), page, pageSize, searchString);
            return View(model);
        }

        [HttpGet]
        public async Task<IActionResult> Detail(int id)
        {
            var articleFromDb = await _unitOfWork.ArticleRepository.GetById(id);
            return View(articleFromDb);
        }

        public IActionResult Privacy()
        {
            return View();
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}
