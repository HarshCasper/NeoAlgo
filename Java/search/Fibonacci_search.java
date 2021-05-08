// Find a Fibonacci number that is greater than or equal to the size of the array in which we are searching for the key.
// Compare the key with the predecessor of the Fibonacci number obtained in Step 1 and store it in index.
// If the key and array element at index are equal then the key is present at position index + 1.        
// If the key is less than array element at index, then search the left sub-tree to index.
// If the given key is greater than the array element at index, then search the right sub-tree to index.  
// If the key is not found, repeat the steps from Step 1 to Step 5 as long as index = 0, that is, Fibonacci number >= array_size. 
// After each iteration the size of array array_size is reduced.

package Java;
import java.util.*;

public class FibonacciSearch {
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
        Scanner s = new Scanner(System.in);
        int sorted_Array[] = new int[100];
        int key, index, low, high, flag, location, array_Size;

        System.out.println("Enter the size of the array: ");
        array_Size = s.nextInt();
        System.out.println("Enter the elements of the array: ");
        for (int i = 0; i < array_Size; i++) {
            sorted_Array[i] = s.nextInt();
        }
 
        low = 0;
        location = -1;
        high = array_Size - 1;
        flag = 0;

        System.out.println("Enter the element which is to be searched: ");
        key = s.nextInt();
        s.close();

        index = 0;
        while (flag != 1 && low <= high) {
            index = getFibanociNumber(array_Size);
            if (key == sorted_Array[index + low]) {
                location = low + index;
                flag = 1;
                break;
            }
            else if (key > sorted_Array[index + low]){ 
                low = low + index + 1;
            } 
            else {
                high = low + index - 1;
            }
            array_Size = high - low + 1;
        }
        if (flag == 1){
            location += 1;
            System.out.println("The given element " + key + " found at location " + location + " ");
        }
        else {
            System.out.println("The given element " + key + " is not present in the given array");
        }
    }
}

/*TEST CASES

   Enter the size of the array: 10 
   Enter the elements of the array: -15 0 9 14 23 35 49 52 65 77 
   Enter the element which is to be searched: 52 
   The given element 52 found at location 8

  COMPLEXITY
  Time complexity O(log n) 
  Space Complexity O(1)
 */

