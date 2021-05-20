/*
Insert Position

For a given sorted array of distinct integers arr[]
and a key value, your task is to return the index where 
it would best fit or be inserted in the order.
*/

import java.util.*;

public class InsertPosition
{
    public static int searchPosition(int[] arr, int key)
    {
        int leftptr = 0;
        int rightptr = arr.length - 1;

        while(leftptr < rightptr)
        {
            int mid = (leftptr + rightptr) / 2;
            if(arr[mid] == key)
            {
                return mid;
            }
            else if(arr[mid] < key)
            {
                leftptr = mid + 1;
            }
            else
            {
                rightptr = mid - 1;
            }
        }

        return leftptr;
    }

    //DRIVER CODE
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        //size of array
        System.out.println("Enter the number of elements of array: ");
        int size = sc.nextInt();

        //key value
        System.out.println("Enter the key value to be inserted: ");
        int key = sc.nextInt();

        int []arr = new int[size];
        //array elements
        System.out.println("Enter the elements for array in sorted order: ");
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println("Position at which the key value should be inserted is: ");
        System.out.print(searchPosition(arr, key));
        sc.close();
    }
}

/*

Example:
Input--
Enter the number of elements of array: 5
Enter the key value to be inserted: 2
Enter the elements for array in sorted order: [1, 4, 5, 8, 9]
Output--
Position at which the key value should be inserted is: 1

TIME COMPLEXITY--> O(N)
SPACE COMPLEXITY--> O(1)

*/
