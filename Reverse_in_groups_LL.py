'''
Given a linked list of size N. 
Reverse every k nodes (where k is an input to the function) in the linked list.

Example:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4

Output: 4 2 2 1 8 7 6 5 

Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.
'''

class Node:
    # initializing the Node
     def __init__(self, data):
        self.data = data
        self.next = None
 
 
class LinkedList:
    # Initializing the LinkedList
    def __init__(self):
        self.head = None
 

    # To insert a node at the last position (Pushing)
    def insert_at_end(self, new_data):
        if self.head is None:
            self.head = Node(new_data)

        else:
            new_node = Node(new_data)
            current = self.head

            while current.next:
                current = current.next

            current.next = new_node


    # Printing the node data in order 
    def display(self):
        current = self.head

        while current.next is not None:
            print(f'{current.data} -> ', end=' ')
            current = current.next

        print(current.data)

    
    def reversal(self, head, k):
        if head is None:
            return None

        current = head
        next = None
        prev = None
        count = 0
 
        while current is not None and count < k:
            next = current.next
            current.next = prev
            prev = current
            current = next
            count += 1
 
        if next is not None:
            head.next = self.reversal(next, k)
 
        return prev
        

if __name__ == '__main__':
    ll_obj = LinkedList()

    N = int(input('Enter number of elements to insert: '))

    for i in range(N):
        val = int(input(f'Enter element {i}: '))
        ll_obj.insert_at_end(val)

    print('The linked list is: ')
    ll_obj.display()

    k = int(input('Enter group size: '))

    ll_obj.head = ll_obj.reversal(ll_obj.head, k)

    print('The new linked list is: ')
    ll_obj.display()

