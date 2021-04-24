/* 

3 Sum problem

For a given array nums[], your task is to find the triplets  
whose sum add up to the target value given. 
The output is the triplet of the numbers which add up to target. 
For example:- 
if A + B + C = target then the output will be A, B, C. 
It is given that all the sets of triplets should be unique. 

*/  

import java.util.Scanner; 
import java.util.Arrays; 
import java.util.ArrayList; 
import java.util.List; 

class three_Sum_problem 
{ 
    //method for printing triplet 
    public List<Integer[]> threeSum(int nums[], int target) 
    { 
        Set<List<Integer[]>> tripletEvaluated = new Hashset<>(); 

        //if the array has no elements then we simpliy return  
        //empty list 
        if(nums.length == 0) 
            return new ArrayList<>(tripletEvaluated); 

        //else 
        Arrays.sort(nums); 

        //using two pointer approach 
        for(int i=0; i<nums.length; i++) 
        { 
            int leftptr = i + 1; 

            int rightptr = nums.length - 1; 

            while(leftptr < rightptr)
            { 
                int complement = target - num[i]; 

                int sum = nums[leftptr] + nums[rightptr]; 

                if(sum == complement) 
                { 
                    tripletEvaluated.add(Arrays.asList(nums[i], nums[leftptr], nums[rightptr])); 
                    leftptr++; 
                    rightptr--; 
                } 

                else if(sum > complement) 
                { 
                    rightptr--; 
                } 

                //else if sum < complement 
                else 
                { 
                    leftptr++; 
                } 
            } 
        } 
        return new ArrayList<>(tripletEvaluated); 
    } 

    //driver method 
    public static void main(String []args) 
    { 

        Scanner sc = new Scanner(System.in); 

        System.out.println("Enter the size of the array: "); 
        int size = sc.nextInt(); 

        System.out.println("Enter the target value: "); 
        int target = sc.nextInt();

        int nums[] = new int[size]; 
        System.out.println("Enter the elements of array: "); 
        for(int i = 0; i < size; i++) 
        { 
            nums[i] = sc.nextInt(); 
        } 

        List<Integer[]> tripletEvaluated = threeSum(nums, target); 

        System.out.println("The triplet values are: "); 
        for(Integer[] triplets: tripletEvaluated) { 
        for(int numb: triplets) 
        { 
            System.out.print(numb + " "); 
        } 
            System.out.println(); 
        } 
    } 
} 

/* 

EXAMPLES:- 

Example 1: 
Input-- 
Enter the size of the array: 6 
Enter the target value: 0 
Enter the elements of array: 1 2 -1 0 -2 1 
Output-- 
The triplet values are: [1, -1, 0] 
                        [2, 0, -2] 
                        [1, 1, -2] 

Example 2: 
Input-- 
Enter the size of the array: 0 
Enter the target value: 0 
Enter the elements of array: 0 
Output-- 
The triplet values are: 0 

Example 3: 
Input-- 
Enter the size of the array: 5 
Enter the target value: 0 
Enter the elements of array: 1 -1 -1 0 1 
Output-- 
The triplet values are: [1, -1, 0] 

TIME COMPLEXITY --> O(N^2) 

*/ 
