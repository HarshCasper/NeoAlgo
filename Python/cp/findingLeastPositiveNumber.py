# finding least positive number
# Given an array of integers, find the first missing positive integer in
# linear time and constant space.In other words,
# find the lowest positive integer that does not exist in the array.
# The array can contain duplicates
# and negative numbers as well.
# code contributed by devanshi katyal
# space complexity:O(1)
# time complexity:O(n)


def MainFunction(arr, size):
    for i in range(size):
        if (abs(arr[i]) - 1 < size and arr[abs(arr[i]) - 1] > 0):
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1]
    for i in range(size):
        if (arr[i] > 0):
            return i + 1
    return size + 1


def findpositive(arr, size):
    j = 0
    for i in range(size):
        if (arr[i] <= 0):
            arr[i], arr[j] = arr[j], arr[i]
            j += 1
    return MainFunction(arr[j:], size - j)
arr = list(map(int, input().split(" ")))
# sample input= [-1, 2, 4,3 , 0]
print("the smallest missing positive number is", findpositive(arr, len(arr)))
# output: the smallest missing positive number is 1
