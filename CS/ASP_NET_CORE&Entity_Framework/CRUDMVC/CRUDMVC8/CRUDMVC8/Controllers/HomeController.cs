using CRUDMVC8.Data;
using CRUDMVC8.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using System.Diagnostics;

namespace CRUDMVC8.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;
        private CRUDMVC8Db _context;

        public HomeController(ILogger<HomeController> logger, CRUDMVC8Db context)
        {
            _logger = logger;
            _context = context;
        }

        public async Task<IActionResult> Index()
        {
            var persons = await _context._persons.ToListAsync();
            return View(persons);
        }

        public IActionResult Privacy()
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
        public async Task<IActionResult> Create(Person person)
        {
            if (ModelState.IsValid)
            {
                person.CreationDate = DateTime.UtcNow;
                await _context._persons.AddAsync(person);
                await _context.SaveChangesAsync();
                
                return RedirectToAction(nameof(Index));
            }

            return View(person);
        }

        [HttpGet]
        public async Task<IActionResult> Edit(int id)
        {
            var person = await _context._persons.FindAsync(id);
            if (person != null)
            {
                return View(person);
            }
            return NotFound();
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public async Task<IActionResult> Edit(Person person)
        {
            if (ModelState.IsValid)
            {
                _context._persons.Update(person);
                await _context.SaveChangesAsync();

                return RedirectToAction(nameof(Index));
            }

            return View(person);
        }

        [HttpGet]
        public async Task<IActionResult> Detail(int id)
        {
            var person = await _context._persons.FindAsync(id);
            if (person != null)
            {
                return View(person);
            }
            return NotFound();
        }

        [HttpGet]
        public async Task<IActionResult> Delete(int id)
        {
            var person = await _context._persons.FindAsync(id);
            if (person != null)
            {
                return View(person);
            }
            return NotFound();
        }

        [HttpPost, ActionName("Delete")]
        public async Task<IActionResult> DeleteComplete(int id)
        {
            var person = await _context._persons.FindAsync(id);
            if (person == null)
            {
                return View();
            }

            _context._persons.Remove(person);
            await _context.SaveChangesAsync();
            return RedirectToAction(nameof(Index));
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }
    }
}
