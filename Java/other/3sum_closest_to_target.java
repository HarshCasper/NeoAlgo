/*

Three sum closest to target

You will be given an array of integers arr[], and a target value
and your task will be to find three such elements whose sum comes
the closest to the target value.
The output will be the sum of the set of three numbers whose sum comes is the
closest to target value.

*/

import java.util.*; 
import java.util.Arrays; 

class 3sum_closest_to_target
{
    //function to find the closest sum
    public int 3sumClosest(int arr[], int target)
    {
        //storing result
        int res = arr[0] + arr[1] + arr[arr.length-1];

        Arrays.sort(arr);

        //using two pinter approach
        for(int i = 0; i<arr.length-2; i++)
        {
            int leftptr = i+1;
            int rightptr = arr.length-1;
            while(leftptr<rightptr)
            {
                int sum = arr[i] + arr[leftptr] + arr[rightptr];
                if(sum > target)
                {
                    rightptr--;
                }
                else {
                    leftptr++;
                }
                if(Math.abs(sum-target) < Math.abs(res-target))
                {
                    res = sum;
                }
            }
        }
        return res;
    }

    //driver method
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in); 

        System.out.println("Enter the size of the array: "); 
        int size = sc.nextInt(); 

        System.out.println("Enter the target value: "); 
        int target = sc.nextInt();

        int arr[] = new int[size]; 
        System.out.println("Enter the elements of array: "); 
        for(int i = 0; i < size; i++) 
        { 
            arr[i] = sc.nextInt(); 
        } 

        System.out.println("Closest sum is: ");
        System.out.print(3sumClosest(arr, target));

    }
}

/* 

EXAMPLES:-

Example 1:
Input--
Enter the size of the array: 4
Enter the target value: 1
Enter the elements of array: 1, -1, -4, 2
Output--
Closest sum is: 2

Example 2:
Input--
Enter the size of the array: 5
Enter the target value: 7
Enter the elements of array: 2, 6, 1, 7, 4
Output--
Closest sum is: 7

Example 3:
Input--
Enter the size of the array: 1
Enter the target value: 1
Enter the elements of array: 0
Output--
Closest sum is: 0

TIME COMPLEXITY --> O(N^2)

*/
