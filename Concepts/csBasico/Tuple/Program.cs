namespace Tuple
{
    class Program
    {
        static void Main(string[] args)
        {
            (int id, string name) product = (1, "Cerveza stout");


            product.name = "cerveza porter";


            var person = (1, "Jose");


            var people = new[]
            {
                (1, "Jose"),
                (2, "Pedro"),
                (3, "Juan"),
            };

            (int id, string name)[] people2 = new[]
            {
                (1, "Jose"),
                (2, "Pedro"),
                (3, "Juan"),
            };

            foreach (var p in people2)
                Console.WriteLine($"persona {p.id}, Name {p.name}");

            var cityInfo = GetLocationCDMX();
            Console.WriteLine($"lat: {cityInfo.lat}, longitud: {cityInfo.lon}, Nombre: {cityInfo.name} ");

            var (_, lng, _) = GetLocationCDMX();

            Console.WriteLine(lng);

        }

        public static (float lat, float lon, string name) GetLocationCDMX()
        {
            float lat = 19.12121f;
            float lon = -99.19238f;
            string name = "CDMX";

            return (lat, lon,name);
        }
    }
}