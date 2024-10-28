public class Program
{
    public static List<T> ReturnArray<T>(List<T> l1, List<T> l2, bool op)
    {
        List<T> list = new List<T>();

        for (int i = 0; i < l1.Count; i++)
        {
            bool found = l2.Contains(l1[i]); 
            
            if (op == true && found) 
            {
                if (!list.Contains(l1[i])) 
                    list.Add(l1[i]);
            }
            else if (op == false && !found)
            {
                if (!list.Contains(l1[i])) 
                    list.Add(l1[i]);
            }
        }
        return list;
    }

    public static void Main(string[] args)
    {
        List<int> l1 = new List<int>{2,3,5,8};
        List<int> l2 = new List<int>{8,1,6,2};

        List<int> l3 = ReturnArray<int>(l1, l2, true);

        foreach (int i in l3)
        {
            Console.WriteLine(i + " ");
        }
    }
}