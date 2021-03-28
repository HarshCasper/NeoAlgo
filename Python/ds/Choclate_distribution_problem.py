# chocolate distribution
# problem

# arr[0..n-1] represents sizes of packets
# m is number of students.
# Returns minimum difference between maximum
# and minimum values of distribution.
def findMinDiff(arr, n, m):


    # if there are no chocolates or number
    # of students is 0
    if (m == 0 or n == 0):
        return 0

    # Sort the given packets
    arr.sort()

    # Number of students cannot be more than
    # number of packets
    if (n < m):
        return -1

    # Largest number of chocolates
    min_diff = arr[n - 1] - arr[0]

    # Find the sub array of size m such that
    # difference between last (maximum in case
    # of sorted) and first (minimum in case of
    # sorted) elements of sub array is minimum.
    for i in range(len(arr) - m + 1):
        min_diff = min(min_diff, arr[i + m - 1] - arr[i])

    return min_diff


# Driver Code
if __name__ == "__main__":
    n1 = int(input("Entre the length of the array "))
    arr1 = []
    for z in range(0, n1):
        x = int(input())
        arr1.append(x)
    k = int(input("Entre number of students "))
    print("Minimum difference is", findMinDiff(arr1, n1, k))

# -------------------------*********************-------------------------
# Time complexity o(n)
# space complexity o(1)

# sample Input
# Entre the length of the array 7
# 1
# 223
# 45
# 12
# 4
# 6
# 7
# Entre number of students 4
# sample output
# Minimum difference is 6
