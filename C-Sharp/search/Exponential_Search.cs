/*
C# Program for Interpolation Search
Exponential Search - 
Exponential search allows you to look at a sorted, unbounded list for a 
specific input value (the search "key"). The algorithm is divided into 
two stages. The first stage establishes a range in which the search key
will be found if it were in the set. This selection is then subjected to
a binary search in the second level.
*/
using System;

class Program
{
    static int ExponentialSearchs(int[] arr, int n, int x)
    {
        if (arr[0] == x)
            return 0;

        int i = 1;
        while (i < n && arr[i] <= x)
            i *= 2;

        //Call Binary Search 
        return BinarySearch(arr, i / 2, Math.Min(i, n - 1), x);
    }


    static int BinarySearch(int[] arr, int l, int r, int x)
    {
        if (r >= l) 
        {
            int mid = l + (r - l) / 2;

            if (arr[mid] == x)
                return mid;

            if (arr[mid] > x)
                return BinarySearch(arr, l, mid - l, x);

            return BinarySearch(arr, mid + l, r, x);
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

        int index = ExponentialSearchs(arr, n, x);

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

Time Complexity - O(Log(n))
Space Complexity - O(1)
*/
