using Backend.Services;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;

namespace Backend.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class PeopleController : ControllerBase
    {
        private IPeopleService _peopleService;

        public PeopleController([FromKeyedServices("people2Service")] IPeopleService peopleService)
        {
            _peopleService = peopleService;
        }


        [HttpGet("all")]
        public List<People> GetPeople() => Repository.people;


        [HttpGet("{id}")]
        public ActionResult<People> Get(int id)
        {
            var people = Repository.people.FirstOrDefault(p => p.ID == id);
            if(people == null)
            {
                return NotFound();
            }

            return Ok(people);
        }


        [HttpGet("search/{search}")]
        public List<People> Get(string search) => 
            Repository.people.Where(p => p.Name.ToUpper().Contains(search.ToUpper())).ToList();



        [HttpPost]
        public IActionResult Add(People people)
        {
            if(!_peopleService.Validate(people))
            {
                return BadRequest();
            }

            Repository.people.Add(people);
            return NoContent();
        }
    }

    public class Repository
    {
        public static List<People> people = new List<People>()
        {
            new People()
            {
                ID = 1,
                Name = "Foo",
                BirthDate = new DateTime(1896,04,15)
            },
            new People()
            {
                ID = 2,
                Name = "Juan",
                BirthDate = new DateTime(1405,03,12)
            },
            new People()
            {
                ID = 3,
                Name = "Jose",
                BirthDate = new DateTime(1998,09,22)
            },
            new People()
            {
                ID = 4,
                Name = "Antonia",
                BirthDate = new DateTime(1998,11,30)
            },
        };
    }

    public class People
    {
        public int ID { get; set; }
        public string Name { get; set; }
        public DateTime BirthDate { get; set; }
    }
}
