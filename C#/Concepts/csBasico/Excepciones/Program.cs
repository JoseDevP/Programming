using System;
using System.IO;

namespace Excepciones
{
    class Program
    {
        static void Main(string[] args) 
        {
            try
            {
                string content = File.ReadAllText(@"C:\Users\josee\Desktop\Cursos\csharp\Udemy\csBasico\pato.txt");
                Console.WriteLine(content);

                //string content2 = File.ReadAllText(@"C:\Users\josee\Desktop\Cursos\csharp\Udemy\csBasico\pato2.txt");
                //Console.WriteLine(content);

                throw new Exception("Error: Ocurrió algo raro");
            }
            catch (FileNotFoundException ex)
            {
                Console.WriteLine("Error: El archivo no existe: " + ex.Message);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally 
            {
                Console.WriteLine("Final");
            }
            
        }
    }
}