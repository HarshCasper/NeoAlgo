# Fibonacci search implementation in Python3

"""
Purpose:
Fibonacci Search is a comparison-based technique that uses Fibonacci numbers to search an element in a sorted array.

Similarities with binary search:
- worked for sorted arrays
- a divide a conquer algorithm

Return type:
Returns the index of a key in a sorted array or returns -1 if it is not contained
"""

def FibonacciSearch(arr, x, n):
    """
    Inputs-
    arr: A sorted array in which we're going to search for the key
    x: The number to be searched for
    n: Size of the array
    """

    # initialize fibonacci numbers
    m2 = 0  # (m-2)'th Fibonacci No.
    m1 = 1  # (m-1)'th Fibonacci No.
    m = m2 + m1  # m'th Fibonacci

    # m: store the smallest
    # fibonacci Number greater than or equal to n
    while m < n:
        m2 = m1
        m1 = m
        m = m2 + m1

    # marks the eliminated range from front
    offset = -1

    # while there are elements to be inspected.
    # Note: we compare arr[m2] with x.
    # when m becomes 1, m2 becomes 0
    while m > 1:

        # Check if m2 is a valid location
        i = min(offset + m2, n - 1)

        # if x is greater than the value at
        # index m2, cut the subarray array
        # from offset to i
        if arr[i] < x:
            m = m1
            m1 = m2
            m2 = m - m1
            offset = i

        # if x is less than the value at
        # index m2, cut the subarray
        # after i+1
        elif arr[i] > x:
            m = m2
            m1 = m1 - m2
            m2 = m - m1

        # element found. return index
        else:
            return i

    # comparing the last element with x
    if m1 and arr[offset + 1] == x:
        return offset + 1

    # element not found. return -1
    return -1

# taking dynamic input
print("Enter the array in space seperated format: ")
arr = list(map(int, input().split(' ')))
print("Enter the element which is to be searched: ")
x = int(input())
n = len(arr)

# calling function
index = FibonacciSearch(arr, x, n)
if index != -1:
    print("Found at index:", FibonacciSearch(arr, x, n))
else:
    print("Element not found in above listed numbers.")

"""
Sample input:
Enter the array in space seperated format:
10 22 35 40 45 50 80 82 85 90 100
Enter the element which is to be searched:
85

Sample output:
Found at index: 8

Worst case time complexity: O(log n)
Best case time complexity:	O(1)

Space complexity: O(1)
"""
