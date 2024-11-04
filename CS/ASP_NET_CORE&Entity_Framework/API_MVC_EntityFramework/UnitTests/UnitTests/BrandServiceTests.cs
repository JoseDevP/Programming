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
using Backend.DTOs.Brand;
using System.Drawing.Drawing2D;

namespace UnitTests
{
    public class BrandServiceTests
    {
        private Mock<IRepository<Brand>> _repositoryMock;
        private IMapper _mappingProfile;
        private BrandService _brandService;
        
        public BrandServiceTests()
        {
            _repositoryMock = new Mock<IRepository<Brand>>();

            var config = new MapperConfiguration(opt =>           
            {
                opt.CreateMap<BrandInsertDTO, Brand>();
                opt.CreateMap<Brand, BrandDTO>()
                    .ForMember(dto => dto.Id,
                    m => m.MapFrom(b => b.BrandID));
                opt.CreateMap<BrandUpdateDTO, Brand>();
            });

            _mappingProfile = config.CreateMapper();

            _brandService = new BrandService(_repositoryMock.Object,_mappingProfile);
        }

        [Fact]
        public async Task Get_ShouldReturnAllEnumerable()
        {
            Brand[] brands = new Brand[]
            {
                new Brand
                {
                    BrandID = 1,
                    Name = "Test"
                },
                new Brand
                {
                    BrandID = 2,
                    Name = "Test2"
                },
            };
            _repositoryMock.Setup(repo => repo.Get()).ReturnsAsync(brands);

            var result = await _brandService.Get();

            result.Should().NotBeNull();
            result.Should().AllBeOfType<BrandDTO>();
            result.Should().HaveCount(2);
        }

        [Fact]
        public async Task GetByID_ShouldReturnBrandDTO_WhenID()
        {
            var brand = new Brand()
            {
                BrandID = 1,
                Name = "Test",
            };

            _repositoryMock.Setup(repo => repo.GetById(It.IsAny<int>()))
                .ReturnsAsync(brand);

            var result = await _brandService.GetByID(1);

            result.Should().NotBeNull();
            result.Should().BeOfType<BrandDTO>();
        }

        [Fact]
        public async Task Add_ShouldReturnBrandDTO_WhenAdding()
        {
            var brand = new Brand()
            {
                BrandID = 1,
                Name = "Test",
            };

            var brandInsertDTO = new BrandInsertDTO
            {
                Name = "Test",
            };

            _repositoryMock.Setup(repo => repo.Add(It.IsAny<Brand>()));

            _repositoryMock.Setup(repo => repo.Save());

            var result = await _brandService.Add(brandInsertDTO);

            result.Should().NotBeNull();
            result.Should().BeOfType<BrandDTO>();
        }

        [Fact]
        public async Task Update_ShouldReturnBrandDTO_WhenUpdating()
        {
            var brand = new Brand()
            {
                BrandID = 1,
                Name = "Test",
            };

            var brandUpdateDTO = new BrandUpdateDTO()
            {
                Id = 1,
                Name = "Test",
            };

            _repositoryMock.Setup(repo => repo.GetById(It.IsAny<int>()))
                .ReturnsAsync(brand);

            _repositoryMock.Setup(repo => repo.Update(It.IsAny<Brand>()))
                .Callback<Brand>(b =>
                {
                    b.Name = b.Name;
                    b.BrandID = b.BrandID;
                });

            _repositoryMock.Setup(repo => repo.Save());

            var result = await _brandService.Update(1, brandUpdateDTO);
            result.Should().NotBeNull();
            result.Should().BeOfType<BrandDTO>();
        }


        [Fact]
        public async Task Delete_ShouldReturnBrandDTO_WhenDeleting()
        {
            var brand = new Brand()
            {
                BrandID = 1,
                Name = "Test",
            };

            _repositoryMock.Setup(repo => repo.GetById(It.IsAny<int>()))
                .ReturnsAsync(brand);

            _repositoryMock.Setup(repo => repo.Delete(It.IsAny<Brand>()));

            _repositoryMock.Setup(repo => repo.Save());

            var result = await _brandService.Delete(1);

            result.Should().NotBeNull();
            result.Should().BeOfType<BrandDTO>();
        }

        [Fact]
        public async void ValidateBrandInsertDTO_ShouldReturnTrue_WhenNotError()
        {
            BrandInsertDTO brandInsertDTO = new BrandInsertDTO()
            {
                Name = "Test"
            };

            _repositoryMock.Setup(repo => repo.Search(It.IsAny<Func<Brand, bool>>()))
                .Returns(new List<Brand>());

            var result =  _brandService.Validate(brandInsertDTO);
        }

        [Fact]
        public void ValidateBrandUpdateDTO_ShouldReturnTrue_WhenNotError()
        {
            BrandUpdateDTO brandUpdateDTO = new BrandUpdateDTO()
            {
                Name = "Test"
            };

            _repositoryMock.Setup(repo => repo.Search(It.IsAny<Func<Brand, bool>>()))
                .Returns(new List<Brand>());

            var result = _brandService.Validate(brandUpdateDTO);
        }
    }
}
