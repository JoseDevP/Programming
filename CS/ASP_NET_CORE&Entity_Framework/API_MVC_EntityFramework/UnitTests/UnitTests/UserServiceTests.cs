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

namespace UnitTests
{
    public class UserServiceTests
    {
        Mock<IRepository<User>> _userRepositoryMock;
        private IMapper _mapper;
        private Jwt _jwt;
        private AuthService _authService;

        public UserServiceTests()
        {
            _userRepositoryMock = new Mock<IRepository<User>>();

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

            _authService = new AuthService(_mapper, _jwt, _userRepositoryMock.Object);

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

            _userRepositoryMock.Setup(repo=> repo.Search(It.IsAny<Func<User, bool>>()))
                .Returns(users);

            _userRepositoryMock.Setup(repo => repo.Save());

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

            _userRepositoryMock.Setup(repo=> repo.Add(It.IsAny<User>()))
                .Returns(Task.CompletedTask);

            _userRepositoryMock.Setup(repo => repo.Save());

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

            _userRepositoryMock.Setup(repo => repo.Search(It.IsAny<Func<User, bool>>()))
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

            _userRepositoryMock.Setup(repo => repo.Search(It.IsAny<Func<User, bool>>()))
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

            
            _userRepositoryMock.Setup(repo => repo.Search(It.IsAny<Func<User, bool>>()))
                .Returns(user);

            var result = _authService.validate(userLogingDTO);

            result.Should().BeTrue();
        }
    }
}
