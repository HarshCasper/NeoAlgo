
# Given two sorted arrays nums1 and nums2 of size m and n
# respectively, return the median of the two sorted arrays.  

# function to find median of two arrays
def findMedianSortedArrays(nums1, nums2):
    newlist = sorted(nums1 + nums2)

    # checking if length of merged array is even
    if len(newlist) % 2 != 1:
        first = newlist[len(newlist) // 2]
        second = newlist[len(newlist) // 2 - 1]
        return (first + second) / 2

    # checking if length of merged array is odd
    if len(newlist) % 2 == 1:
        return newlist[len(newlist) // 2]

# Driver's code
if __name__ == "__main__":
    # creating an empty lists
    nums1 = []
    nums2 = []
    n = int(input('Enter length of first array: '))
    m = int(input('Enter length of second array: '))

    nums1 = list(map(int,input("\nEnter elements of first array: ").strip().split()))[:n]
    nums2 = list(map(int,input("\nEnter elements of second array: ").strip().split()))[:m]

    print('Median of two arrays is: ' +
        str(findMedianSortedArrays(nums1, nums2)))

# Time Complexity: O(n)
# Space Complexity: O(n)

# Example 1:

# Input:
# Enter length of first array:
# 2
# Enter length of second array:
# 1
# Enter the elements of first array:
# 1 3
# Enter the elements of second array:
# 2

# Output:
# Median of two arrays is: 2.00000

# Example 2:

# Input:
# Enter length of first array:
# 5
# Enter length of second array:
# 3
# Enter the elements of first array:
# 1 5 6 7 8
# Enter the elements of second array:
# 2 4 4

# Output:
# Median of two arrays is: 4.50000
