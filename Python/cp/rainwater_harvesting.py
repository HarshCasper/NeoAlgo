class Solution(object):
    def trap(self, heights):
            if not heights or len(heights) < 3:
                return 0

            level = water = 0
            i = 0
            j = len(heights) - 1
            while i < j:
                it = heights[i if heights[i] < heights[j] else j]
                if heights[i] < heights[j]:
                    i += 1
                else:
                    j -= 1

                if level > it:
                    water += level - it
                else:
                    level = it
            return water


sol = Solution()
N = int(input("Enter Number of elements: "))
ilist = list(map(int, input("Enter non-negative numbers: ").split()))
print("Maximum units of water saved is " + str(sol.trap(ilist)))

"""
Time Complexity: O(n2)
Space Complexity: O(1)

Sample Input:
Enter Number of elements: 10
Enter non-negative element: 0 2 1 3 0 1 2 1 2 1

Output: Maximum units of water saved is 5
"""
