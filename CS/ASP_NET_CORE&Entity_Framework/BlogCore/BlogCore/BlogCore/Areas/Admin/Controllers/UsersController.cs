using BlogCore.DataAccess.Data.Repository.IRepository;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using System.Security.Claims;

namespace BlogCore.Areas.Admin.Controllers
{
    [Authorize(Roles = "Administrador")]
    [Area("Admin")]
    public class UsersController : Controller
    {
        private readonly IUnitOfWork _unitOfWork;
        public UsersController(IUnitOfWork unitOfWork)
        {
            _unitOfWork = unitOfWork;
        }
        [HttpGet]
        public async Task<IActionResult> Index()
        {
            //option 1 obtain all users
            //return View(await _unitOfWork.UserRepository.GetAll());

            //option 2 obtain all but not who has logged
            var claimsIdentity = (ClaimsIdentity)this.User.Identity;
            var currentUser = claimsIdentity.FindFirst(ClaimTypes.NameIdentifier);
            return View(await _unitOfWork.UserRepository.GetAll(u => u.Id != currentUser.Value));
        }

        [HttpGet]
        public async Task<IActionResult> Block(string id)
        {
            if(id == null)
            {
                return NotFound();
            }
            
            await _unitOfWork.UserRepository.BlockUser(id);
            return RedirectToAction(nameof(Index));
        }

        [HttpGet]
        public async Task<IActionResult> UnBlock(string id)
        {
            if (id == null)
            {
                return NotFound();
            }

            await _unitOfWork.UserRepository.UnBlockUser(id);
            return RedirectToAction(nameof(Index));
        }
    }
}
