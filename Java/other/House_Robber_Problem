class Solution {
    public int rob(int[] nums) {
        int len=nums.length;
        if(len==0)
            return 0;
        else if(len==1)
            return nums[0];
        else if(len==2)
            return Math.max(nums[0],nums[1]);
        else
        {
            int[] helper=new int[len];
            helper[0]=nums[0];
            helper[1]=Math.max(nums[0],nums[1]);
            for(int i=2;i<len;i++)
                helper[i]=Math.max(nums[i]+helper[i-2],helper[i-1]);
            return helper[len-1];
        }
    }
}

//Time Complexity - O(n) for the one-time traversal of array.
//Space Complexity - O(1) Since no extra space is required.

//Input: nums = [1,2,3,1]
//Output: 4
//Explanation: Rob House1 and House3

//Input: nums = [2,7,9,3,1]
//Output: 12
//Explanation: Rob House1, House3 and House5
