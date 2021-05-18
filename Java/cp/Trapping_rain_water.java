
/* Given n non-negative integers representing an elevation map where the 
width of each bar is 1, compute how much water it can trap after raining. */

import java.io.*;
import java.util.*;

class Trapping_rain_water {
    static int trap(int arr[]) {

        // Your code here
        int n = arr.length;
        if (n == 0)
            return 0;
        int left[] = new int[n];

        int right[] = new int[n];

        // Initialize result
        int water = 0;

        // Fill left array
        left[0] = arr[0];
        for (int i = 1; i < n; i++)
            left[i] = Math.max(left[i - 1], arr[i]);

        // Fill right array
        right[n - 1] = arr[n - 1];

        // Find max
        for (int i = n - 2; i >= 0; i--)
            right[i] = Math.max(right[i + 1], arr[i]);

        // Find min
        for (int i = 0; i < n; i++)
            water += Math.min(left[i], right[i]) - arr[i];

        // return the answer
        return water;

    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of elements: ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the elements: ");
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        System.out.println("Water it can trap is: " + trap(arr));
    }
}

/* 
Time Complexity: O(n)
Space Complexity: O(n)

Example 1:

Input:
Enter number of elements: 
12
Enter the elements: 
0 1 0 2 1 0 1 3 2 1 2 1

Output:
Water it can trap is: 6

Example 2:

Input:
Enter number of elements: 
5
Enter the elements: 
1 4 2 0 1

Output:
Water it can trap is: 1

*/
