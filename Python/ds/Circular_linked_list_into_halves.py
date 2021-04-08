# Program to split circular linked list into two halves
  
# A node class
class Node:
      
    # To create a new node
    def __init__(self, data):
        self.data = data
        self.next = None
  
  
# Class Linked list
class LinkedList:
      
    # create a empty circular linked list
    def __init__(self):
        self.head = None
  
    # Function to insert elements in
    # circular linked list
    def push(self, data):
        newNode = Node(data)
        temp = self.head
          
        newNode.next = self.head
  
        # If linked list is not None then insert at last
        if self.head is not None:
            while(temp.next != self.head):
                temp = temp.next 
            temp.next = newNode
  
        else:
            newNode.next = newNode # For the first node
  
        self.head = newNode
  
    # Function to print given circular linked list
    def print_List(self):
        temp = self.head
        if self.head is not None:
            while(True):
                print(temp.data)
                temp = temp.next
                if (temp == self.head):
                    break 
  
  
    # Function to split a list (starting with head) into two lists.
    def split_List(self, head1, head2):
        slow_ptr = self.head 
        fast_ptr = self.head
      
        if self.head is None:
            return 
          
        # If there are odd nodes in the circular list then
        # fast_ptr->next becomes head and for even nodes
        # fast_ptr->next->next becomes head
        while(fast_ptr.next != self.head and 
            fast_ptr.next.next != self.head ):
            fast_ptr = fast_ptr.next.next
            slow_ptr = slow_ptr.next
  
        # If there are even elements in list then move fast_ptr
        if fast_ptr.next.next == self.head:
            fast_ptr = fast_ptr.next
  
        # Set the head pointer of first half
        head1.head = self.head
  
        # Set the head pointer of second half
        if self.head.next != self.head:
            head2.head = slow_ptr.next
  
        # Make second half circular
        fast_ptr.next = slow_ptr.next
      
        # Make first half circular
        slow_ptr.next = self.head
  
  
  
# Initialize lists as empty by creating Linkedlist objects
head = LinkedList() 
head_1 = LinkedList()
head_2 = LinkedList()
  
# Pushing elements into LinkedList
head.push(20)
head.push(30)
head.push(40)
head.push(50)

print("Entered Circular Linked List: ")
head.print_List()
  
# Function to Split the list 
head.split_List(head_1 , head_2)

print("\nLinked List after splitting: ")
print("\nFirst Circular Linked List")
head_1.print_List()
  
print("\nSecond Circular Linked List")
head_2.print_List()

"""
OUTPUT: 
Entered Circular Linked List:
20 30 40 50
First Circular Linked List
20 30 
Second Circular Linked List
40 50 


.-> 20 -> 30 -> 40 -> 50 -.
|_________________________|

.-> 20 -> 30 -.       .-> 40 -> 50 -. 
|_____________|       |_____________|


Time Complexity: O(n)
"""