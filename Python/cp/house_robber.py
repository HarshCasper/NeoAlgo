'''
The rob function takes an array as input 
and returns total amount that can be robbed. 

'''

def rob(nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    if nums == [] or len(nums) == 0:
        return 0
    elif len(nums) == 1:
        return nums[0]

    runningTotal = [-1, -1]
    runningTotal[0] = nums[0]
    runningTotal[1] = max(nums[0], nums[1])

    for i in range(2, len(nums)):
        runningTotal.append(max([nums[i] + runningTotal[i - 2],
                            runningTotal[i - 1]]))

    return runningTotal[-1]

def main():
    nums = input()

    rob(nums)

main()

# Complexity - 

# Time O(N), 
# Space O(N); N = length of array 

# Sample input/output
#input: nums = [2, 7, 9, 3, 1]
#Output: 12

#input: nums = [1, 2, 3, 1]
#Output: 4

