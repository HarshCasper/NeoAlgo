/*
Sum of pairwise bit differences

For a given array arr[] of n integers, your task is to find the sum 
of bit differences in all possible pairs which can be formed out of
the array elements.
Bit difference of a pair (x, y) is the count of differet bits
in two elements at the same position in their binary representation.
*/

import java.io.*;
import java.util.*;

class Pairwise_bitdiff_sum
{
    //function to find the sum of bit difference of all posible pairs 
    static int bitdifferenceSum(int arr[])
    {
        int result = 0;
        //we fix the total number of bits to 32
        for(int pass1 = 0; pass1 < 32; pass1++)
        {
            int countBitdiff = 0;
            for(int pass2 = 0; pass2 < arr.length; pass2++)
            {
                if((arr[pass2] & (1 << pass1)) == 0)
                {
                    countBitdiff = countBitdiff + 1;
                }
            }
            //countBitdiff stands for set i.e. count value 1
            // and arr_length - countBitdiff stands for unset i.e. count value 0
            result = result + (countBitdiff * (arr.length - countBitdiff) * 2);
        }
        return result;
    }

    //driver code
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int size;
        System.out.println("Enter the size of array: ");
        int size = sc.nextInt();
        int arr[] = new int[size];
        System.out.println("Enter the array elements: ");
        for (int i = 0; i < size; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println("Sum of bit difference of all possible pairs made with array is: "+bitdifferenceSum(arr));
        System.out.println(" ");
    }
}

/*
EXAMPLE--
Input-->
Enter the size of array: 3
Enter the array elements: 1, 3, 6
Sum of bit difference of all possible pairs made with array is: 12

TIME COMPLEXITY --> O(N)
SPACE COMPLEXITY --> O(1)
*/
