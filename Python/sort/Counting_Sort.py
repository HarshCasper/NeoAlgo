# Implementation of the Counting Sort algorithm in Python.

# Worst complexity: n+r
# Average complexity: n+r
# Space complexity: n+r
# Stable: Yes
# Class: Non-comparison sort
# Data structure: Array


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

# Taking input
n = int(input("Enter length of array (n): "))

lst = []
print("Enter the Array (values has to be smaller than (n)): ")
for _ in range(n):
    lst.append(int(input()))

counting_Sort(lst)
print("Sorted array in Ascending Order: ")
print(lst)

"""
____Example 1____
Enter length of array (n): 6                                                                                                       
Enter the Array (values has to be smaller than (n)):                                                                                
4                                                                                                                                  
5                                                                                                                                  
3                                                                                                                                  
1                                                                                                                                  
2                                                                                                                                  
5                                                                                                                                  
Sorted array in Ascending Order:                                                                                                   
[1, 2, 3, 4, 5, 5]

____Example 2____
Enter length of array (n): 8                                                                                                       
Enter the Array (values has to be smaller than (n)):                                                                                
3                                                                                                                                  
6                                                                                                                                  
7                                                                                                                                  
5                                                                                                                                  
2                                                                                                                                  
4                                                                                                                                  
1                                                                                                                                  
5                                                                                                                                  
Sorted array in Ascending Order:                                                                                                   
[1, 2, 3, 4, 5, 5, 6, 7] 
"""