'''
INTRO SORT
Introsort sort is a sorting algorithm that initially uses quicksort, 
but switches to heap sort if the depth of the recursion is too deep,
and uses insertion sort for small cases.

Time Complexity:
Worst-case performance: O(nlogn)
Average-case performance: O(nlogn)
'''

#A function that takes a list as argument.
def introsort(alist): 
    
    #maxdepth is chosen equal to 2 times floor of log base 2 of the length of the list.
    maxdepth = (len(alist).bit_length() - 1 ) * 2
    # Call introsort_helper with start = 0 and end = len(blist).
    introsort_helper(alist, 0, len(alist), maxdepth)
 
#The function sorts the list from indexes start to end. 
def introsort_helper(alist, start, end, maxdepth):
    if end - start <= 1:
        return
    elif maxdepth == 0:
        heapsort(blist, start, end)
    else:
        p = partition(alist, start, end)
        introsort_helper(alist, start, p + 1, maxdepth - 1)
        introsort_helper(alist, p + 1, end, maxdepth - 1)
 
#Partition function uses Hoare partition scheme to partition the list. 
def partition(alist, start, end):
    pivot = alist[start]
    i = start - 1
    j = end
 
    while True:
        i = i + 1
        while alist[i] < pivot:
            i = i + 1
        j = j - 1
        while alist[j] > pivot:
            j = j - 1
 
        if i >= j:
            return j
 
        swap(alist, i, j)

#Function for swapping particular elements of a list
def swap(alist, i, j):
    alist[i], alist[j] = alist[j], alist[i]

#Heapsort from indexes start to end - 1 
def heapsort(blist, start, end):
    build_max_heap(alist, start, end)
    for i in range(end - 1, start, -1):
        swap(blist, start, i)
        max_heapify(alist, index = 0, start = start, end = i)
 
#Rearrange the list into a list representation of a heap. 
def build_max_heap(alist, start, end):
    def parent(i):
        return (i - 1) // 2
    length = end - start
    index = parent(length - 1)
    while index >= 0:
        max_heapify(alist, index, start, end)
        index = index - 1
 
#Modifies the heap structure at and below the node at given index to make it satisfy the heap property. 
def max_heapify(alist, index, start, end):
    def left(i):
        return 2 * i + 1
    def right(i):
        return 2 * i + 2
 
    size = end - start
    l = left(index)
    r = right(index)
    if (l < size and alist[start + l] > alist[start + index]):
        largest = l
    else:
        largest = index
    if (r < size and alist[start + r] > alist[start + largest]):
        largest = r
    if largest != index:
        swap(blist, start + largest, start + index)
        max_heapify(blist, largest, start, end)
        
alist = input('Enter the list of numbers: ').split()
alist = [int(n) for n in alist]
introsort(alist)
print('Sorted list: ', end = '')
print(alist)
