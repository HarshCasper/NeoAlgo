# Python program for implementation of heap Sort

# To heapify subtree rooted at index.
# length is size of heap

def heapify(arr, length, index):
    # base case
    # we will call this function until the largest number is the index...
    largest_num_index = index
    left_index = (index * 2) + 1
    right_index = (index * 2) + 2

    if(left_index < length and arr[index] < arr[left_index]):
        largest_num_index = left_index

    if(right_index < length and arr[largest_num_index] < arr[right_index]):
        largest_num_index = right_index

    # if index is not the largest, make it the largest!
    # and run it again!
    if(largest_num_index != index):
        arr[index], arr[largest_num_index] = arr[largest_num_index], arr[index]
        heapify(arr, length, largest_num_index)


def heap_sort(arr):
    # need array length to create indices
    length = len(arr)

    for index in range(length, -1, -1):
        # ask about functions modifying arrays without return value
        # build max heap
        heapify(arr, length, index)

    # for each sorted heap, swap the root and the last number
    for index in range(length - 1, 0, -1):
        arr[index], arr[0] = arr[0], arr[index]
        # then call heapify again with the new array
        heapify(arr, index, 0)


# Taking Elements to be Sorted
data = [int(input())
        for index in range(int(input("Enter elements to be sorted : ")))]
# Sending element to get sorted
heap_sort(data)
# Priting Elements after Getting Sorted
print(data)

'''
Sample Output:
Enter elements to be sorted : 5
30
50
10
20
40
[10, 20, 30, 40, 50]

Building the max heap requires O(n) calls to the buildHeap function which
takes O(log n) time to build the max heap
Therefore, total time complexity = O(nlog n)
In heap sort since we are only keeping data in the array and only
rearranging it so no data needs to be stored anywhere else (other than the swap step)
So, space complexity = O(1)
'''
