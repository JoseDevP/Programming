﻿namespace ExepcionesPersonalizadas
{
    class Program
    {
        public static void Main(string[] args)
        {
            try
            {
                Beer beer = new Beer()
                {
                    Name = "London Porter",
                    //Brand = "Fuller's"
                };
                beer.ToString();
            }
            catch (InvalidBeerException ex)
            {
                Console.WriteLine(ex.Message);
            }
            
        }
    }

    public class InvalidBeerException : Exception
    {
        public InvalidBeerException() : base("La cerveza no tiene nombre o marca, por lo cual es invalida") { }
    }

    public class Beer 
    {
        public string Name { get; set; }
        public string Brand { get; set; }

        public override string ToString()
        {
            if(Name == null || Brand == null) 
                throw new InvalidBeerException();

            return $"Cerveza: {Name}, Brand {Brand}";
        }
    }
}