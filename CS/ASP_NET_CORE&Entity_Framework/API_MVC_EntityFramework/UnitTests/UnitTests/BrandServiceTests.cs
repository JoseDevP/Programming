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
using BeerShop.Data.Repository;
using System.Linq.Expressions;

namespace UnitTests
{
    public class BrandServiceTests
    {
        private Mock<IUnitOfWork> _unitOfWorkMock;
        private IMapper _mappingProfile;
        private BrandService _brandService;
        
        public BrandServiceTests()
        {
            _unitOfWorkMock = new Mock<IUnitOfWork>();

            var config = new MapperConfiguration(opt =>           
            {
                opt.CreateMap<BrandInsertDTO, Brand>();
                opt.CreateMap<Brand, BrandDTO>()
                    .ForMember(dto => dto.Id,
                    m => m.MapFrom(b => b.BrandID));
                opt.CreateMap<BrandUpdateDTO, Brand>();
            });

            _mappingProfile = config.CreateMapper();

            _brandService = new BrandService(_unitOfWorkMock.Object,_mappingProfile);
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
            _unitOfWorkMock.Setup(repo => repo.BrandRepository.Get(null,null,null)).ReturnsAsync(brands);

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

            _unitOfWorkMock.Setup(repo => repo.BrandRepository.GetById(It.IsAny<int>()))
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

            _unitOfWorkMock.Setup(repo => repo.BrandRepository.Add(It.IsAny<Brand>()));

            _unitOfWorkMock.Setup(repo => repo.Save());

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

            _unitOfWorkMock.Setup(repo => repo.BrandRepository.GetById(It.IsAny<int>()))
                .ReturnsAsync(brand);

            _unitOfWorkMock.Setup(repo => repo.BrandRepository.Update(It.IsAny<Brand>()))
                .Callback<Brand>(b =>
                {
                    b.Name = b.Name;
                    b.BrandID = b.BrandID;
                });

            _unitOfWorkMock.Setup(repo => repo.Save());

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

            _unitOfWorkMock.Setup(repo => repo.BrandRepository.GetById(It.IsAny<int>()))
                .ReturnsAsync(brand);

            _unitOfWorkMock.Setup(repo => repo.BrandRepository.Delete(It.IsAny<Brand>()));

            _unitOfWorkMock.Setup(repo => repo.Save());

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

            _unitOfWorkMock.Setup(repo => repo.BrandRepository.Search(It.IsAny<Expression<Func<Brand, bool>>>()))
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

            _unitOfWorkMock.Setup(repo => repo.BrandRepository.Search(It.IsAny<Expression<Func<Brand, bool>>>()))
                .Returns(new List<Brand>());

            var result = _brandService.Validate(brandUpdateDTO);
        }
    }
}
