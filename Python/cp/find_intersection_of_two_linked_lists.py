'''
Introduction 
    There are two singly linked lists in a system
    Write a program to get the point where two linked list merge. 
    If they do not merge , print that the given lists do not merge
'''


# Code / Solution
# A Linked List Node
class Node:
    def __init__(self, data, next=None):
        self.data = data
        self.next = next
 
# Utility function to find the total number of nodes in a linked list
def size(head):

    # Initialise a int "count" with 0 value
    count = 0
    # Traverse all nodes till u reach tail
    while head:
        # Every time u visit a node , increment "count" and move head pointer forward
        count += 1
        head = head.next
    return count

# Utility function to find if given nodes are equal
def eq(head1, head2):

    # If both nodes are NONE , they are equal
    if(!head1 and !head2):
        return True
    # If one of the nodes is NONE , they are not equal        
    if(None in (head1, head2)):
        return False 
    # If data's of both nodes are equal , 
    # return if their successive nodes are equal recursively
    if(head1.data == head2.data):
        return eq(head1.next, head2.next)
    # else return False
    return False

# Utility function to find the intersection point of two linked lists.
# Assume that the first linked list is of longer size than second
def findIntersection(first, second, k):

    # advance the bigger list by `k` nodes
    i = 0
    while i < k and first:
        first = first.next   
        i += 1
 
    # simultaneously move both lists at the same speed until they meet
    while first and second:
        # if both lists meet any node, then that node is the intersection point
        if eq(first, second):
            return first
        # advance both lists by one node
        first = first.next
        second = second.next
 
    # return None if both lists don't meet
    return None


# Function to find the intersection node of two linked lists
def FindIntersectionNode(first, second):

    # get the difference in the number of nodes in both lists
    diff = size(first) - size(second)
 
    # if the first list has a smaller number of nodes, exchange both lists
    if diff < 0:
        first, second = second, first

    # find and return the intersection node
    return findIntersection(first, second, abs(diff))
 
# Driver Code 
if __name__ == '__main__':

    # Take input of values seperated by space and 
    # split them to form a list to store data values of Linked List 1 in order
    List1 = [int(value) for value in input("Enter the values of each node of Linked List 1 in order : ").split()]
    # Take input of values seperated by space and 
    # split them to form a list to store data values of Linked List 1 in order
    List2 = [int(value) for value in input("Enter the values of each node of Linked List 2 in order : ").split()]

    # Bulid Linked List 1 from List 1 values
    LinkedList1 = None
    temp = LinkedList1
    for k in enumerate(List1):
        if k == 0:
            LinkedList1 = Node(List1[0])
            temp = LinkedList1
        else:
            new = Node(List1[k])
            temp.next = new
            temp = temp.next

    # Build Linked List 2 from List 2 Values
    LinkedList2 = None
    temp = LinkedList2
    for j in enumerate(List2):
        if j == 0:
            LinkedList2 = Node(List2[0])
            temp = LinkedList2
        else:
            new = Node(List2[j])
            temp.next = new
            temp = temp.next          

    # Print Linked List 1
    prev = LinkedList1
    print("Linked List 1 = ", end = "")
    while prev:
        print(prev.data, end = "->")
        prev=prev.next
    print("None")

    # Print Linked List 2
    prev = LinkedList2
    print("Linked List 2 = ", end="")
    while prev:
        print(prev.data, end = "->")
        prev = prev.next
    print("None")
    
    # Find Intersection Node 
    ans = FindIntersectionNode(LinkedList1, LinkedList2)
    if ans:
        print("The intersection point is", ans.data)    
        # If node is not NONE , print data of the node
    else:
        print("The lists do not intersect.")            
        # If node is NONE , print that the given lists do not intersect

'''
Sample Test Case      

Input Format : 
Example :
Enter the values of each node of Linked List 1 in order : 1 2 3 4 5 6 7
Enter the values of each node of Linked List 2 in order : 5 4 3 4 5 6 7   

Output Format :
Example : ( Output to the above input example ) 
Linked List 1 = 1->2->3->4->5->6->7->None
Linked List 2 = 5->4->3->4->5->6->7->None
The intersection point is 3

Time/Space Complexity
Time Complexity : O(m+n)
  where m and n are size of two linked lists
Space Complexity : O(1)
'''

