'''
    Given a linked list of size N. 
    Reverse every k nodes (where k is an input to the function) in the linked list.
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
        # If the linked list is empty
        if self.head is None:
            self.head = Node(new_data)

        # Adding the new node at the end of the linked list
        else:
            new_node = Node(new_data)
            current = self.head

            # Traversing the linked list till we reach the last node
            while current.next:
                current = current.next

            current.next = new_node


    # Printing the node data in order 
    def display(self):
        current = self.head

        # Traversing the linked list
        while current.next is not None:
            print(f'{current.data} -> ', end=' ')
            current = current.next

        print(current.data)

    
    # Function to reverse a linked list in groups of k
    def reversal(self, head, k):
        # if LinkedList is empty
        if head is None:
            return None

        current = head
        next = None
        prev = None
        count = 0

        # Initially traversing k elements through current pointer and reversing them
        while current is not None and count < k:
            next = current.next
            current.next = prev
            prev = current
            current = next
            count += 1
 
        # If current pointer doesn't indicate the end of linked list,
        # we recursively call the function to perform similar group wise reversal
        # for the following groups of k elements 
        if next is not None:
            head.next = self.reversal(next, k)

        # We return the pointer pointing to the head of the new reversed linked list
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


'''
    For reversal function:
        Time complexity: O(n)
        Space complexity: O(1)

    Sample input/output:

    Enter number of elements to insert: 8
    Enter element 0: 1
    Enter element 1: 2
    Enter element 2: 3
    Enter element 3: 4
    Enter element 4: 5
    Enter element 5: 5
    Enter element 6: 6
    Enter element 7: 7
    The linked list is: 
    1 ->  2 ->  3 ->  4 ->  5 ->  5 ->  6 ->  7
    Enter group size: 3
    The new linked list is: 
    3 ->  2 ->  1 ->  5 ->  5 ->  4 ->  7 ->  6
'''

