/*
1) Find a Fibonacci number that is greater than or equal to the size of the array in which we are searching for the key.
2) Compare the key with the predecessor of the Fibonacci number obtained in Step 1 and store it in index.
3) If the key and array element at index are equal then the key is present at position index + 1.        
4) If the key is less than array element at index, then search the left sub-tree to index.
5) If the given key is greater than the array element at index, then search the right sub-tree to index.  
6) If the key is not found, repeat the steps from Step 1 to Step 5 as long as index = 0, that is, Fibonacci number >= array_size. After each iteration the size of array array_size is reduced.
                
*/

package Java;

import java.util.*;

public class FibonacciSearch {

    // function to find the predecessor of the Fibonacci number that is greater than
    // or equal to array_Size .
    public static int getFibanociNumber(int array_Size) {

        int fibk = 0;
        int fibk2 = 0;
        int fibk1 = 1;

        if (array_Size == 0 || array_Size == 1) {
            return 0;
        }

        while (fibk < array_Size) {
            fibk = fibk1 + fibk2;
            fibk2 = fibk1;
            fibk1 = fibk;
        }
        return fibk2;
    }

    public static void main(String[] args) {

        // Creating Scanner Object to read input from user
        Scanner s = new Scanner(System.in);
        int sorted_Array[] = new int[100];
        int key;
        int index;
        int low;
        int high;
        int flag;
        int location;
        int array_Size;

        System.out.println("Enter the size of the array: ");

        // Reading the size of the array from the user
        array_Size = s.nextInt();

        // Reading the elements of the array from the user and storing it in variable
        // sortedArray
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < array_Size; i++) {
            sorted_Array[i] = s.nextInt();
        }
        // Initialising the values of some variables
        low = 0;
        location = -1;
        high = array_Size - 1;
        flag = 0;

        // Read the key element to be searched from the user
        System.out.println("Enter the element which is to be searched: ");
        // Storing it in element in variable key
        key = s.nextInt();

        // Closing the scanner Object
        s.close();

        index = 0;
        while (flag != 1 && low <= high) {
            // Returns the predecessor of the Fibonacci number that is greater than or equal
            // to array_Size .
            index = getFibanociNumber(array_Size);

            // key and array element at index are equal
            if (key == sorted_Array[index + low]) {
                location = low + index;
                flag = 1;
                break;
            }
            // key is greater than array element at index
            else if (key > sorted_Array[index + low])

            { // Updating the lower index
                low = low + index + 1;
            } else {
                // Updating the higher index
                high = low + index - 1;
            }
            // adjusting the size of the array
            array_Size = high - low + 1;

        }
        // The given key is present in the array
        if (flag == 1)
        // Incrementing location by one to get the position of key as location
        // represents index of key
        {
            location += 1;
            System.out.println("The given element " + key + " found at location " + location + " ");
        }

        // The given key is not present
        else {
            System.out.println("The given element " + key + " is not present in the given array");
        }

    }

}

/*
   TEST CASES
  
   Enter the size of the array: 10 
   Enter the elements of the array: -15 0 9 14 23 35 49 52 65 77 
   Enter the element which is to be searched: 52 
   The given element 52 found at location 8

 */

/*
  COMPLEXITY
  
  Time complexity O(log n) 
 
 */