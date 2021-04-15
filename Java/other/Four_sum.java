/*
Four Sum equal to target

For a given array arr[] consisting of integers,
your task is to return the set of integers of all the unique quadruplets 
such that the sum of those integers is equal to a target value key.
You are asked to provide answer in any order.
i.e. arr[a] + arr[b] + arr[c] + arr[d] == key
and, 0 <= a, b, c, d < arr.length
*/

import java.io.*;
import java.util.*;
import java.lang.*;

class Four_sum
{
    //We approach this problem with two-pointer method
    //function to find sum of four integers
    public List<List<Integer>> 4_Sum(int []arr, int key)
    {
        Arrays.sort(arr);
        return n_Sum(arr, key, 0, 4);
    }

    //function to find sum of n inegers 
    public List<List<Integer>> n_Sum(int []arr, int key, int start, int n)
    {
        List<List<Integer>> result = new ArrayList<>();
        if(start == arr.length || arr[start] * n > key || key > arr[arr.length - 1] * n)
        {
            return result;
        }
        if(n == 2)
        {
            return 2_Sum(arr, key, start);
        }
        for(int pass = start; pass < arr.length; pass++)
        {
            if(pass == start || arr[pass -1] != arr[pass])
            {
                for (var i : n_Sum(arr, key - arr[pass], pass + 1, n - 1)) {
                result.add(new ArrayList<>(Arrays.asList(nums[pass])));
                result.get(result.size() - 1).addAll(i);
            }
        }
        return result;
    }

    //function to find sum of 2 integers
    public List<List<Integer>> 2_Sum(int []arr, int key, int start)
    {
        List<List<Integer>> result = new ArrayList<>();
        //using two-pointer approach
        int leftptr = start;
        int rightptr = arr.length - 1;
        while(leftptr < rightptr)
        {
            int sum = arr[leftptr] + arr[rightptr];
            if(sum < key || (leftptr > start && arr[leftptr] == arr[leftptr - 1]))
            {
                //required number should be greater than current arr[leftptr]
                leftptr++;
            }
            else if(sum > key || (rightptr < arr.length - 1 && arr[rightptr] == arr[rightptr + 1]))
            {
                //required number should be smaller than current arr[rightptr] 
                rightptr--;  
            }
            else
            {
                result.add(Arrays.asList(arr[leftptr++], arr[rightptr--]));
            }
        }  
        return result;
    }

    //driver code
    public static void main(String []args)
    {
        Scanner sc = new Scanner(System.in);

        //taking input array
        System.out.println("Enter the size of array: ");
        int size = sc.nextInt();
        System.out.println("Enter a target value: ")
        int key = sc.nextInt();
        int arr[] = new int[size];
        System.out.println("Enter elements of array: ");
        for (int i=0; i<size; i++) {
            arr[i] = sc.nextInt();
        }

        //for output
        List<Integer[]> quadrupletsEvaluated = 4_Sum(arr, key);
        System.out.println("The quadruplets values are: "); 
        for(Integer[] quadruplets: quadrupletsEvaluated) { 
            for(int numb: quadruplets) 
            { 
                System.out.print(numb + " "); 
            } 
            System.out.println(); 
        } 
    }
}

/*
EXAMPLE:-
Input--
Enter the size of array: 6
Enter a target value: 0
Enter elements of array: 1, 0, -1, 0, -2, 2
Output--
The quadruplets values are: [-2, -1, 1, 2]
                            [-2, 0, 0, 2]
                            [-1, 0, 0, 1]

TIME COMPLEXITY --> O(N^3)
SPACE COMPLEXITY --> O(N) , where N is the number of integers in array.
*/
