"""
Tim Sort Algorithm implementation in Python3

Introduction:
TimSort is a sorting algorithm that is a hybrid of merge sort and
binary insertion sort algorithm. It is a stable algorithm and works
best on real-time data. In this, the list that needs to be sorted
is first analyzed, and based on that it is divided into blocks known
as Run. These runs are sorted using insertion sort one by one and
then by merging these runs using the combine function used in merge
sort. If the size of the Array is less than run, then Array gets
sorted just by using Insertion Sort. The size of the run may vary
from 32 to 64 depending upon the size of the array. Note that the
merge function performs well when size subarrays are powers of 2.
"""

MIN_MERGE = 32
MAX_MERGE = 64

# This function searches for the index where we can insert the key


def binarySearch(arr, left, right, key):
    # If there is only 1 element
    if left == right:
        if arr[left] > key:
            return left
        else:
            return left+1

    # If we have searched in the whole array
    if left > right:
        return left

    # The middle index
    mid = (left + right - 1) // 2

    if arr[mid] <= key:
        if mid + 1 == right:
            return mid + 1
        return binarySearch(arr, mid + 1, right, key)
    elif arr[mid] > key:
        return binarySearch(arr, left, mid - 1, key)


# This function sorts runs using binary search
def InsertionSort(arr):
    """
    Returns the sorted run in place using binary search to find 
    the index where the element can be inserted.
    """
    # Initialise the left ans=d right index
    left, right = 0, len(arr) - 1

    # Intialise the key element
    key = arr[-1]

    # Binary Search to the find the index for key
    idx = binarySearch(arr, left, right, key)

    # shifting the elements to the right
    for i in range(right, idx, -1):
        arr[i] = arr[i-1]

    # Insert the key
    arr[idx] = key

    return arr


# This function returns the length of sorted run
def calcSize(arr, start):
    """
    Returns the length of a run from 32 - 64 to divide runs in a "natural" size 
    - the size of initial runs are not in a fixed number, but have a minimal 
    size requirement - "MIN_MERGE" and maximal size - "MAX_MERGE".
    """
    # To check if the sequence is decreasing or not
    descending = False

    # Size of the sorted run
    n = 1

    # If array[start:] contains a single value
    if len(arr[start:]) == 1:
        return n

    # If the intial 2 elements are decreasing
    if arr[start+n] < arr[start+n-1]:
        descending = True
    n += 1

    # size of run to be less than MAX_MERGE
    while n < MAX_MERGE:

        # If the pointer reaches the end of array
        if len(arr) - start < MIN_MERGE:

            # If the run is sorted in decreasing order, reverse it
            # and return the length
            if descending:
                arr[start:start+n] = reversed(arr[start:start+n])
            return n

        # If the sequence is in decreasing order
        elif descending:
            if arr[start+n] < arr[start+n-1]:
                n += 1

            else:
                # If the length of run > minimal size, reverse it
                # and return the length
                if n >= MIN_MERGE:
                    arr[start:start+n] = reversed(arr[start:start+n])
                    return n

                else:
                    # reverse the sequence to convert it in increasing order
                    arr[start:start+n] = reversed(arr[start:start+n])
                    descending = False

                    n += 1
                    # sort the elements using binary insertion sort
                    arr[start: start+n] = InsertionSort(arr[start: start+n])

        # If the sequence is in Increasing order
        else:
            if arr[start+n] >= arr[start+n-1]:
                n += 1
            else:
                # If the length of run > minimal size, return the length
                if n >= MIN_MERGE:
                    return n

                else:
                    n += 1
                    # sort the elements using binary insertion sort
                    arr[start: start+n] = InsertionSort(arr[start: start+n])

    # If the run is sorted in decreasing order, reverse it
    if descending:
        arr[start:start+n] = reversed(arr[start:start+n])

    # return the length of sorted run
    return n


# Merge function to merge two sorted runs inplace
def merge(arr, start1, start2, end2):
    """
    Input : 
    Take Starting and Ending indices of 2 sorted runs and merge them (similar to merge sort) 
    The function merges the sorted runs inplace to reduce the space complexity in merging.
    """
    # last index of the first sorted run
    end1 = start2 - 1

    # If the direct merge is already sorted
    if (arr[end1] <= arr[start2]):
        return

    # Two pointers to maintain start of both runs to merge
    while (start1 <= end1 and start2 <= end2):

        # If element 1 is in right place
        if (arr[start1] <= arr[start2]):
            start1 += 1
        else:
            value = arr[start2]
            index = start2

            # Shift all the elements between element 1
            # element 2, right by 1.
            while (index != start1):
                arr[index] = arr[index - 1]
                index -= 1

            arr[start1] = value

            # Update all the pointers
            start1 += 1
            end1 += 1
            start2 += 1


# Iterative Timsort function to sort the array[0...n-1] in an efficient way
def timSort(arr):
    """
    This function divides the array into subarrays (RUNs) and sort every "RUN"
    elements by binary Insertion Sort and then merge the sorted runs similar 
    to merging in Merge Sort.
    """
    # length of the array
    n = len(arr)

    # List to store the starting index and size of each run
    runs = []

    while (n):
        # Starting index for that run
        startIndex = len(arr) - n

        # Size of that run
        size = calcSize(arr, startIndex)

        # Size of Remaining unsorted array
        n -= size

        # Update starting index and size of the sorted run
        runs.append((startIndex, size))

    # To iterate over all the sorted runs and merge them inplace
    for i in range(len(runs)-1):

        # Merge function to merge run[i] with run[i+1]
        merge(arr, runs[i][0], runs[i+1][0], sum(runs[i+1])-1)

        # Update the size of resulting sorted run
        runs[i+1] = (0, runs[i][1] + runs[i+1][1])


"""
Sample input:
Enter the array elements seperated by space: 13 7 2 1 11 17 15 18 6 17 13 12 9 8 3 5 1

Sample output:
The sorted array using Tim Sort Algorithm:
1 1 2 3 5 6 7 8 9 11 12 13 13 15 17 17 18

Best case time complexity: O(n)
Average case time complexity: O(nlog(n))
Worst case time complexity: O(nlog(n))
Space complexity: O(n)
"""

# Driver program to run TimSort Algorithm


def main():
    # To enter the array elements from the user
    arr = list(
        map(int, input("Enter the array elements seperated by space: ").split()))

    timSort(arr)
    print("The sorted array using Tim Sort Algorithm:\n", *arr)


if __name__ == '__main__':
    main()

"""
The in-built sort() function of Python uses similar algorithm to 
provides a stable sorting approach. It is faster than other 
sorting algorithms and can be directly implemented in python using 
the sort() method.
"""