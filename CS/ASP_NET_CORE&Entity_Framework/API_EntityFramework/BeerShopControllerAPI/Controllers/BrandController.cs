using Core.DTOs.Brand;
using Core.Interfaces;
using FluentValidation;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace BeerShop.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class BrandController : ControllerBase
    {
        ICommonService<BrandDTO, BrandInsertDTO, BrandUpdateDTO> _brandService;
        IValidator<BrandInsertDTO> _brandInsertValidator;
        IValidator<BrandUpdateDTO> _brandUpdateValidator;

        public BrandController([FromKeyedServices("brandService")] ICommonService<BrandDTO, BrandInsertDTO, BrandUpdateDTO> brandService,
            IValidator<BrandInsertDTO> brandInsertValidator,
            IValidator<BrandUpdateDTO> brandUpdateValidator)
        {
            _brandService = brandService;
            _brandInsertValidator = brandInsertValidator;
            _brandUpdateValidator = brandUpdateValidator;
        }

        [HttpGet]
        public async Task<IEnumerable<BrandDTO>> Get() => await _brandService.Get();

        [HttpGet("{id}")]
        public async Task<ActionResult<BrandDTO>> GetById(int id) => await _brandService.GetByID(id) is BrandDTO brandDTO ? Ok(brandDTO) : NotFound();

        [HttpPost]
        [Authorize(Roles = "User,Admin")]
        public async Task<ActionResult<BrandDTO>> Add(BrandInsertDTO brandInsertDTO)
        {
            var validation = await _brandInsertValidator.ValidateAsync(brandInsertDTO);

            if (!validation.IsValid)
                return BadRequest(validation.Errors);

            if (!_brandService.Validate(brandInsertDTO))
                return BadRequest(_brandService.Errors);

            var brandDTO = await _brandService.Add(brandInsertDTO);

            return CreatedAtAction(nameof(GetById), new { id = brandDTO.Id }, brandDTO);
        }

        [HttpPut("{id}")]
        [Authorize(Roles = "User,Admin")]
        public async Task<ActionResult<BrandDTO>> Edit(int id, BrandUpdateDTO brandUpdateDTO)
        {
            var validation = await _brandUpdateValidator.ValidateAsync(brandUpdateDTO);
            if (!validation.IsValid)
                return BadRequest(validation.Errors);

            if (!_brandService.Validate(brandUpdateDTO))
                return BadRequest(_brandService.Errors);

            return await _brandService.Update(id, brandUpdateDTO) is BrandDTO brandDTO ? Ok(brandDTO) : NotFound();
        }

        [HttpDelete("{id}")]
        [Authorize(Roles = "User,Admin")]
        public async Task<ActionResult<BrandDTO>> Delete(int id) => await _brandService.Delete(id) is BrandDTO brandDTO ? Ok(brandDTO) : NotFound(null);
    }
}
