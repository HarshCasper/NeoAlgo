'''
    Given head pointer you have to delete the value of the node to delete
'''


class ListNode():      
    #Node Class            
    def __init__(self,value=None):
        self.data = value
        self.next = None
# function for creating linked list
def create_LinkedList(head,val):           
    if(head.next!=None):
        temp = head.next
        while(temp.next!=None):
            temp = temp.next
        newnode = ListNode(val)
        newnode.next = None
        temp.next = newnode
        
    else:
        newnode = ListNode(val)
        newnode.next = None
        head.next = newnode
        
#function for displaying  linked list
def print_linkedlist(head):                 
    temp = head.next
    while(temp!=None):
        print(temp.data,end =' ')
        temp = temp.next
    print()

    #function to delete a node from linked list
def delete_node(node):                         
     if node.next is not None:
            node.data, node.next = node.next.data, node.next.next
        
if __name__ == '__main__': 
    head = ListNode()
    n = int(input("Enter total no of elemets in linked list :"))
    for i in range(n):
        create_LinkedList(head,int(input()))
    print_linkedlist(head)
    delete_node(head.next.next)
    print_linkedlist(head)
    
    
    
# OUPUT :
# Enter total no of elemets in linked list :5
# 3
# 4
# 5
# 6
# 7
# 3 4 5 6 7 
# 3 5 6 7 

'''
Time complexity : O(N)
Space complexity :O(1)
'''



    
