#471
#Pthon implementation of Radomised selection Algorithm
"""
Time Complexity:O(n)
Space Complexity:
"""
import random as rand

# This function returns the ith smallest element assuming that the elements are distinct
def ithSmallestElement(arr, l, r, i):
    #Base condion:arr has just one element
    if l==r:
        return arr[l]
    # If k is smaller than number of
    # elements in array
    if (i > 0 and i <= r - l + 1):

        #get position of pivot element in sorted array
        pos = randomPartition(arr, l, r)

        # If position is same as k
        if (pos - l == i - 1):
            return arr[pos]
        if (pos - l > i - 1):  # If position is more
            return ithSmallestElement(arr, l, pos - 1, i)

            # Else recur for right subarray
        return ithSmallestElement(arr, pos + 1, r,
                           i - pos + l - 1)

# swaping without an extra variable
def swap(arr, a, b):
    arr[a] = arr[a] + arr[b]
    arr[b] = arr[a] - arr[b]
    arr[a] = arr[a] - arr[b]

# Standard partition process of QuickSort().
def partition(arr, low, high):
    i = (low - 1)  # index of smaller element
    pivot = arr[high]  # pivot

    for j in range(low, high):

        # If current element is smaller than the pivot
        if arr[j] < pivot:
            # increment index of smaller element
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return (i + 1)

# Picks a random pivot element between l and r for partition of arr
def randomPartition(arr, l, r):
    n = r - l + 1
    pivot = int(rand.random() % n)
    swap(arr, l + pivot, r)
    return partition(arr, l, r)

# Driver Code
if __name__ == '__main__':
    size = int(input("Enter the total number of elements"))
    arr = []
    for i in range(0, size):
        arr.append(int(input("Enter a element")))
    i_pos = int(input("Enter the i'th position"))

    if(ithSmallestElement(arr, 0, size - 1, i_pos) is None):
        print("Please enter a valid i'th position")
    else:
        print("i'th smallest element is",
              ithSmallestElement(arr, 0, size - 1, i_pos))

"""
Testcases that were tested:
Total Number of elements :5 
Elements: [1,2,3,4,5] i'th position: 5
o/p: 5
For the above usecase if i'th position is 6 
o/p: None
"""
