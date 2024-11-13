using Moq;
using Xunit;
using AutoMapper;
using Backend.DTOs.Beer;
using Backend.Models;
using Backend.Data.Repository;
using Backend.Services;
using FluentAssertions;
using System.ComponentModel.DataAnnotations.Schema;
using static System.Runtime.InteropServices.JavaScript.JSType;
using BeerShop.Data.Repository;
using System.Linq.Expressions;

namespace UnitTests
{
    public class BeerServiceTests
    {
        private Mock<IUnitOfWork> _unitOfWorkMock;
        private IMapper _mapper;
        private BeerService _beerService;

        public BeerServiceTests() 
        {
            _unitOfWorkMock = new Mock<IUnitOfWork>();

            var config = new MapperConfiguration(opt =>
            {
                opt.CreateMap<BeerInsertDTO, Beer>();
                opt.CreateMap<Beer, BeerDTO>()
                    .ForMember(dto => dto.Id,
                    m => m.MapFrom(b => b.BeerID));
                opt.CreateMap<BeerUpdateDTO, Beer>();
            });

            _mapper = config.CreateMapper();

            _beerService = new BeerService(_unitOfWorkMock.Object,_mapper);
        }

        [Fact]
        public async Task Get_ShouldReturnIEnumerableBeerDTO()
        {
            // Arrange
            var beers = new List<Beer>
            {
                new Beer { BeerID = 1, Name = "Test", Alcohol = 1, BrandID = 1 },
                new Beer { BeerID = 2, Name = "Test2", Alcohol = 3, BrandID = 1 }
            };

            _unitOfWorkMock.Setup(repo => repo.BeerRepository.Get(null,null,null)).ReturnsAsync(beers);

            // Act
            var result = await _beerService.Get();

            // Assert
            result.Should().NotBeNull();
            result.Should().AllBeOfType<BeerDTO>(); 
            result.Count().Should().Be(2);
            result.First().Name.Should().Be("Test");
        }

        [Fact]
        public async Task GetByID_ShouldReturnBeerDTO_WhenID()
        {
            //Arrange
            int id = 2;
            var beers = new List<Beer>
            {
                new Beer { BeerID = 1, Name = "Test", Alcohol = 1, BrandID = 1 },
                new Beer { BeerID = 2, Name = "Test2", Alcohol = 3, BrandID = 1 }
            };

            _unitOfWorkMock.Setup(repo => repo.BeerRepository.GetById(It.IsAny<int>()))
                .ReturnsAsync(beers.Find(b => b.BeerID == id));

            //Act 

            var result = await _beerService.GetByID(id);

            //Assert
            result.Should().NotBeNull();
            result.Name.Should().Be("Test2");
            result.Alcohol.Should().Be(3);
        }

        [Fact]
        public async Task Add_ShouldReturnBeerDTO_WhenAdded()
        {
            // Arrange
            var beerInsertDTO = new BeerInsertDTO()
            {
                Name = "Test",
                BrandID = 1,
                Alcohol = 2.5m
            };

            _unitOfWorkMock.Setup(repo => repo.BeerRepository.Add(It.IsAny<Beer>()))
                .Callback<Beer>(b => {
                    b.BeerID = 1;
                    b.Name = "Test";
                    b.BrandID = 1;
                    b.Alcohol = 2.5m;
                })
                .Returns(Task.CompletedTask);

            _unitOfWorkMock.Setup(repo => repo.Save()).Returns(Task.CompletedTask);

            //Act 
            var result = await _beerService.Add(beerInsertDTO);

            //Assert
            result.Should().NotBeNull();
            result.Name.Should().Be("Test");
            result.BrandID.Should().Be(1);
            result.Alcohol.Should().Be(2.5m);

        }

        [Fact]
        public async Task Update_ShouldReturnBeerDTO_WhenUpdateBeer()
        {
            // Arrange
            int id = 1;

            BeerUpdateDTO beerUpdateDTO = new BeerUpdateDTO()
            {
                Id = id,
                Name = "Test Deleted",
                BrandID = 1,
                Alcohol = 2.5m
            };

            var beers = new List<Beer>
            {
                new Beer { BeerID = 1, Name = "Test", Alcohol = 1, BrandID = 1 },
                new Beer { BeerID = 2, Name = "Test2", Alcohol = 3, BrandID = 1 }
            };

            _unitOfWorkMock.Setup(repo => repo.BeerRepository.GetById(It.IsAny<int>())).ReturnsAsync(beers.Find(b => b.BeerID == id));


            _unitOfWorkMock.Setup(repo => repo.BeerRepository.Update(It.IsAny<Beer>()))
                .Callback<Beer>(b => {
                    b.BeerID = id;  
                    b.Name = beerUpdateDTO.Name;
                    b.BrandID = beerUpdateDTO.BrandID;
                    b.Alcohol = beerUpdateDTO.Alcohol;
                });

            _unitOfWorkMock.Setup(repo => repo.Save()).Returns(Task.CompletedTask);

            // Act
            var result = await _beerService.Update(id, beerUpdateDTO);

            // Assert
            result.Should().NotBeNull();
            result.Name.Should().Be(beerUpdateDTO.Name);
            result.BrandID.Should().Be(beerUpdateDTO.BrandID);
            result.Alcohol.Should().Be(beerUpdateDTO.Alcohol);
        }

        [Fact]
        public async Task Delete_ShouldReturnBeerDTO_WhenDeleting()
        {
            // Arrange
            int id = 2;
            var beers = new List<Beer>
            {
                new Beer { BeerID = 1, Name = "Test", Alcohol = 1, BrandID = 1 },
                new Beer { BeerID = 2, Name = "Test2", Alcohol = 3, BrandID = 1 }
            };

            _unitOfWorkMock.Setup(repo => repo.BeerRepository.GetById(It.IsAny<int>())).ReturnsAsync(beers.Find(b => b.BeerID == id));

            _unitOfWorkMock.Setup(repo =>
            repo.BeerRepository.Delete(It.IsAny<Beer>()))
                .Callback<Beer>(b =>
                {
                    beers.Remove(b); 
                });

            _unitOfWorkMock.Setup(repo => repo.Save()).Returns(Task.CompletedTask);

            // Act
            var result = await _beerService.Delete(id);

            // Assert
            result.Should().NotBeNull();
            result.Name.Should().Be("Test2");
        }

        [Fact]
        public void ValidateBeerInsertDTO_ShouldReturnTrue_WhenNotError()
        {
            // Arrange
            BeerInsertDTO beerInsertDTO = new BeerInsertDTO()
            {
                Name = "Test Beer",  
                BrandID = 1,
                Alcohol = 2.5m
            };

            _unitOfWorkMock.Setup(repo => repo.BeerRepository.Search(It.IsAny<Expression<Func<Beer, bool>>>()))
                .Returns(new List<Beer>()); 

            // Act
            var result = _beerService.Validate(beerInsertDTO);

            // Assert
            result.Should().BeTrue(); 
        }

        [Fact]
        public void ValidateBeerUpdateDTO_ShouldReturnTrue_WhenNotError()
        {
            // Arrange
            BeerUpdateDTO beerUpdateDTO = new BeerUpdateDTO()
            {
                Name = "Test Beer",
                BrandID = 1,
                Alcohol = 2.5m
            };

            _unitOfWorkMock.Setup(repo => repo.BeerRepository.Search(It.IsAny<Expression<Func<Beer, bool>>>()))
                .Returns(new List<Beer>());

            // Act
            var result = _beerService.Validate(beerUpdateDTO);

            // Assert
            result.Should().BeTrue();
        }


    }
}
