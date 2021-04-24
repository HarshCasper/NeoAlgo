"""
CombSort Algorithm Implementation in Python 3

Purpose:
Comb sort is a relatively simple sorting algorithm.
Comb sort improves on bubble sort algorithm.
In bubble sort, distance (or gap) between two compared elements is always one.
Comb sort improvement is that gap can be much more than 1, in order to prevent
slowing down by small values at the end of a list.

Time Complexity :
Worst case complexity is O(n^2)
Best Case complexity is O(n log n)

Space Complexity: O(1)

Argument/ Return Type:
arr : Unorded list
output : Return list in ascending order

"""


def combsort(arr, n):

    """
    Pure implementation of comb sort algorithm in Python
    :param data: mutable collection with comparable items
    :return: the same collection in ascending order
    Examples:
    >>> comb_sort([0, 5, 3, 2, 2])
    [0, 2, 2, 3, 5]
    >>> comb_sort([])
    []
    >>> comb_sort([99, 45, -7, 8, 2, 0, -15, 3])
    [-15, -7, 0, 2, 3, 8, 45, 99]

    """

    gap = n
    while gap > 1:
        gap = int(gap / 1.3)
        for i in range(0, n - gap):
            if arr[i] > arr[i + gap]:
                arr[i], arr[i + gap] = arr[i + gap], arr[i]
    return arr


a = int(input("Enter the number of elements in the array: "))
li = []
for i in range(0, a):
    li.append(int(input('Enter the element one at a time: ')))
print('The unsorted array you have given is:', li)
print('The sorted array using combsort method is: ', end="")
print(combsort(li, len(li)))
