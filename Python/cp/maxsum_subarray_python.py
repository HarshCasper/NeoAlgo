
# Returns sum of maxium sum subarray in arr[l..h]
def maxSumSubArray(arr, l, h) :

    # Base Case
    if (l == h) :
        return arr[l]
    # Find middle element
    m = (l + h) // 2

    # Return maximum of left ,right and mid crossing
    return max(maxSumSubArray(arr, l, m),
               maxSumSubArray(arr, m+1, h),
               maxSumCrossing(arr, l, m, h))

# Find the maximum possible sum in arr[] such that arr[m] is part of it
def maxSumCrossing(arr, a, m, h) :

    # Include elements on left of mid.
    sm = 0; left_sum = -10000

    for i in range(m, a-1, -1) :
        sm = sm + arr[i]

        if (sm > left_sum) :
            left_sum = sm


    # Include elements on right of mid
    sm = 0; right_sum = -1000
    for i in range(m + 1, h + 1) :
        sm = sm + arr[i]

        if (sm > right_sum) :
            right_sum = sm


    # Return sum of elements on left and right of mid returning only left_sum + right_sum will fail for [-2, 1]
    return max(left_sum + right_sum, left_sum, right_sum)

# Driver Code
# creating an empty list
lst = []

# number of elemetns as input
n = int(input("Enter number of elements in arr : "))

# iterating till the range
for i in range(0, n):
    ele = int(input())
    lst.append(ele) # adding the element

print("input array is : "lst)
n = len(lst)
max_sum = maxSumSubArray(lst, 0, n-1)
print("Maximum contiguous sum is ", max_sum)
