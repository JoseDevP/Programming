﻿using Asp.Versioning;
using AutoMapper;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using MoviesAPI.Models;
using MoviesAPI.Models.DTOs;
using MoviesAPI.Repository;
using MoviesAPI.Repository.IRepository;

namespace MoviesAPI.Controllers.V1
{
    [ResponseCache(CacheProfileName = "Default")]
    [Route("api/v{version:apiVersion}/[controller]")]
    [ApiController]
    [ApiVersion("1.0")]
    public class MoviesControllerV1 : ControllerBase
    {
        private readonly IUnitOfWork _unitOfWork;
        private readonly IMapper _mapper;
        public MoviesControllerV1(IUnitOfWork unitOfWork, IMapper mapper)
        {
            _unitOfWork = unitOfWork;
            _mapper = mapper;
        }

        [HttpGet]
        [ProducesResponseType(StatusCodes.Status403Forbidden)]
        [ProducesResponseType(StatusCodes.Status200OK)]
        public async Task<IActionResult> GetMovies()
        {
            var moviesList = await _unitOfWork.MovieRepository.GetAllElements();

            var dtoMoviesList = new List<MovieDTO>();

            foreach (var movie in moviesList)
            {
                dtoMoviesList.Add(_mapper.Map<MovieDTO>(movie));
            }

            return Ok(dtoMoviesList);
        }

        [HttpGet("{movieId:int}", Name = "GetMovie")]
        [ProducesResponseType(StatusCodes.Status403Forbidden)]
        [ProducesResponseType(StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        [ProducesResponseType(StatusCodes.Status404NotFound)]
        public async Task<IActionResult> GetMovie(int movieId)
        {
            var movieItem = await _unitOfWork.MovieRepository.GetById(movieId);

            if (movieItem == null)
                return NotFound();

            var movieItemDTO = _mapper.Map<MovieDTO>(movieItem);


            return Ok(movieItemDTO);
        }

        [Authorize(Roles = "Admin")]
        [HttpPost]
        [ProducesResponseType(201, Type = typeof(MovieDTO))]
        [ProducesResponseType(StatusCodes.Status201Created)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        [ProducesResponseType(StatusCodes.Status500InternalServerError)]
        [ProducesResponseType(StatusCodes.Status401Unauthorized)]
        public async Task<IActionResult> CreateMovie([FromBody] MovieCreateDTO movieCreateDTO)
        {
            if (!ModelState.IsValid)
                return BadRequest(ModelState);

            if (movieCreateDTO == null)
                return BadRequest();

            if (await _unitOfWork.MovieRepository.ElementExist(movieCreateDTO.Name))
            {
                ModelState.AddModelError("", $"La pelicula ya existe");
                return StatusCode(404, ModelState);
            }

            var movie = _mapper.Map<Movie>(movieCreateDTO);
            movie.CreationDate = DateTime.Now;

            await _unitOfWork.MovieRepository.CreateElement(movie);

            if (!await _unitOfWork.Save())
            {
                ModelState.AddModelError("", $"Algo ha salido mal al guardar el registro {movie.Name}");
                return StatusCode(404, ModelState);
            }

            return CreatedAtRoute("GetMovie", new { movieId = movie.Id }, movie);
        }

        [Authorize(Roles = "Admin")]
        [HttpPatch("{movieId:int}", Name = "PatchMovie")]
        [ProducesResponseType(StatusCodes.Status204NoContent)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        [ProducesResponseType(StatusCodes.Status401Unauthorized)]
        [ProducesResponseType(StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> PatchMovie(int movieId, [FromBody] MovieDTO movieDTO)
        {
            if (!ModelState.IsValid)
                return BadRequest(ModelState);

            if (movieDTO == null || movieId != movieDTO.Id)
                return BadRequest();

            var currentMovie = await _unitOfWork.MovieRepository.GetById(movieId);
            if (currentMovie == null)
                return NotFound($"No se encontró la película con id {movieId}");

            _mapper.Map(movieDTO, currentMovie);
            currentMovie.CreationDate = DateTime.Now;

            if (!await _unitOfWork.Save())
            {
                ModelState.AddModelError("", $"Algo ha salido mal al actualizar el registro {currentMovie.Name}");
                return StatusCode(500, ModelState);
            }

            return NoContent();
        }

        [Authorize(Roles = "Admin")]
        [HttpDelete("{movieId:int}", Name = "DeleteMovie")]
        [ProducesResponseType(StatusCodes.Status204NoContent)]
        [ProducesResponseType(StatusCodes.Status400BadRequest)]
        [ProducesResponseType(StatusCodes.Status401Unauthorized)]
        [ProducesResponseType(StatusCodes.Status404NotFound)]
        [ProducesResponseType(StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> DeleteMovie(int movieId)
        {
            if (!await _unitOfWork.MovieRepository.ElementExist(movieId))
                return NotFound();

            var movie = await _unitOfWork.MovieRepository.GetById(movieId);

            _unitOfWork.MovieRepository.DeleteElement(movie);

            if (!await _unitOfWork.Save())
            {
                ModelState.AddModelError("", $"Algo ha salido mal al actualizar el registro {movie.Name}");
                return StatusCode(500, ModelState);
            }

            return NoContent();
        }

        [HttpGet("GetMoviesInCategory/{idCategory:int}")]
        [ProducesResponseType(StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status404NotFound)]
        [ProducesResponseType(StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> GetMoviesInCategory(int idCategory)
        {
            var moviesList = await _unitOfWork.MovieRepository.GetMoviesInCategory(idCategory);

            if (moviesList == null)
                return NotFound();

            var movieItem = new List<MovieDTO>();
            foreach (var movie in moviesList)
            {
                movieItem.Add(_mapper.Map<MovieDTO>(movie));
            }

            return Ok(movieItem);
        }

        [HttpGet("Search")]
        [ProducesResponseType(StatusCodes.Status200OK)]
        [ProducesResponseType(StatusCodes.Status404NotFound)]
        [ProducesResponseType(StatusCodes.Status500InternalServerError)]
        public async Task<IActionResult> Search(string name)
        {
            try
            {
                var result = await _unitOfWork.MovieRepository.SearchMovie(name);
                if (result.Any())
                {
                    return Ok(result);
                }

                return NotFound();
            }
            catch (Exception)
            {
                return StatusCode(StatusCodes.Status500InternalServerError, "Error recuperando datos del servidor");
            }
        }
    }
}
