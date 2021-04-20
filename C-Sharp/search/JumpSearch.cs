/*
C# program for jump Search
Jump Search -
Jump Search is a searching algorithm for sorted arrays. The basic idea
is to check fewer elements (than linear search) by jumping ahead by 
fixed steps or skipping some elements in place of searching all elements.
*/
using System;

public class JumpSearch
{
    public static int JumpSearchAlgo(int[] arr, int x)
    {
        int n = arr.Length;

        //Finding Block size to be jumped
        int step = (int)Math.Floor(Math.Sqrt(n));

        //Finding the block where element is present (if it is present)
        int prev = 0;
        while (arr[Math.Min(step, n) - 1] < x)
        {
            prev = step;
            step += (int)Math.Floor(Math.Sqrt(n));
            if (prev >= n)
                return -1;
        }

        //Doing a linear search for x in block beginning with prev.
        while (arr[prev] < x)
        {
            prev++;

            //if we reached next block or end of array,element is not present.
            if (prev == Math.Min(step, n))
                return -1;

        }

        //if element is found 
        if (arr[prev] == x)
            return prev;

        return -1;
    }

    public static void Main()
    {
        Console.WriteLine("Enter size of array that you like to create");
        int n = int.Parse( Console.ReadLine());
        
        int[] arr = new int[n];
        Console.WriteLine("Enter values in array");
        
        for (int i = 0; i < n; i++)
        {
            arr[i] = int.Parse( Console.ReadLine());
        }

        Console.WriteLine("Enter value that you like to find in array");
        int x = int.Parse(Console.ReadLine());

        int index = JumpSearchAlgo(arr, x);
        if (index >= 0)
            Console.WriteLine("Found at index: " + index);
        else
            Console.WriteLine(x + " isn't present in the array");
    }
}
/*
Sample Input
Enter size of array that you like to create
10
Enter values in array
12
23
34
45
56
67
78
89
90
100
Enter value that you like to find in array
45

Sample Output
Found at index: 3

Time Complexity  - O(√n) 
Space Complexity - O(1)

*/
