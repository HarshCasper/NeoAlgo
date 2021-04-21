/*
Pigeonhole sorting is a sorting algorithm that is
suitable for sorting lists of elements where the
number of elements and the number of possible
key values are approximately the same.
 */

import java.util.*;
import java.lang.*;

public class PigeonholeSort {
    public static void pigeonhole_sort(int arr[], int n) {

        /*
        initially assuming the min and max values as the
        the first element of input array
         */
        int min_value = arr[0];
        int max_value = arr[0];
        int range, i, j, index;

        //finding out the min and max value
        for (int a = 0; a < n; a++) {
            if (arr[a] > max_value) {
                max_value = arr[a];
            }
            if (arr[a] < min_value) {
                min_value = arr[a];
            }
        }

        //finding range from min and max value
        range = max_value - min_value + 1;

        //initially assigning null values to pigeonHole array
        //size of array is equal to range
        int[] pigeonHole = new int[range];
        Arrays.fill(pigeonHole, 0);

        //Traverse through input array and put every
        //element in its respective pigeonhole
        for (i = 0; i < n; i++) {
            pigeonHole[arr[i] - min_value]++;
        }

        //index in sorted array
        index = 0;

        /*
         Traverse through all pigeonholes one by one. For
         every hole, take its elements and put in array.
         */
        for (j = 0; j < range; j++) {
            while (pigeonHole[j]-- > 0) {
                arr[index++] = j + min_value;
            }
        }
    }

    public static void main(String[] args)
    {
        PigeonholeSort sort = new PigeonholeSort();

        int n;
        Scanner sc=new Scanner(System.in);
        System.out.println();

        //Taking Array size from the user
        System.out.print("Enter the size of array: ");
        n=sc.nextInt();

        int[] a = new int[n];
        System.out.println();

        //taking array input from the user using loop
        System.out.println("Enter the elements of the array: ");
        for(int i=0; i<n; i++)
        {
            a[i]=sc.nextInt();
        }

        //printing out the array elements using for loop
        System.out.print("\nArray elements (before sorting): ");

        for (int i=0; i<n; i++)
        {
            System.out.print(a[i] + " ");
        }

        //printing sorted array
        System.out.println("");
        System.out.print("Array elements (after sorting):: ");
        sort.pigeonhole_sort(a, a.length);

        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println("");

    }
}

/*
    Sample I/O:

    Enter the size of array: 10

    Enter the elements of the array:
    12
    3
    10
    9
    10
    4
    4
    7
    6
    3

    Array elements (before sorting): 12 3 10 9 10 4 4 7 6 3
    Array elements (after sorting):: 3 3 4 4 6 7 9 10 10 12

    Time complexity - O(k + n)

    Space complexity - O(n)

    (here value of k is equal to range(max_value - min_value + 1))
 */
