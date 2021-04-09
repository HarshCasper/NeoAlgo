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
    Fibm2 = 0  # (m-2)'th Fibonacci No.
    Fibm1 = 1  # (m-1)'th Fibonacci No.
    Fibm = Fibm2 + Fibm1  # Fibm'th Fibonacci

    # Fibm: store the smallest
    # fibonacci Number greater than or equal to n
    while Fibm < n:
        Fibm2 = Fibm1
        Fibm1 = Fibm
        Fibm = Fibm2 + Fibm1

    # marks the eliminated range from front
    offset = -1

    # while there are elements to be inspected.
    # Note: we compare arr[Fibm2] with x.
    # when Fibm becomes 1, Fibm2 becomes 0
    while Fibm > 1:

        # Check if Fibm2 is a valid location
        i = min(offset + Fibm2, n - 1)

        # if x is greater than the value at
        # index Fibm2, cut the subarray array
        # from offset to i
        if arr[i] < x:
            Fibm = Fibm1
            Fibm1 = Fibm2
            Fibm2 = Fibm - Fibm1
            offset = i

        # if x is less than the value at
        # index Fibm2, cut the subarray
        # after i+1
        elif arr[i] > x:
            Fibm = Fibm2
            Fibm1 = Fibm1 - Fibm2
            Fibm2 = Fibm - Fibm1

        # element found, return index
        else:
            return i

    # comparing the last element with x
    if Fibm1 and arr[offset + 1] == x:
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
