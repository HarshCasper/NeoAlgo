# Python Code for Heap Sorting
# Python3 program to demonstrate working of heapq
from heapq import heappush, heapify

# function for maxHeap


def maxHeap(arr, size):
    # Creating empty maxheap
    maxheap = []
    heapify(maxheap)

    # Adding items to the heap using heappush
    # function by multiplying them with -1

    for i in range(0, size):
        heappush(maxheap, -1 * arr[i])
    # printing the value of maximum element
    print("Head value of Maxheap : " + str(-1 * maxheap[0]))

    # printing the elements of the heap
    print("The Maxheap elements : ")
    for i in maxheap:
        print(-1 * i, end=" ")
    print("\n")


# function for minHeap
def minHeap(arr, size):
    # Creating empty minheap
    minheap = []
    heapify(minheap)

    # Adding items to the heap using heappush
    # function by multiplying them with -1

    for i in range(0, size):
        heappush(minheap, arr[i])
    # printing the value of maximum element
    print("Head value of Minheap : " + str(minheap[0]))

    # printing the elements of the heap
    print("The Minheap elements : ")
    for i in minheap:
        print(i, end=" ")
    print("\n")


# Driver Code
print("Input-->")
print("Enter the size of heap:")
size = int(input())
li = []
print("Enter the elements of list:")
for i in range(0, size):
    ele = int(input())
    # adding the element
    li.append(ele)
print("Output-->\n")
maxHeap(li, size)
minHeap(li, size)
"""
Input-->
Enter the size of heap:
3
Enter the elements of list:
15
12
56
Output-->
Head value of Maxheap : 56
The Maxheap elements : 56 12 15
Head value of Minheap : 12
The Minheap elements : 12 15 56
Time Complexity : O(n log n)
 Space Complexity : O(1)
"""
