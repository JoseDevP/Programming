namespace Prueba
{
    class Program
    {
        static void Main(string[] args)
        {
            CPersona[] personas =
            {
                new CPersona()
                {
                    Name = "Jose",
                    Apellido = "Cazorla",
                    Nacionalidad = "Española"
                },
                new CPersona()
                {
                    Name = "Antonio",
                    Apellido = "Guiterrez",
                    Nacionalidad = "Peruana"
                },
                new CPersona()
                {
                    Name = "Fabiana",
                    Apellido = "Ramos",
                    Nacionalidad = "Venezolana"
                },
            };

            CPais[] nacionalidades_paises =
            {
                new CPais()
                {
                    Nacionalidad = "Española",
                    Pais = "España",
                },
                new CPais()
                {
                    Nacionalidad = "Peruana",
                    Pais = "Perú",
                },
                new CPais()
                {
                    Nacionalidad = "Venezolana",
                    Pais = "Venezuela",
                },
            };

            CComida[] paises_comidas =
            {
                new CComida()
                {
                    Pais = "España",
                    Comida = "Paella",
                },
                new CComida()
                {
                    Pais = "Perú",
                    Comida = "Ceviche",
                },
                new CComida()
                {
                    Pais = "Venezuela",
                    Comida = "Arepas",
                },
            };

            var juntar = from p in personas
                         join n in nacionalidades_paises on p.Nacionalidad equals n.Nacionalidad
                         join c in paises_comidas on n.Pais equals c.Pais
                         select new { Name = p.Name, Apellido = p.Apellido, Nacionalidad = n.Nacionalidad, Pais = n.Pais, Comida = c.Comida };

            foreach (var j in juntar)
                Console.WriteLine($"Name: {j.Name}, Apellido: {j.Apellido}, Nacionalidad: {j.Nacionalidad}, País: {j.Pais}, Comida: {j.Comida}");

        }
    }

    public class CPersona
    {
        public string Name { get; set; }
        public string Apellido { get; set; }
        public string Nacionalidad { get; set; }
    }

    public class CPais
    {
        public string Nacionalidad { get; set; }
        public string Pais { get; set; }
    }

    public class CComida
    {
        public string Pais { get; set; }
        public string Comida { get; set; }
    }
}