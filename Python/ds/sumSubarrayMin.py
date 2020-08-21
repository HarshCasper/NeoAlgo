def sum_subarray_mins(A) -> int:
    """"returns the sum of the smallest elements of all sub-arrays"""
    stack = []
    length = len(A)
    left = [-1]*length
    right = [length]*length
    index = 0
    while index < length:
        while stack and A[stack[-1]] > A[index]:
            right[stack.pop()] = index
        else:
            if stack:
                left[index] = stack[-1]
            
        stack.append(index)
        index += 1
    sumi = 0
    for index in range(length):
        sumi += (index - left[index]) * (right[index]-index) * A[index]
    return sumi

arr = list(map(int, input('Enter elements of an array (format- a,b,c..): ').split(',')))
print('Sum of smallest elements of all sub-arrays is: {}' .format(sum_subarray_mins(arr)))
"""
Input format:
Enter elements of an array (format- a,b,c..): 5,7,1,3,8,2

Output format:
Sum of smallest elements of all sub-arrays is: 49

Approach: Before finding the sum, we should know the minimums in all sub-arrays.
For this we will traverse to all numbers of the list and find their left minimum and
right minimum.
    Ex- 3
        we will find out left and right  minimum of number 3 which are-
            1 at index 2
            2 at index 5.
        So, between index 2 and 5, 3 is the smallest no.
        Thereore, sum contribution by 3=> (no. of subarrays) * 3
        where, no. of subarrays = (index of 3 - left min index)*(right min index - index of 3)
        => (3-2) * (5-3) * 3 = 6

Left and right min can be find out by monotonic stack!

Complexity- Time: O(n) n-> length of list
            space: O(n)
contributed by @pradeep98
"""
