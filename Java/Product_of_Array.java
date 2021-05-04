/*
This Program use an array  of n integers, construct a Product Array (of same size) 
such that prod is equal to the product of all the elements of arr except itself
*/

import java.util.*;   

class Main {
    public static int[] productExceptSelf(int[] nums) 
    {
        //find the product of all elements of the matrix
        int product = 1; 
        for(int index=0;index<nums.length;index++)
        {
            product = product*nums[index];
        }

        //case when product 0
        //if product=0, find the index that has 0 element
        int zeroindex=0;
        if(product==0)
        {
            for(int index=0;index<nums.length;index++)
            {
                if(nums[index]==0)
                {
                    zeroindex=index;
                }
            }

            //find the new product excluding 0 element  
            int newproduct=1;

            for(int index=0;index<nums.length;index++)
            {
                if(index!=zeroindex)
                {
                    newproduct = newproduct*nums[index];
                }
            }

            for(int index=0;index<nums.length;index++)
            {
                if(index==zeroindex)
                {
                    nums[index]=newproduct;
                }else{
                    nums[index]=0;            
                    }
                }

                return nums;
            }

            //case when product not zero
            for(int i=0;i<nums.length;i++){
                nums[i]=product/nums[i];
            }

            return nums;
        }

    //main method
   public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int nums[] = new int[n];
        for(int index=0;index<n;index++){
            nums[index]=sc.nextInt();
        }

        int[] result = new int[n];

        result = productExceptSelf(nums);

        for(int i=0;i<n;i++){
            System.out.print(result[i]+" ");
        }

    }
}

/*
INPUT:-
5
1 2 3 4 5
OUTPUT:-
120 60 40 30 24 
*/

/*
Time Complexity :- O(n)
Space Complexity :- O(n)
*/