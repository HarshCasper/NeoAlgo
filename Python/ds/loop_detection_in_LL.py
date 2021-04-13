'''
PROBLEM STATEMENT:
Given a linked list, the task is to find whether the linked list consists of
a loop or not.
The user will enter the elements in a linked list and will specify whether
the tail of the linked list is pointed to some other node or to NULL.
If the tail is pointing to NULL, the user will input -1 in 'pos' variable,
otherwise, the user will input the index of the node to which the tail pointer
will point.
'pos' variable is only used to create a linked list as per the data entered
by the user, and is not passed to the function for detecting a loop,
it is being detected by using Floyd's cycle detection algorithm.
'''


class Node:
    # Constructor to initialize node
    def __init__(self, val):
        self.val = val
        self.next = None


class LinkedList:
    # Constructor to initialize head and variable pointer
    def __init__(self):
        self.head = None
        self.var = None

    # Function to create a linked list
    def push(self, newval):
        newnode = Node(newval)
        if self.var:
            self.var.next = newnode
            self.var = newnode
        else:
            self.head = newnode
            self.var = newnode
        return newnode

    # Function to create a loop
    def CreateLoop(self, idx, last):
        temp = self.head
        if idx >= 0:
            while idx > 0:
                temp = temp.next
                idx -= 1
            last.next = temp

    # Function for detecting loop using Floyd's cycle detection algorithm
    def LoopDetect(self):
        slow = self.head
        fast = self.head
        while slow and fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                print("Loop Detected!")
                return
        print("Loop not found!")


# Driver Code
n = int(input("Enter the size of linked list: "))
ll = LinkedList()
print("Enter elements:")
for i in range(n):
    # tail stores the last node of the linked list
    tail = ll.push(int(input()))
# if the user wants to enter a linked list with a loop, pos specifies the index
# of the node which will be pointed by the tail
# For no loop, pos will take -1
pos = int(input("Index of node which is connected to tail, else enter -1: "))
ll.CreateLoop(pos, tail)
ll.LoopDetect()


'''
TEST CASE:
Input:
Enter the size of linked list: 5
Enter elements:
8
6
1
5
7
Index of node which is connected to tail, else enter -1: 2
Output:
Loop Detected!

TIME COMPLEXITY: O(n), to traverse the linked list
where 'n' denotes the length of the linked list.
SPACE COMPLEXITY: O(1), no extra space used.
'''
