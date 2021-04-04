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

def updateGap(gap):
    gap = int((gap * 10)/13)
    if gap < 1:
        return 1
    else:
        return gap

# function to sort arr[] using Comb Sort
def combSort(arr, n):

    gap = n

    # Initialize swapped as true to make sure that the loop runs
    swapped = True

    # Keep running while gap is more than 1
    while gap !=1 or swapped == 1:

        # Update gap value
        gap = updateGap(gap)
        swapped = False

        # Compare all elements with current gap
        for i in range(0, n - gap):
            if arr[i] > arr[i + gap]:
                arr[i], arr[i + gap] = arr[i + gap], arr[i]
                swapped = True

    return arr

a = int(input("Enter the number of elements in the array: "))
li = []
for i in range(0, a):
    li.append(int(input('Enter the element one at a time: ')))

print('The unsorted array you have given is:', li)
print('The sorted array using combsort method is: ', end="")
print(combSort(li, len(li)))

"""
Sample input:
Enter the number of elements in the array: 5
Enter the element one at a time: 7
Enter the element one at a time: 3
Enter the element one at a time: 9
Enter the element one at a time: 2
Enter the element one at a time: 12

Sample output:
The unsorted array you have given is: [7, 3, 9, 2, 12]
The sorted array using combsort method is: [2, 3, 7, 9, 12]
"""
