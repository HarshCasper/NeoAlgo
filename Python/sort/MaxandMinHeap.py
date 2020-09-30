# Python3 Code implementation of Max and Min Heap
import sys


class MaxHeap:
    def __init__(self, mxsize):

        self.mxsize = mxsize
        self.len = 0
        self.mxHeap = [0] * (self.mxsize + 1)
        self.mxHeap[0] = sys.mxsize
        self.FR = 1

    # Function to determine parent node
    def parent(self, p):

        return p // 2

    # Function to determine leftchild
    def leftChild(self, p):

        return 2 * p

    # Function to determine rightChild
    def rightChild(self, p):

        return (2 * p) + 1

    # Function to determine leaf node
    def isLeaf(self, p):

        if p >= (self.len // 2) and p <= self.len:
            return True
        return False

    # Function for swapping two nodes of heap
    def swap(self, fps, sps):

        self.mxHeap[fps], self.mxHeap[sps] =
        (self.mxHeap[sps], self.mxHeap[fps])

    # Function for  heapify the node at position p
    def maxHeapify(self, p):

        # If the mxHeap node is not a leaf node and smaller
        # than its child
        if not self.isLeaf(p):
            if (self.mxHeap[p] < self.mxHeap[self.leftChild(p)] or
               self.mxHeap[p] < self.mxHeap[self.rightChild(p)]):

                # Swap the left child & heapify
                # left child
                if self.mxHeap[self.leftChild(p)] >
                self.mxHeap[self.rightChild(p)]:
                    self.swap(p, self.leftChild(p))
                    self.maxHeapify(self.leftChild(p))
                # Swap the right child and heapify
                # right child
                else:
                    self.swap(p, self.rightChild(p))
                    self.maxHeapify(self.rightChild(p))

    # Function to insert a node into maxheap
    def insert(self, elem):

        if self.len >= self.mxsize:
            return
        self.len += 1
        self.mxHeap[self.len] = elem

        cur = self.len

        while self.mxHeap[cur] > self.mxHeap[self.parent(cur)]:
            self.swap(cur, self.parent(cur))
            cur = self.parent(cur)

    # Function to display the contents of the heap
    def Display(self):

        for k in range(1, (self.len // 2) + 1):
            print(" PARENT : " + str(self.mxHeap[k]) +
                  " LEFT CHILD : " + str(self.mxHeap[2 * k]) +
                  " RIGHT CHILD : " + str(self.mxHeap[2 * k + 1]))

    # Function for removing and returning max value of heap
    def extractMax(self):

        popEle = self.mxHeap[self.FR]
        self.mxHeap[self.FR] = self.mxHeap[self.len]
        self.len -= 1
        self.maxHeapify(self.FR)

        return popEle


class MinHeap:
    def __init__(self, mxsize):

        self.mxsize = mxsize
        self.len = 0
        self.minmHeap = [0] * (self.mxsize + 1)
        self.minmHeap[0] = -1 * sys.mxsize
        self.FR = 1

    # Function to determine parent position
    def parent(self, p):

        return p // 2

    # Function for finding left child position
    def leftChild(self, p):

        return 2 * p

    # Function to find position of right child
    def rightChild(self, p):

        return (2 * p) + 1

    # Function to check node is leaf node
    def isLeaf(self, p):

        if p >= (self.len // 2) and p <= self.len:
            return True
        return False

    # Function to swap two nodes
    def swap(self, fps, sps):

        self.minmHeap[fps], self.minmHeap[sps] =
        (self.minmHeap[sps], self.minmHeap[fps])

    # Function to heapify  node at pos
    def minHeapify(self, p):

        # Check If the node is a non-leaf node and smaller
        # than any of child
        if not self.isLeaf(p):
            if (self.minmHeap[p] > self.minmHeap[self.leftChild(p)] or
               self.minmHeap[p] > self.minmHeap[self.rightChild(p)]):

                # Swap h the left child and heapify
                # left child
                if self.minmHeap[self.leftChild(p)] > self.minmHeap[
                 self.rightChild(p)]:
                    self.swap(p, self.leftChild(p))
                    self.minHeapify(self.leftChild(p))
                # Swap the right child and heapify
                # the right child
                else:
                    self.swap(p, self.rightChild(p))
                    self.minHeapify(self.rightChild(p))

    # Function to insert into the heap
    def insert(self, element):

        if self.len >= self.mxsize:
            return
        self.len += 1
        self.minmHeap[self.len] = element

        current = self.len

        while self.minmHeap[current] < self.minmHeap[self.parent(current)]:
            self.swap(cu, self.parent(cur))
            cur = self.parent(cur)

    # Function to print the contents of the heap
    def Print(self):

        for j in range(1, (self.len // 2) + 1):
            print(" PARENT : " + str(self.Heap[j]) +
                  " LEFT CHILD : " + str(self.Heap[2 * j]) +
                  " RIGHT CHILD : " + str(self.Heap[2 * j + 1]))

    # Function to build the min heap using
    # the minHeapify function
    def minHeap(self):

        for p in range(self.len // 2, 0, -1):
            self.minHeapify(p)
    # Function to remove & return smallest

    def remove(self):

        popElem = self.minmHeap[self.FR]
        self.Heap[self.FR] = self.minmHeap[self.len]
        self.len -= 1
        self.minHeapify(self.FR)
        return popElem


# Driver Code
if __name__ == "__main__":

    print("Input-->")
    print("Enter the size of heap")
    size = int(input())
    li = []
    print("Enter the elements of heap:")
    for i in range(0, size):
        ele = int(input())

        li.append(ele)
    maxHeap = MaxHeap(size)
    for i in range(0, size):
        maxHeap.insert(li[i])
    print("Output-->")
    print("The Max Heap is :")
    maxHeap.Print()

    print("The Maximum value is " + str(maxHeap.extractMax()))
    minHeap = MinHeap(size)
    for i in range(0, size):
        minHeap.insert(li[i])
    print("The Min Heap is :")
    minHeap.Dispaly()

    print("The Minimum value is " + str(minHeap.remove()))
"""
Input-->
Enter the size of heap :
9
Enter the elements of heap :
5
3
17
10
84
19
6
22
9
Output-->
The Max Heap is:
PARENT : 84 LEFT CHILD : 22 RIGHT CHILD : 19
PARENT : 22 LEFT CHILD : 17 RIGHT CHILD : 10
PARENT : 19 LEFT CHILD : 5 RIGHT CHILD : 6
PARENT : 17 LEFT CHILD : 3 RIGHT CHILD : 9
The Maximum value is 8.
The Min Heap is:
PARENT : 3 LEFT CHILD : 5 RIGHT CHILD :6
PARENT : 5 LEFT CHILD : 9 RIGHT CHILD :84
PARENT : 6 LEFT CHILD : 19 RIGHT CHILD :17
PARENT : 9 LEFT CHILD : 22 RIGHT CHILD :10
The Minimum value is 3.
Time Complexity : O(n log n)
Space Complexity : O(1)
"""
