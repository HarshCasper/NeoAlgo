# creating the Node class to frame a single node
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

# creating a Linked List class to get all the helper functionalities inside
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self,data):
        if self.tail is None:
            self.head = Node(data)
            self.tail = self.head

        else:
            self.tail.next = Node(data)
            self.tail = self.tail.next

    def printLL(self):
        temp = self.head
        while(temp):
            print(temp.data, end =" ")
            temp = temp.next

# creating a solution class to implement more methods on the Linked List
class solution:

    def length(self,head):
        temp = head
        count = 0
        while(temp):
            temp = temp.next
            count += 1
        return count

    # the recursive approach to reverse the Linked List
    def reverse_linked_recursive(self,head):
        
        # if head or it's next pointer are null
        if(head == None or head.next == None):
            return head
        
        # getting small output using recursion
        small_head = self.reverse_linked_recursive(head.next)
        head.next = None
        
        # Traversing to the end node
        temp = small_head
        while(temp.next != None):
            temp = temp.next
        
        # Putting the head pointer at the next of end node
        temp.next = head
        head = small_head
        return head
    
    # the iterative approach to reverse the linked list
    def reverse_linked_iterative(self,head):
        
        # if head or it's next pointer are null
        if(head == None or head.next == None):
            return head
        
        
        # getting three pointers,
        
        # prev = to store the previous pointer
        # temp = auxiliary storage (Node pointer)
        # curr = current pointer
        prev = None
        curr = head
        
        while(curr):
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        return prev

if __name__ == '__main__':
    llist = LinkedList()
    llist.head = Node(1)
    
    # takig array input using map and list
    arr = list(map(int,input().split()))
    
    # forging the linked list
    for i in arr:
        llist.append(i)
    llist.printLL()
    sol = solution()
    
    # recursive approach test
    llist2 = LinkedList()
    llist2.head = sol.reverse_linked_recurive(llist.head)
    llist2.printLL()
    
    # iterative approach test
    llist3 = LinkedList()
    llist3.head = sol.reverse_linked_iterative(llist.head)
    llist3.printLL()
