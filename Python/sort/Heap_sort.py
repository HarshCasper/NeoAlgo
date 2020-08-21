# Heap Sort in python

def heapify(arr, n, i):
    # Find largest among root and children
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2

    if l < n and arr[i] < arr[l]:
        largest = l

    if r < n and arr[largest] < arr[r]:
        largest = r

    # If root is not largest, swap with largest and continue heapifying
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heapSort(arr):
    n = len(arr)

    # Build max heap
    for i in range(n//2, -1, -1):
        heapify(arr, n, i)

    for i in range(n-1, 0, -1):
        # Swap
        arr[i], arr[0] = arr[0], arr[i]

    # Heapify root element
        heapify(arr, i, 0)

arr = [int(input()) for i in range(int(input("Enter elements to be sorted : ")))] 
heapSort(arr)
n = len(arr)
print("Sorted array:")
for i in range(n):
    print("%d " % arr[i], end='')
    
'''
Sample Output:

Enter elements to be sorted : 8
5
4
9
82
65
79
97
25
Sorted array is
4 5 9 25 65 79 82 97 
'''
