"""
Program to calculate sum of linked list.
In the sum_ll function we traversed through all the functions of the linked list and calculate
the sum of every data element of every node in the linked list.
"""

# A node class
class Node:
    # To create a new node
    def __init__(self, data):
        self.data = data
        self.next = None

# Class Linked list
class LinkedList:
    # create a empty linked list
    def __init__(self):
        self.head = None

    # Function to insert elements in linked list
    def push(self, data):
        newNode = Node(data)
        temp = self.head

        newNode.next = self.head

        # If linked list is not None then insert at last
        if self.head is not None:
            while (temp.next != self.head):
                temp = temp.next
            temp.next = newNode
        else:
            newNode.next = newNode  # For the first node

        self.head = newNode

    # Function to print given linked list
    def print_List(self):
        temp = self.head
        if self.head is not None:
            while (True):
                print(temp.data)
                temp = temp.next
                if (temp == self.head):
                    break

    # Function to calculate sum of a Linked list
    def sum_ll(self, head):
        sum_ = 0
        temp = self.head
        if self.head is not None:
            while True:
                sum_ += temp.data
                temp = temp.next

        return sum_

# Initialize lists as empty by creating Linkedlist objects
head = LinkedList()

# Pushing elements into LinkedList
n = int(input("Enter the no. of elements you want to insert: "))
for i in range(n):
    number = int(input(f"Enter Element {i + 1}: "))
    head.push(number)

print("Entered Linked List: ")
head.print_List()

sum_ = head.sum_ll(head)
print(f"\nSum of Linked List: {sum_}")

"""
Time Complexity: O(n)
Space Complexity: O(n)

SAMPLE INPUT/OUTPUT: 
Entered Circular Linked List:
20 30 40 50
Sum of Linked List: 140

"""

