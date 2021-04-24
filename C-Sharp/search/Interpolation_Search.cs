/*
C# Program for Interpolation Search
Interpolation Search - 
For cases where the values in a sorted array are uniformly distributed, 
Interpolation Search outperforms Binary Search. To verify, Binary Search 
always goes to the middle variable. Interpolation search, on the other 
hand, can lead to various locations depending on the value of the key 
being searched.
*/
using System;

class Program
{
    static int InterPolationSearch(int[] arr, int n, int x)
    {
        int low = 0, high = (n - 1); 

        while (low <= high && x >= arr[low] && x <= arr[high])
        {
            if (low == high)
            {
                if (arr[low] == x) return low;
                return -1;
            }
            // Probing the position with keeping uniform distribution in mind. 

            int pos = low + (((high - low)/(arr[high] - arr[low]))*(x - arr[low]));

            // Condition of element to be found 
            if (arr[pos] == x)
                return pos;

            // If x is larger, x is in upper part 
            if (arr[pos] < x)
                low = pos + 1;

            // If x is smaller, x is in the lower part 
            else
                high = pos - 1;
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

        int index = InterPolationSearch(arr,n,x); 

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
23
34
45
56
67
78
89
Enter value that you like to find in array
56

Sample Output
Found at index: 3

Time Complexity 
Average Case - O(log log n) 
Worst Case - O(N)

Space Complexity - O(1)
*/
