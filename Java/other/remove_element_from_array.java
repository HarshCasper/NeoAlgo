/*

Remove Element from the Array

For a given array of integers arr[], and a key value 
remove the key values from the array if present, and 
return the new size of the array thus obtained.
It is given that removal of all the elements should be in-place,
there should be no use of extra space.

*/

import java.util.Scanner; 
import java.util.Arrays; 

class remove_elements_from_array
{
    //function to remove the key value
    //from arrray if present
    public int removeKey(int arr[], int key)
    {
        //simply returning for an empty array
        if(arr.length == 0){
            return 0;
        }

        int newSize = 0;
        
        for(int pass = 0; pass < arr.length; pass++)
        {
            if(arr[pass] != key)
            {
                arr[newSize] = arr[pass];
                newSize++;
            }
        }

        return newSize;
    }

    //driver method
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in); 

        System.out.println("Enter the size of the array: "); 
        int size = sc.nextInt(); 

        System.out.println("Enter the key value: "); 
        int key = sc.nextInt(); 

        int arr[] = new int[size]; 

        System.out.println("Enter the elements of array: "); 
        for(int i = 0; i < size; i++) 
        { 
            arr[i] = sc.nextInt(); 
        } 

        System.out.println("New size of array thus formed after the removal of "+key+" is : ");
        System.out.print(removeKey(arr, key));
        System.out.println();
    }
}

/*

EXAMPLES:-

Example 1:
Input--
Enter the size of the array: 5
Enter the key value: 6
Enter the elements of array: 2 1 8 33 6  
New size of array thus formed after the removal of 6 is : 4

Example 2:
Input--
Enter the size of the array: 3
Enter the key value: 1
Enter the elements of array: 6 80 44
New size of array thus formed after the removal of 1 is : 3

Example 3:
Input--
Enter the size of the array: 1
Enter the key value: 0
Enter the elements of array: 1  
New size of array thus formed after the removal of 0 is : 1

TIME COMPLEXITY --> O(N)
SPACE COMPLEXITY --> O(1)
*/
