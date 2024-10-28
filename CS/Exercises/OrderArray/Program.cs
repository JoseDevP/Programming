public class Program
{
    public static T[] QuickSort<T>(T[] array, int min, int max, string ord = "Asc") where T : IComparable<T>
    {
        if(array == null || (ord != "Asc" && ord != "Desc"))
        {
            Console.WriteLine("El array no puede ser null o ord tiene que ser Asc o Desc");
            return array;
        }

        if (min < max)
        {
            int izq = min, der = max;
            T medio = array[(izq + der) / 2];

            while (izq <= der)
            {
                if (ord == "Asc")
                {
                    while (array[izq].CompareTo(medio) < 0) izq++;
                    while (array[der].CompareTo(medio) > 0) der--;
                }
                else
                {
                    while (array[izq].CompareTo(medio) > 0) izq++;
                    while (array[der].CompareTo(medio) < 0) der--;
                }

                if (izq <= der)
                {
                    T temp = array[izq];
                    array[izq] = array[der];
                    array[der] = temp;
                    izq++;
                    der--;
                }
            }

            if (izq < max) QuickSort(array, izq, max, ord);
            if (der > min) QuickSort(array, min, der, ord);
        }

        return array;
    }


    public static void Main(string[] args)
    {
        int[] array = { 8, 3, 1, 4, 2};

        List<int> list = array.ToList();
        List<int> sortedList = list.OrderBy(x => x).ToList();

        QuickSort(array,0,array.Length -1,"Asc");

        foreach (var item in array)
        {
            Console.WriteLine(item + " ");
        }

        Console.WriteLine("\n\n");

        foreach (var item in sortedList)
        {
            Console.WriteLine(item + " ");
        }
    }
}