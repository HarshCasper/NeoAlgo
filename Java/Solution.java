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
