# Implementation of the Counting Sort algorithm in Python.


def counting_Sort(arr):
    size = len(arr)
    output = [0] * size

    count = [0] * 10

    # Store the count of each elements in count array
    for i in range(0, size):
        count[arr[i]] += 1

    # Store the cummulative count
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Find the index of each element of the original array in count array
    # place the elements in output array
    i = size - 1
    while i >= 0:
        output[count[arr[i]] - 1] = arr[i]
        count[arr[i]] -= 1
        i -= 1

    # Copy the sorted elements into original array
    for i in range(0, size):
        arr[i] = output[i]


lst = [6, 4, 2, 5, 3, 4, 1]
counting_Sort(lst)
print("Sorted arr in Ascending Order: ")
print(lst)

