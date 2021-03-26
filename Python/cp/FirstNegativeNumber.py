'''
Author: Guru Charan
Given an array of numbers, write a program to find the first occurrence
of a negative number in every sublist of size k .
If there is no negative number in that sublist, consider the answer to be 0
for that particular sublist
'''

from collections import deque


def firstNegativeNumber(nums, n, k):

    '''
    Function returns an array of values which correspond to the first negative number in
    each sublist of length k

    nums: array of integers
    n: size of the array
    k:  size of the window

    '''
    # this window will contain the indices of negative numbers
    window = deque()
    # this array/ list will contain the first negative
    # number for each subarray of length k
    ans = []

    # first window
    for i in range(k):
        # adding a number to the window if it is negative
        if nums[i] < 0:
            window.append(i)
    # appending 0 to the answer if the window is empty
    if len(window) == 0:
        ans.append(0)
    else:
        # storing the answer for first window
        ans.append(nums[window[0]])

    for i in range(k, n):

        # removing all the negative numbers which lie outside
        # the current window
        while window and i-k+1 > window[0]:
            window.popleft()
        # adding a number to the window if it is negative
        if nums[i] < 0:
            window.append(i)
        # appending 0 to the answer if the window is empty
        if len(window) == 0:
            ans.append(0)
        else:
            # storing the answer for current window
            ans.append(nums[window[0]])
    return ans

# DRIVER CODE

if __name__ == "__main__":

    size = int(input('enter the size of the array : '))

    numsArr = [int(i) for i in input('enter the elements of the array : ').split()]

    windowLen = int(input('enter the size of the window : '))

    print('The first negative values of each subarray of length k : ')
    print(*firstNegativeNumber(numsArr, size, windowLen))

ProblemDetails = '''
Time Complexity
O(n) is the overall time complexity of the algorithm
O(k) is the overall space complexity of the algorithm since there can  only be k
elements in the window
Test Cases:
TC-1
Input:
enter the size of the array : 5
enter the elements of the array : -8 2 3 -6 10
enter the size of the window : 2
Output:
The first negative values of each subarray of length k :
-8 0 -6 -6

TC-2
Input:
enter the size of the array : 9
enter the elements of the array : 1 -2 3 -4 5 4 -3 2 -1
enter the size of the window : 2
Output:
The first negative values of each subarray of length k :
-2 -2 -4 -4 0 -3 -3 -1
'''
