using AutoMapper;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Cors;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using MoviesAPI.Models;
using MoviesAPI.Models.DTOs;
using MoviesAPI.Repository.IRepository;

namespace MoviesAPI.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class CategoriesController : ControllerBase
    {
        private readonly IUnitOfWork _unitOfWork;
        private readonly IMapper _mapper;
        public CategoriesController(IUnitOfWork unitOfWork, IMapper mapper)
        {
            _unitOfWork = unitOfWork;
            _mapper = mapper;
        }

        [HttpGet()]
        [ProducesResponseType(StatusCodes.Status403Forbidden)]
        [ProducesResponseType(StatusCodes.Status200OK)]
        //[EnableCors("CorsPolitic")]
        public async Task<IActionResult> GetCategories()
        {
            var categoriesList = await _unitOfWork.CategoryRepository.GetAllElements();

            var dtoCategoriesList = new List<CategoryDTO>();

            foreach (var category in categoriesList)
            {
                dtoCategoriesList.Add(_mapper.Map<CategoryDTO>(category));
            }

            return Ok(dtoCategoriesList);
        }

        [HttpGet("{categoryId:int}", Name = "GetCategory")]
        [ProducesResponseType(StatusCodes.Status403Forbidden)]
        [ProducesResponseType(StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        [ProducesResponseType(StatusCodes.Status404NotFound)]
        public async Task<IActionResult> GetCategory(int categoryId)
        {
            var categoryItem = await _unitOfWork.CategoryRepository.GetById(categoryId);

            if(categoryItem == null) 
                return NotFound();

            var cartegoryItemDTO = _mapper.Map<CategoryDTO>(categoryItem);


            return Ok(cartegoryItemDTO);
        }

        [Authorize(Roles = "Admin")]
        [HttpPost]
        [ProducesResponseType(StatusCodes.Status201Created)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        [ProducesResponseType(StatusCodes.Status500InternalServerError)]
        [ProducesResponseType(StatusCodes.Status401Unauthorized)]
        public async Task<IActionResult> CreateCategory([FromBody] CategoryCreateDTO categoryCreateDTO)
        {
            if (!ModelState.IsValid)
                return BadRequest(ModelState);

            if (categoryCreateDTO == null)
                return BadRequest();

            if(await _unitOfWork.CategoryRepository.ElementExist(categoryCreateDTO.Name))
            {
                ModelState.AddModelError("",$"La categoria ya existe");
                return StatusCode(404,ModelState);
            }

            var category = _mapper.Map<Category>(categoryCreateDTO);
            category.CreationDate = DateTime.Now;

            await _unitOfWork.CategoryRepository.CreateElement(category);

            if (! await _unitOfWork.Save())
            {
                ModelState.AddModelError("", $"Algo ha salido mal al guardar el registro {category.Name}");
                return StatusCode(404, ModelState);
            }

            return CreatedAtRoute("GetCategory", new {categoryId = category.Id}, category);
        }

        [Authorize(Roles = "Admin")]
        [HttpPatch("{categoryId:int}", Name = "PatchCategory")]
        [ProducesResponseType(StatusCodes.Status204NoContent)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        [ProducesResponseType(StatusCodes.Status401Unauthorized)]
        [ProducesResponseType(StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> PatchCategory(int categoryId, [FromBody] CategoryDTO categoryDTO)
        {
            if (!ModelState.IsValid)
                return BadRequest(ModelState);

            if (categoryDTO == null || categoryId != categoryDTO.Id)
                return BadRequest();

            var currentCategory = await _unitOfWork.CategoryRepository.GetById(categoryId);
            if (currentCategory == null)
                return NotFound($"No se encontró la categoría con id {categoryId}");

            _mapper.Map(categoryDTO, currentCategory);

            // Guardar cambios
            if (!await _unitOfWork.Save())
            {
                ModelState.AddModelError("", $"Algo ha salido mal al actualizar el registro {currentCategory.Name}");
                return StatusCode(500, ModelState);
            }

            return NoContent();
        }

        [Authorize(Roles = "Admin")]
        [HttpPut("{categoryId:int}", Name = "PutCategory")]
        [ProducesResponseType(StatusCodes.Status204NoContent)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        [ProducesResponseType(StatusCodes.Status401Unauthorized)]
        [ProducesResponseType(StatusCodes.Status404NotFound)]
        [ProducesResponseType(StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> PutCategory(int categoryId, [FromBody] CategoryDTO categoryDTO)
        {
            if (!ModelState.IsValid)
                return BadRequest(ModelState);

            if (categoryDTO == null || categoryId != categoryDTO.Id)
                return BadRequest();

            var currentCategory = _unitOfWork.CategoryRepository.GetById(categoryDTO.Id);
            if (currentCategory == null) 
                return NotFound($"No se encontró la categoria con id {categoryDTO.Id}");

            var category = _mapper.Map<Category>(categoryDTO);

            _unitOfWork.CategoryRepository.UpdateCategory(category);

            if (!await _unitOfWork.Save())
            {
                ModelState.AddModelError("", $"Algo ha salido mal al actualizar el registro {category.Name}");
                return StatusCode(500, ModelState);
            }

            return NoContent();
        }

        [Authorize(Roles = "Admin")]
        [HttpDelete("{categoryId:int}", Name = "DeleteCategory")]
        [ProducesResponseType(StatusCodes.Status204NoContent)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        [ProducesResponseType(StatusCodes.Status401Unauthorized)]
        [ProducesResponseType(StatusCodes.Status404NotFound)]
        [ProducesResponseType(StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> DeleteCategory(int categoryId)
        {
            if (! await _unitOfWork.CategoryRepository.ElementExist(categoryId))
                return NotFound();

            var category = await _unitOfWork.CategoryRepository.GetById(categoryId);

            _unitOfWork.CategoryRepository.DeleteElement(category);

            if (!await _unitOfWork.Save())
            {
                ModelState.AddModelError("", $"Algo ha salido mal al actualizar el registro {category.Name}");
                return StatusCode(500, ModelState);
            }

            return NoContent();
        }
    }
}
