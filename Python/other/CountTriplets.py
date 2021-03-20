# Count all triplets such that sum of two elements equals the third element.
def find_triplets(arr):
    arr.sort()
    count = 0
    ptr_1 = len(arr) - 1
    while ptr_1 >= 2:
        ptr_2 = 0
        ptr_3 = ptr_1 - 1
        while ptr_2 < ptr_3:
            if arr[ptr_1] == arr[ptr_2] + arr[ptr_3]:
                count += 1
                ptr_2 += 1
                ptr_3 -= 1
            elif arr[ptr_1] > arr[ptr_2] + arr[ptr_3]:
                ptr_2 += 1
            else:
                ptr_3 -= 1
        ptr_1 -= 1
    return count

# Driver code
arr = [int(item) for item in input("Enter the list elements : ").split()]
print('Total number of found triplets : {}'.format(find_triplets(arr)))

'''
SAMPLE I/O:

Input: Enter the array elements : 1 4 3 5 7
Output: Total number of found triplets : 3

Time Complexity : O(n^2)
'''
