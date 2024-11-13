using AutoMapper;
using Backend.Configurations;
using Backend.Data.Repository;
using Moq;
using Xunit;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Backend.Services;
using Backend.DTOs;
using Microsoft.AspNetCore.Identity;
using System.Data;
using FluentAssertions;
using System.Security.Policy;
using Backend.DTOs.Beer;
using Backend.Models;
using BeerShop.Data.Repository;
using System.Linq.Expressions;

namespace UnitTests
{
    public class UserServiceTests
    {
        Mock<IUnitOfWork> _unitOfWorkMock;
        private IMapper _mapper;
        private Jwt _jwt;
        private AuthService _authService;

        public UserServiceTests()
        {
            _unitOfWorkMock = new Mock<IUnitOfWork>();

            var config = new MapperConfiguration(opt =>
            {
                opt.CreateMap<UserLogingDTO, User>()
                .ForMember(dest => dest.LastToken, opt => opt.MapFrom(src => "ninguno"));

                opt.CreateMap<User, UserDTO>();

                string Key = "mi_clave_super_secreta_muy_larga_que_tiene_que_tener_32_caracteres";
                string Issuer = "https://localhost:7200/";
                string Audience = "https://localhost:7200/";
                string Subject = "baseWebApiSubject";

                _jwt = new Jwt(Key,Issuer,Audience,Subject);
            }
            );

            _mapper = config.CreateMapper();

            _authService = new AuthService(_mapper, _jwt, _unitOfWorkMock.Object);

        }

        [Fact]
        public async Task Get_ShouldReturnIEnumerableUSERDTO_WhenGet()
        {
            _unitOfWorkMock.Setup(repo => repo.UserRepository.Get(null,null,null)).ReturnsAsync(new List<User>() {
                new User()
                {
                    IdUser = 1,
                    UserName = "Test",
                    PasswordHash = "ASDF",
                    PasswordSalt = "asdc",
                    Email =" kasld",
                    LastToken ="asdfsdf",
                    Role = "Admin"
                },
                new User()
                {
                    IdUser = 2,
                    UserName = "Test2",
                    PasswordHash = "asdf",
                    PasswordSalt = "dvfdxzvd",
                    Email =" kaasdasdassld",
                    LastToken ="as",
                    Role = "User"
                }});

            var result = await _authService.Get();

            result.Should().NotBeNull();
            result.Should().HaveCount(2);
        }

        [Fact]
        public async Task GetByID_ShouldReturnUSERDTO_WhenGettingbyid()
        {
            int id = 1;
            _unitOfWorkMock.Setup(repo => repo.UserRepository.GetById(It.IsAny<int>())).ReturnsAsync(

                new User()
                {
                    IdUser = 1,
                    UserName = "Test",
                    PasswordHash = "ASDF",
                    PasswordSalt = "asdc",
                    Email =" kasld",
                    LastToken ="asdfsdf",
                    Role = "Admin"
                });

            var result = await _authService.GetById(id);

            result.Should().NotBeNull();
            result.IdUser.Should().Be(id);
            result.UserName.Should().Be("Test");
            result.Role.Should().Be("Admin");
        }

        [Fact]
        public async Task SignIn_ShouldReturnUSERDTO_WhenSignIn()
        {
            IEnumerable<User> users = new List<User>()
            {
                new User()
                {
                    IdUser = 1,
                    UserName = "Test",
                    PasswordHash = "sfxvg",
                    PasswordSalt = "sdf",
                    Role = "User",
                    Email = "email",
                    LastToken = "dsfsdf"
                },
            };

            var userLogingDTO = new UserLogingDTO()
            {
                UserName = "Test",
                Password = "sfxvg",
            };

            _unitOfWorkMock.Setup(repo=> repo.UserRepository.Search(It.IsAny<Expression<Func<User, bool>>>()))
                .Returns(users);

            _unitOfWorkMock.Setup(repo => repo.Save());

            var result = await _authService.SignIn(userLogingDTO);

            result.Should().NotBeNull();
            result.UserName.Should().Be("Test");
            result.PasswordHash.Should().Be("sfxvg");
            result.PasswordSalt.Should().Be("sdf");
        }



        [Fact]
        public async Task SignUp_ShouldReturnUSERDTO_WhenSignUp()
        {
            string role = "User";
            var userRegisterDTO = new UserRegisterDTO()
            {
                UserName = "Test",
                Password = "sfxvg",
                Email = "mail"
            };

            _unitOfWorkMock.Setup(repo=> repo.UserRepository.Add(It.IsAny<User>()))
                .Returns(Task.CompletedTask);

            _unitOfWorkMock.Setup(repo => repo.Save());

            var result = await _authService.SignUp(userRegisterDTO, role);
            result.Should().NotBeNull();
            result.UserName.Should().Be("Test");

        }

        [Fact]
        public async Task CreatePasswordHash_ShouldReturnHASHANDSALT_WhenCreated()
        {
            string password = "Test";

            var (hash, salt) = _authService.CreatePasswordHash(password);

            hash.Should().NotBeNullOrWhiteSpace();
            salt.Should().NotBeNullOrWhiteSpace();
        }

        [Fact]
        public void VerifyPasswordHash_ShouldReturnTrue_WhenPasswordMatches()
        {
            string password = "Test";
            var (hash, salt) = _authService.CreatePasswordHash(password);

            bool result = _authService.VerifyPasswordHash(password, hash, salt);

            result.Should().BeTrue();
        }

        [Fact]
        public async Task FindUserByCredentials_ShouldReturnUSER_WhenFind()
        {
            string username = "Test";
            string password = "Test";

            var (hash, salt) = _authService.CreatePasswordHash(password);

            IEnumerable<User> users = new List<User>()
            {
                new User()
                {
                    IdUser = 1,
                    UserName = "Test",
                    PasswordHash = hash,
                    PasswordSalt = salt,
                    Role = "User",
                    Email = "email",
                    LastToken = "dsfsdf"
                },
            };

            _unitOfWorkMock.Setup(repo => repo.UserRepository.Search(It.IsAny<Expression<Func<User, bool>>>()))
                .Returns(users);

            var result = await _authService.FindUserByCredentials(username,password);

            result.Should().NotBeNull();
            result.IdUser.Should().Be(1);
            result.UserName.Should().Be(username);
            result.PasswordHash.Should().Be(hash);
            result.PasswordSalt.Should().Be(salt);
            result.Role.Should().Be("User");
            result.Email.Should().Be("email");
            result.LastToken.Should().Be("dsfsdf");
        }

        [Fact]
        public void GenerateToken_ShouldReturnString_WhenCreatingToken() 
        {
            User user = new User()
            {
                IdUser = 1,
                UserName = "Test",
                PasswordHash = "dsf",
                PasswordSalt = "saaaaddvvryu",
                Role = "User",
                Email = "email",
                LastToken = "dsfsdf"
            };

            var result = _authService.GenerateToken(user);

            result.Should().NotBeNull();
            result.Should().BeOfType<String>();
        }


        [Fact]
        public void ValidateUserRegisterDTO_ShouldReturnTrue_WhenNotError()
        {
            UserRegisterDTO userRegisterDTO = new UserRegisterDTO()
            {
                UserName = "Test Beer",
                Password = "password",
                Email = "email"
            };

            _unitOfWorkMock.Setup(repo => repo.UserRepository.Search(It.IsAny<Expression<Func<User, bool>>>()))
                .Returns(new List<User>());

            var result = _authService.validate(userRegisterDTO);

            result.Should().BeTrue();
        }

        [Fact]
        public void ValidateUserLogingDTO_ShouldReturnTrue_WhenNotError()
        {

            UserLogingDTO userLogingDTO = new UserLogingDTO()
            {
                UserName = "Test Beer",
                Password = "password"
            };

            var (hash, salt) = _authService.CreatePasswordHash("password");

            IEnumerable<User> user = new List<User>()
            {
                new User()
                {
                    IdUser = 1,
                    UserName = "Test Beer",
                    PasswordHash = hash,
                    PasswordSalt = salt,
                    Role = "User",
                    Email = "email",
                    LastToken = "dsfsdf"
                }
            };

            
            _unitOfWorkMock.Setup(repo => repo.UserRepository.Search(It.IsAny<Expression<Func<User, bool>>>()))
                .Returns(user);

            var result = _authService.validate(userLogingDTO);

            result.Should().BeTrue();
        }

        [Fact]
        public async Task DeleteUser_ShouldReturnUserDTO_WhenId()
        {
            int id = 1;
            _unitOfWorkMock.Setup(repo => repo.UserRepository.GetById(It.IsAny<int>())).ReturnsAsync(

                new User()
                {
                    IdUser = 1,
                    UserName = "Test",
                    PasswordHash = "ASDF",
                    PasswordSalt = "asdc",
                    Email = " kasld",
                    LastToken = "asdfsdf",
                    Role = "Admin"
                });

            _unitOfWorkMock.Setup(repo => repo.UserRepository.Delete(It.IsAny<User>()));

            var result = await _authService.DeleteUser(id);

            result.Should().NotBeNull();
            result.IdUser.Should().Be(id);
            result.UserName.Should().Be("Test");
            result.Role.Should().Be("Admin");
        }
    }
}
