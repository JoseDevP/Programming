using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;

namespace Backend.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class SomeController : ControllerBase
    {
        [HttpGet("sync")]
        public IActionResult GetSync()
        {
            Stopwatch stopwatch = Stopwatch.StartNew();
            stopwatch.Start();

            Thread.Sleep(1000);
            Console.WriteLine("Conexión a base de datos terminada");

            Thread.Sleep(1000);
            Console.WriteLine("Envio de mail terminado");


            Console.WriteLine("Todo ha terminado");

            stopwatch.Stop();

            return Ok(stopwatch.Elapsed);  
        }

        [HttpGet("async")]
        public async Task<IActionResult> GetAsync()
        {
            Stopwatch stopwatch = Stopwatch.StartNew();
            stopwatch.Start();

            var task1 = new Task<int>(() =>
            {
                Thread.Sleep(1000);
                Console.WriteLine("Conexión a base de datos terminada");
                return 8;
            });
            task1.Start();

            var task2 = new Task<int>(() =>
            {
                Thread.Sleep(1000);
                Console.WriteLine("Envio de mail terminado");
                return 2;
            });
            task2.Start();

            var resultado = await task1;
            var resultado2 = await task2;

            Console.WriteLine("Todo ha terminado");

            stopwatch.Stop();

            return Ok(stopwatch.Elapsed + " Resultado1: " + resultado + " Resultado2: " + resultado2);
        }
    }
}
