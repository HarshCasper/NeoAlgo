/*

Remove an element from the array

For a given array of integers arr[], and
a value key, your task is to remove all the instances of value present 
in the array, and return the new size of the array.
It is given that the arrangement should be done in-place i.e.
with no extra space used.

*/

import java.util.*;

class remove_element_from_array
{
    //function to find the new size of the array
    public int removeKey(int arr[], int key)
    {
        int pass=0;
        int size=arr.length;
        while(pass<size)
        {
            if(arr[pass]==key)
            {
                //on encountering the key value we replace the current element 
                //with the last element and then decreament the size of array
                // that is we basically remove key element from array  
                arr[pass]=arr[size-1];
                size--;//decrementing the size of array
            }
            else
            {
                pass++;
            }
        }
        return size;
    }

    //driver method
    public satic void main(String []args)
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the length of the array: ");
        int n = sc.nextInt();

        System.out.print("Enter the value to be removed: ");
        int key = sc.nextInt();
        
        int arr[] = new int[n];
        System.out.println("Enter the values for array: ");
        for(int i=0; i<n; i++)
        {
            arr[i] = sc.nextInt();
        }

        System.out.println("New size of the array after removing the key element "+key+" is: ");
        System.out.print(removeKey(arr, key));
    }

}

/*

EXAMPLES:

Example 1-
Input--
Enter the length of the array: 5
Enter the value to be removed: 1
Enter the values for array: 1 3 4 5 1
Output--
New size of the array after removing the key element 1 is: 3

Example 2-
Input--
Enter the length of the array: 8
Enter the value to be removed: 4
Enter the values for array: 2 4 4 4 4 5 6 7
Output--
New size of the array after removing the key element 4 is: 4

TIME COMPLEXITY --> O(N)

*/
