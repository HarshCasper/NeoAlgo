'''
Given a linked list of N nodes. 
Check if the linked list has a loop. 
Linked list can contain self loop.

Example:

Input:
N = 3
value[] = {1,3,4}
position = 2

Output: True

Explanation: In the above example N = 3.
The linked list with nodes N = 3 is
given. Then value of position = 2 is given which
means last node is connected with 2nd
node of linked list. Therefore, there
exists a loop.

Time Complexity: O(N).
Space Complexity: O(1).
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
 

    #  Function to detect loop in linked list  
    def detect_loop(self):
        one_step_p = self.head
        two_step_p = self.head

        while (two_step_p.next and two_step_p.next.next):
            one_step_p = one_step_p.next
            two_step_p = two_step_p.next.next

            if one_step_p == two_step_p:
                return 1

        return 0
 

if __name__ == '__main__':

    # Creating a linked list instance
    ll_obj = LinkedList()

    # Pushing elements to the Linked List
    ll_obj.insert_at_end(1)
    ll_obj.insert_at_end(8)
    ll_obj.insert_at_end(3)
    ll_obj.insert_at_end(4)
    
    # Creating a loop within the Linked List
    ll_obj.head.next.next.next.next = ll_obj.head

    # Here, node at 4th position is looped back to the head (1st position)
    # 1 -> 8 -> 3 -> 4     
    # |_ _ _  _ _ _ _|

    if(ll_obj.detect_loop()):
        print('Found Loop')
    else:
        print('No Loop')

