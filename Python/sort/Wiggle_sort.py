"""
To get wiggle sort, 
you want to put the number in the following way such that:
 
(1) elements smaller than the 'median' are put into the last even slots. 
(2) elements larger than the 'median' are put into the first odd slots. 
(3) the medians are put into the remaining slots.

Purpose: Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Time Complexity: O(nlogn)
Space Complexity: O(n)
"""

"""
Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

Sorting and reorder solution. (92ms)
"""

class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        nums.sort()
        med = (len(nums) - 1) / 2
        nums[::2], nums[1::2] = nums[med::-1], nums[:med:-1]

"""
Time Complexity:  O(n) ~ O(n^2)
Space Complexity: O(1)

Tri Partition with virtual index solution.
"""

from random import randint
class Solution2(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        def findKthLargest(nums, k):
            left, right = 0, len(nums) - 1
            while left <= right:
                pivot_idx = randint(left, right)
                new_pivot_idx = partitionAroundPivot(left, right, pivot_idx, nums)
                if new_pivot_idx == k - 1:
                    return nums[new_pivot_idx]
                elif new_pivot_idx > k - 1:
                    right = new_pivot_idx - 1
                else:  # new_pivot_idx < k - 1.
                    left = new_pivot_idx + 1
            
        def partitionAroundPivot(left, right, pivot_idx, nums):
            pivot_value = nums[pivot_idx]
            new_pivot_idx = left
            nums[pivot_idx], nums[right] = nums[right], nums[pivot_idx]
            for i in xrange(left, right):
                if nums[i] > pivot_value:
                    nums[i], nums[new_pivot_idx] = nums[new_pivot_idx], nums[i]
                    new_pivot_idx += 1
            nums[right], nums[new_pivot_idx] = nums[new_pivot_idx], nums[right]
            return new_pivot_idx

        def reversedTriPartitionWithVI(nums, val):
            def idx(i, N):
                return (1 + 2 * (i)) % N

            N = len(nums) / 2 * 2 + 1
            i, j, n = 0, 0, len(nums) - 1
            while j <= n:
                if nums[idx(j, N)] > val:
                    nums[idx(i, N)], nums[idx(j, N)] = nums[idx(j, N)], nums[idx(i, N)]
                    i += 1
                    j += 1
                elif nums[idx(j, N)] < val:
                    nums[idx(j, N)], nums[idx(n, N)] = nums[idx(n, N)], nums[idx(j, N)]
                    n -= 1
                else:
                    j += 1

        mid = (len(nums) - 1) / 2
        findKthLargest(nums, mid + 1)
        reversedTriPartitionWithVI(nums, nums[mid])

"""
Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.
"""
