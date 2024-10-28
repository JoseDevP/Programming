using System;
using System.Collections.Generic;

public class Porgram
{
    static int Fibonacci(int n)
    {
        if( n <= 0)
            return 0;
        if (n <= 1)
            return 1;
        
        return Fibonacci(n-1) + Fibonacci(n-2);
    }

    static int FibonacciStack(int n)
    {
        if (n <= 0) return 0;
        if (n == 1) return 1;

        Stack<int> values = new Stack<int>();
        values.Push(n);

        int a = 0, b = 0;

        while (values.Count > 0)
        {
            int current = values.Pop();

            if(current == 1)
            {
                a += 1;
            }
            else if (current == 2)
            {
                b += 1;
            }
            else
            {
                values.Push(current - 1);
                values.Push(current - 2);
            }
        }

        return a + b; 
        
    }

    static void Main(string[] args)
    {
        
        for (int i = 0; i <= 50; i++)
            Console.WriteLine(FibonacciStack(i));
    }
}