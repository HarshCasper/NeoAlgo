/*
C# program for Fibonacci Search 
Fibonacci search -
the Fibonacci search technique is a method of searching a sorted array 
using a divide and conquer algorithm that narrows down possible locations
with the aid of Fibonacci numbers.
*/
using System;

class Fibonacci 
{
    public static int min(int x, int y)
    {
        return (x <= y) ? x : y;
    }

    /* Returns index of x if present, else returns -1 */
    public static int FibMonaccianSearch(int[] arr, int x, int n)
    {
        /* Initialize fibonacci numbers */
        int fibMMm2 = 0;
        int fibMMm1 = 1; 
        int fibM = fibMMm2 + fibMMm1; 

        while (fibM < n)
        {
            fibMMm2 = fibMMm1;
            fibMMm1 = fibM;
            fibM = fibMMm2 + fibMMm1;
        }

        int offset = -1;

        while (fibM > 1)
        {
            int i = min(offset + fibMMm2, n - 1);

            if (arr[i] < x)
            {
                fibM = fibMMm1;
                fibMMm1 = fibMMm2;
                fibMMm2 = fibM - fibMMm1;
                offset = i;
            }

            else if (arr[i] > x)
            {
                fibM = fibMMm2;
                fibMMm1 = fibMMm1 - fibMMm2;
                fibMMm2 = fibM - fibMMm1;
            }
            
            else
                return i;
        }

        if (fibMMm1 == 1 && arr[n - 1] == x)
            return n - 1;

        return -1;
    }

    public static void Main()
    {
        Console.WriteLine("Enter size of array that you like to create");
        int n = int.Parse(Console.ReadLine());
        int[] arr = new int[n];
        Console.WriteLine("Enter values in array");
        for(int i = 0; i < n; i++)
        {
            arr[i] = int.Parse(Console.ReadLine());
        }

        Console.WriteLine("Enter value that you like to find in array");
        int x = int.Parse(Console.ReadLine());

        int ind = FibMonaccianSearch(arr, x, n);
        if (ind >= 0)
            Console.WriteLine("Found at index: " + ind);
        else
            Console.WriteLine(x + " isn't present in the array");
    }
}

/*
Sample Input 
Enter size of array that you like to create
5
Enter values in array
45 56 76 87 89
Enter value that you like to find in array
87

Sample Output 
Found at Index: 3

Time Complexity - O(log(n))
Space Complexity - O(1)
*/
