class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums ==[] or len(nums) == 0:
            return 0
        elif len(nums) == 1: 
            return nums[0]
        

        runningTotal = [-1,-1]
        runningTotal[0] = nums[0]
        runningTotal[1] = max(nums[0], nums[1])

        for i in range(2, len(nums)):
            runningTotal.append(max([nums[i] + runningTotal[i - 2], runningTotal[i - 1]]))


        return runningTotal[-1]

if __name__ == '__main__':
    nums = [1,2,3,1]
    instance = Solution()
    print(instance.rob(nums))
