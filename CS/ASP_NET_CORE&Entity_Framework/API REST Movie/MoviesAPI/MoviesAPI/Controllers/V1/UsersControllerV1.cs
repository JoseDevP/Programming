using Asp.Versioning;
using AutoMapper;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using MoviesAPI.Models;
using MoviesAPI.Models.DTOs;
using MoviesAPI.Repository.IRepository;
using System.Net;

namespace MoviesAPI.Controllers.V1
{
    [ResponseCache(CacheProfileName = "Default")]
    [Route("api/v{version:apiVersion}/[controller]")]
    [ApiController]
    [ApiVersion("1.0")]
    public class UsersControllerV1 : ControllerBase
    {
        private readonly IUnitOfWork _unitOfWork;
        private readonly IMapper _mapper;
        protected ResponseAPI _responseAPI;

        public UsersControllerV1(IUnitOfWork unitOfWork, IMapper mapper)
        {
            _unitOfWork = unitOfWork;
            _mapper = mapper;
            _responseAPI = new ResponseAPI();
        }

        [HttpGet]
        [ProducesResponseType(StatusCodes.Status403Forbidden)]
        [ProducesResponseType(StatusCodes.Status200OK)]
        public async Task<IActionResult> GetUsers()
        {
            var usersList = await _unitOfWork.UserRepository.GetAllElements();

            var dtoUsersList = new List<UserDTO>();

            foreach (var user in usersList)
            {
                dtoUsersList.Add(_mapper.Map<UserDTO>(user));
            }

            return Ok(dtoUsersList);
        }

        [HttpGet("{userId:int}", Name = "GetUser")]
        [ProducesResponseType(StatusCodes.Status403Forbidden)]
        [ProducesResponseType(StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        [ProducesResponseType(StatusCodes.Status404NotFound)]
        public async Task<IActionResult> GetUser(int userId)
        {
            var userItem = await _unitOfWork.UserRepository.GetById(userId);

            if (userItem == null)
                return NotFound();

            var userItemDTO = _mapper.Map<UserDTO>(userItem);


            return Ok(userItemDTO);
        }

        [HttpPost("register")]
        [ProducesResponseType(StatusCodes.Status201Created)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        [ProducesResponseType(StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> RegisterUser([FromBody] UserRegisterDTO userRegisterDTO)
        {
            bool validateUserNameUnique = await _unitOfWork.UserRepository.IsUniqueUser(userRegisterDTO.UserName);
            if (!validateUserNameUnique)
            {
                _responseAPI.StatusCode = HttpStatusCode.BadRequest;

                _responseAPI.IsSuccess = false;

                _responseAPI.ErrorMessage.Add("El nombre de usuario ya existe");

                return BadRequest(_responseAPI);
            }

            var user = await _unitOfWork.UserRepository.Register(userRegisterDTO);

            if (user == null)

            {

                _responseAPI.StatusCode = HttpStatusCode.BadRequest;

                _responseAPI.IsSuccess = false;

                _responseAPI.ErrorMessage.Add("Error en el registro");

                return BadRequest(_responseAPI);

            }


            _responseAPI.StatusCode = HttpStatusCode.OK;

            _responseAPI.IsSuccess = true;

            return Ok(_responseAPI);
        }


        [HttpPost("login")]
        [ProducesResponseType(StatusCodes.Status201Created)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        [ProducesResponseType(StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> LoginUser([FromBody] UserLoggingDTO userLoggingDTO)
        {
            var loginResponse = await _unitOfWork.UserRepository.Login(userLoggingDTO);

            if (loginResponse == null || string.IsNullOrEmpty(loginResponse.Token))
            {
                _responseAPI.StatusCode = HttpStatusCode.BadRequest;

                _responseAPI.IsSuccess = false;

                _responseAPI.ErrorMessage.Add("El nombre de usuario o password son incorrectos");

                return BadRequest(_responseAPI);
            }

            _responseAPI.StatusCode = HttpStatusCode.OK;

            _responseAPI.IsSuccess = true;

            _responseAPI.Result = loginResponse;

            return Ok(_responseAPI);
        }
    }
}
