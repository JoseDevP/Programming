using BeerShop.Aplication.DTOs;
using BeerShop.Core.Interfaces;
using FluentValidation;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;


namespace BeerShop.API.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class UserController : ControllerBase
    {
        IAuthService _authService;
        IValidator<UserLogingDTO> _validatorLoging;
        IValidator<UserRegisterDTO> _validatorRegister;
        public UserController(IAuthService authService,
            IValidator<UserLogingDTO> validatorLoging,
        IValidator<UserRegisterDTO> validatorRegister
            )
        {
            _authService = authService;
            _validatorLoging = validatorLoging;
            _validatorRegister = validatorRegister;
        }

        [HttpGet]
        [Authorize(Roles = "Admin")]
        public async Task<IEnumerable<UserDTO>> Get() => await _authService.Get();

        [HttpGet("{id}")]
        [Authorize(Roles = "Admin")]
        public async Task<ActionResult<UserDTO>> GetByID(int id) => await _authService.GetById(id) is UserDTO user ? Ok(user) : NotFound();


        [HttpPost("SignIn")]
        public async Task<ActionResult<UserDTO>> SignIn(UserLogingDTO userLogingDTO)
        {
            var validations = _validatorLoging.Validate(userLogingDTO);
            if (!validations.IsValid)
            {
                return BadRequest(validations.Errors);
            }

            if (!_authService.validate(userLogingDTO))
            {
                return BadRequest(_authService.Errors);
            }

            var userDTO = await _authService.SignIn(userLogingDTO);
            return userDTO != null ? Ok(userDTO) : NotFound();
        }


        [HttpPost("SignUp")]
        public async Task<ActionResult<UserDTO>> SignUp(UserRegisterDTO userRegisterDTO)
        {
            var validations = _validatorRegister.Validate(userRegisterDTO);
            if (!validations.IsValid)
            {
                return BadRequest(validations.Errors);
            }

            if (!_authService.validate(userRegisterDTO))
            {
                return BadRequest(_authService.Errors);
            }

            var userDTO = await _authService.SignUp(userRegisterDTO, "Guest");
            return userDTO != null ? Ok(userDTO) : BadRequest();
        }

        [HttpPost("SignUp/User")]
        [Authorize(Roles = "User,Admin")]
        public async Task<ActionResult<UserDTO>> SignUpUser(UserRegisterDTO userRegisterDTO)
        {
            var validations = _validatorRegister.Validate(userRegisterDTO);
            if (!validations.IsValid)
            {
                return BadRequest(validations.Errors);
            }

            if (!_authService.validate(userRegisterDTO))
            {
                return BadRequest(_authService.Errors);
            }

            var userDTO = await _authService.SignUp(userRegisterDTO, "User");
            return userDTO != null ? Ok(userDTO) : BadRequest();
        }

        [HttpPost("SignUp/Admin")]
        [Authorize(Roles = "Admin")]
        public async Task<ActionResult<UserDTO>> SignUpAdmin(UserRegisterDTO userRegisterDTO)
        {
            var validations = _validatorRegister.Validate(userRegisterDTO);
            if (!validations.IsValid)
            {
                return BadRequest(validations.Errors);
            }

            if (!_authService.validate(userRegisterDTO))
            {
                return BadRequest(_authService.Errors);
            }

            var userDTO = await _authService.SignUp(userRegisterDTO, "Admin");
            return userDTO != null ? Ok(userDTO) : BadRequest();
        }

        [HttpDelete("{id}")]
        [Authorize(Roles = "Admin")]
        public async Task<ActionResult<UserDTO>> DeleteUser(int id) => await _authService.DeleteUser(id) is UserDTO userDto ? Ok(userDto) : NotFound();
    }
}
