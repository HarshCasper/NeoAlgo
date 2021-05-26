/*
Problem statement:
Given an integer array, we need to display a new array 
such that array[index] is equal to the product of all the 
elements of the array except array[index].
*/

class Solution {
    public static int[] productExceptSelf(int[] nums) {
      
        //find the product of all elements of the matrix
        int product = 1; 
        for(int index=0;index<nums.length;index++){
            product = product*nums[index];
        }
        
        //case when product 0
        //if product=0, find the index that has 0 element
        int zeroindex=0;
        if(product==0){
            for(int index=0;index<nums.length;index++){
                if(nums[index]==0){
                    zeroindex=index;
                }
            }
        
            //find the new product excluding 0 element  
            int newproduct=1;
        
            for(int index=0;index<nums.length;index++){
                if(index!=zeroindex){
                    newproduct = newproduct*nums[index];
                }
            }
        
            for(int index=0;index<nums.length;index++){
                if(index==zeroindex){
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
        System.out.println("Enter length of array: ");
        int n = sc.nextInt();
        int nums[] = new int[n];
        System.out.println("Enter the array elements: ");
        for(int index=0;index<n;index++){
            nums[index]=sc.nextInt();
        }
        
        int[] result = new int[n];
        result = productExceptSelf(nums);
        System.out.print("The array of product except self is: ");
        for(int i=0;i<n;i++){
            System.out.print(result[i]+" ");
        }
        
    }
}
/*
EXAMPLES:

INPUT:
Enter length of array: 2
Enter the array elements: 4 2

OUTPUT:
The array of product except self is: 2 4 

INPUT:
Enter length of array: 3
Enter the array elements: 1 0 4

OUTPUT:
The array of product except self is: 0 4 0 

Time complexity: O(n)
Space complexity: O(n)
*/
