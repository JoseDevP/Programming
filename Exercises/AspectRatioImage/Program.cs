using System;
using System.Net.Http;
using System.Threading.Tasks;
using System.Drawing;
using System.IO;

public class Program
{
    static async Task Main(string[] args)
    {
        string imageUrl = "https://images.unsplash.com/photo-1506748686214-e9df14d4d9d0?crop=entropy&cs=tinysrgb&fit=max&fm=jpg&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&ixlib=rb-1.2.1&q=80&w=400";

        using (HttpClient httpClient = new HttpClient())
        {
            byte[] imageBytes = await httpClient.GetByteArrayAsync(imageUrl);

            using (var stream = new MemoryStream(imageBytes))
            {
                using (Image image = Image.FromStream(stream))
                {
                    int width = image.Width;
                    int height = image.Height;

                    double aspectRatio = (double)width / height;

                    Console.WriteLine($"El aspect ratio de la imagen es: {aspectRatio:F2} (o {width}:{height})");
                }
            }
        }
    }
}
