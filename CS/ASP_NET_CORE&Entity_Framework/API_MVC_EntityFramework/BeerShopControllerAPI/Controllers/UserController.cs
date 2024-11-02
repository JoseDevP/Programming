using Backend.DTOs;
using Backend.Services;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;


namespace Backend.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class UserController : ControllerBase
    {
        IAuthService _authService;
        public UserController(IAuthService authService)
        {
            _authService = authService;
        }

        [HttpGet("validate")]
        [Authorize(Roles = "Admin")] 
        public IActionResult ValidateToken()
        {
            return Ok("ok");
        }

        [HttpPost("SignIn")]
        public async Task<ActionResult<UserDTO>> SignIn(UserLogingDTO userLogingDTO)
        {
            //Validaciones de campos (no campos nulos ni otras normas)
            //Validaciones db 
            var userDTO = await _authService.SignIn(userLogingDTO);
            return (userDTO != null) ? Ok(userDTO) : NotFound();
        }


        [HttpPost("SignUp")]
        public async Task<ActionResult<UserDTO>> SignUp(UserRegisterDTO userRegisterDTO)
        {
            //Validaciones de campos (no campos nulos ni otras normas)
            //Validaciones db 
            var userDTO = await _authService.SignUp(userRegisterDTO, "Guest");
            return (userDTO != null) ? Ok(userDTO) : BadRequest();
        }

        [HttpPost("SignUp/User")]
        [Authorize(Roles = "User,Admin")]
        public async Task<ActionResult<UserDTO>> SignUpUser(UserRegisterDTO userRegisterDTO)
        {
            //Validaciones de campos (no campos nulos ni otras normas)
            //Validaciones db 
            var userDTO = await _authService.SignUp(userRegisterDTO, "User");
            return (userDTO != null) ? Ok(userDTO) : BadRequest();
        }

        [HttpPost("SignUp/Admin")]
        [Authorize(Roles = "Admin")]
        public async Task<ActionResult<UserDTO>> SignUpAdmin(UserRegisterDTO userRegisterDTO)
        {
            //Validaciones de campos (no campos nulos ni otras normas)
            //Validaciones db 
            var userDTO = await _authService.SignUp(userRegisterDTO, "Admin");
            return (userDTO != null) ? Ok(userDTO) : BadRequest();
        }

    }
}
