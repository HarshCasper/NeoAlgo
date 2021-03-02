# Program to merge two arrays in a single array

# function to perform arrays merge operation

def mergearray(array1, array2, size1, size2):

    i = size1 - 1
    j = 0

    # iterating through first array from the end and the second array from
    # start
    while i >= 0 and j < size2:

        # swap if number in 1st array is greater than 2nd array
        if array1[i] > array2[j]:
            temporary = array1[i]
            array1[i] = array2[j]
            array2[j] = temporary
        i = i - 1
        j = j + 1

    # sorting both the arrays to get the final result
    array1.sort()
    array2.sort()
    print("Array after merge:")
    for i in range(size1):
        print(array1[i], end=' ')
        i = i + 1
    for i in range(size2):
        print(array2[i], end=' ')
        i = i + 1

size1 = int(input('Enter size of 1st array:'))
print('Enter elements of array 1: ')
array1 = list(map(int, input().split()))

size2 = int(input('Enter size of 2nd array: '))
print('Enter elements of array 2: ')
array2 = list(map(int, input().split()))
mergearray(array1, array2, size1, size2)

'''
Sample I/O:

    Input:

    Enter size of 1st array:3
    Enter elements of array 1:
    1 2 3
    Enter size of 2nd array: 2
    Enter elements of array 2:
    1 2

    Output:

    Array after merge:
    1 1 2 2 3

Time Complexity: O(NlogN)(where N will be max of size1 and size2)
Space Complexity: O(1)
'''
