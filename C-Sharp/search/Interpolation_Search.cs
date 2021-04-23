/*
C# Program for Interpolation Search
Interpolation Search - 
The Interpolation Search is an improvement over Binary Search for instances,where 
the values in a sorted array are uniformly distributed.Binary Search always goes 
to the middle element to check. On the other hand, interpolation search may go to
different locations according to the value of the key being searched.
*/
using System;

class Program
{
    static int InterPolationSearch(int[] arr, int l, int h, int x)
    {
        int pos;
        if (l < h && x >= arr[l] && x <= arr[h])
        {
            pos = l + ((h - l) / (arr[h] - arr[l])) * (x - arr[l]);

            if(arr[pos] == x)
                return pos;

            if (arr[pos] < x)
                return InterPolationSearch(arr, pos + 1, h, x);

            if (arr[pos] > x)
                return InterPolationSearch(arr, l, pos - 1, x);
        }
        return -1;
    }

    static void Main()
    {
        Console.WriteLine("Enter size of array that you like to create");
        int n = int.Parse(Console.ReadLine());

        int[] arr = new int[n];
        Console.WriteLine("Enter values in array");

        for (int i = 0; i < n; i++)
        {
            arr[i] = int.Parse(Console.ReadLine());
        }

        Console.WriteLine("Enter value that you like to find in array");
        int x = int.Parse(Console.ReadLine());

        int index = InterPolationSearch(arr,0,n-1,x); 

        if (index >= 0)
            Console.WriteLine("Found at index: " + index);
        else
            Console.WriteLine(x + " isn't present in the array");
    }
}
/*
Sample Input
Enter size of array that you like to create
7
Enter values in array
7
14
21
28
35
42
49
Enter value that you like to find in array
35

Sample Output
Found at index: 4

Time Complexity 
Average Case - O(log log n) 
Worst Case - O(N)

Space Complexity - O(1)
*/
