public abstract class Poligon
{
    public abstract double GetArea();
}

public class Triangle : Poligon
{
    public double Base { get; private set; }
    public double Height { get; private set; }
    public Triangle(double ba, double hei)
    {
        Base = ba;
        Height = hei;
    }
    public override double GetArea()
    {
        return ((Base*Height) / 2);
    }
}

public class Square : Poligon
{
    public double Side { get; private set; }
    public override double GetArea()
    {
        return Side * Side;
    }
    public Square(double si)
    {
        Side = si;
    }
}

public class Rectangle : Poligon
{
    public double Lenght { get; private set; }
    public double Width { get; private set; }
    public override double GetArea()
    {
        return Lenght * Width;
    }
    public Rectangle(double le, double wi)
    {
        Lenght = le;
        Width = wi;
    }
}

public class Program
{
    public static void GetArea(Poligon pol)
    {
        Console.WriteLine(pol.GetArea());
    }

    public static void Main(string[] args)
    {
        Poligon triangle = new Triangle(3,4);
        Poligon square = new Square(3);
        Poligon rectangle = new Rectangle(3,4);

        GetArea(triangle);
        GetArea(square);
        GetArea(rectangle);
    }
}