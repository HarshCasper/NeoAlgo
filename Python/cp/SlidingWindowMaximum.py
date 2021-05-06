"""
Author: Guru Charan

Problem statement:
Given a list of integers "nums" and an integer k, return the maximum values
of each sublist of length k.

Constraints:
1 ≤ n ≤ 100,000 where n is the length of "nums".
1 ≤ k ≤ 100,000.

"""

from collections import deque


def findMaxInSubarray(nums, n , k) :

    '''
    paramaters:
    nums: input array
    n: size of the array
    k: window size
    output:
    returns a list (ans) containing the maximum of each window of size k

    '''
    ans = []

    # indices are stored in 'window'
    # with the maximum element at the front
    window = deque()

    # first k elements
    for i in range(k):

        # pop all the elements that are smaller than the current
        # element which are present towards its left (lower indices)
        while (window and (nums[i] >= nums[window[-1]])):
            window.pop()
        # adding the current element
        window.append(i)

    # storing the current answer
    ans.append(nums[window[0]])

    # getting the answer for rest of he array

    for i in range(k, n):

        # checking the window bounds
        if window[0] <= i-k:
            # remove an element from front
            window.popleft()
        while (window and nums[window[-1]] <= nums[i]):
            window.pop()
        window.append(i)
        # storing answer for current window
        ans.append(nums[window[0]])
    # returning the answer
    return ans


# DRIVER CODE

if __name__ == "__main__":

    size = int(input('enter the size of the array : '))

    numsArr = [int(i) for i in input('enter the elements of the array : ').split()]

    windowLen = int(input('enter the size of the window : '))

    print('The maximum values of each subarray of length k : ')
    print(*findMaxInSubarray(numsArr, size, windowLen))

ProblemDetails = '''Time Complexity
O(n) is the overall time complexity of the algorithm
O(k) is the overall space complexity of the algorithm since there can  only be k
elements in the window

Test Cases:

TC-1
Input:
enter the size of the array : 6
enter the elements of the array : 10 5 2 7 8 7
enter the size of the window : 3

Output:
The maximum values of each subarray of length k :
10 7 8 8

TC-2
Input:
enter the size of the array : 9
enter the elements of the array : 1 2 3 4 5 4 3 2 1
enter the size of the window : 3

Output:
The maximum values of each subarray of length k :
3 4 5 5 5 4 3'''
