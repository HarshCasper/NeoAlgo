"""
Merge Sort Algorithm Implementation in Python 3

Purpose:
It works on the principle of Divide and Conquer. Merge sort repeatedly breaks
down a list into several sublists until each sublist consists of a single
element and merging those sublists in a manner that results into a sorted list.

Methodology:
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n)
to hold additional elements from B.
The number of elements initialized in A and B are m and n respectively.

"""

# function merge_sort takes a list and two variables start and end as arguments
def merge_sort(alist, start, end):
    '''
    The function merge_sort will sort the list from indexes start to end – 1 inclusive.
    '''

    #  If end – start is not greater than 1, then return.
    if end - start > 1:
        # Otherwise, set mid equal to the floor of (start + end)/2.
        mid = (start + end)//2

        # Call merge_sort with the same list and with start = start and end = mid as arguments.
        merge_sort(alist, start, mid)

        # Call merge_sort with the same list and with start = mid and end = end as arguments.
        merge_sort(alist, mid, end)

        # Call the function merge_list, passing the list and the variables start, mid and end as arguments.
        merge_list(alist, start, mid, end)


def merge_list(alist, start, mid, end):
    '''
    The function merge_list takes a list and three numbers, start, mid and end
    as arguments and assuming the list is sorted from indexes start to mid – 1
    and from mid to end – 1, merges them to create a new sorted list from
    indexes start to end – 1.
    '''
    left = alist[start:mid]
    right = alist[mid:end]
    k = start
    i = 0
    j = 0
    while (start + i < mid and mid + j < end):
        if (left[i] <= right[j]):
            alist[k] = left[i]
            i = i + 1
        else:
            alist[k] = right[j]
            j = j + 1
        k = k + 1
    if start + i < mid:
        while k < end:
            alist[k] = left[i]
            i = i + 1
            k = k + 1
    else:
        while k < end:
            alist[k] = right[j]
            j = j + 1
            k = k + 1

alist = input('Enter the list of numbers: ').split()
alist = [int(x) for x in alist]
merge_sort(alist, 0, len(alist))
print('Sorted list: ', end='')
print(alist)

'''
Sample Input:
Enter the list of numbers: 5 3 2 1 0

Sample Output:
Sorted list: [0, 1, 2, 3, 5]

Time Complexity:  O(n)
Space Complexity: O(1)
'''
