/*
C# Program for Recursive Implementation of Binary Search
Binary Search - 
Search a sorted array by repeatedly dividing the search interval in half. 
Begin with an interval covering the whole array. If the value of the search
key is less than the item in the middle of the interval, narrow the interval
to the lower half. Otherwise narrow it to the upper half. Repeatedly check 
until the value is found or the interval is empty.
*/
using System;

class Program
{
    static int RecursiveBinarySearch(int[] arr, int l,int r, int x)
    {
        if (r >= l)
        {
            int mid = l + (r - l) / 2;

            //if the element is present at the middle itself
            if (arr[mid] == x)
                return mid;

            //if the element is smaller thar the mid, then it can only be present in left subarray
            if (arr[mid] > x)
                return RecursiveBinarySearch(arr, l, mid - 1, x);

            //else the Element can only be present in right subarray
            return RecursiveBinarySearch(arr, mid + 1, r, x);
        }

        //we reach here when element not present in array 
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

        int index = RecursiveBinarySearch(arr, 0, n - 1, x);

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

Time Complexity  - O(Log(n)) 
Space Complexity - O(1)
*/


