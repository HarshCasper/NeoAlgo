# Python program for all basic functionalities of Singly Linked List

class Node:
    # Constructor to initialize the node object
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    # Constructor to initialize head 
    def __init__(self):
        self.head = None

    def insertNodeAtFront(self, ndata):
        nnode = Node(ndata)
        nnode.next = self.head
        self.head = nnode

    def insertNodeAtEnd(self, ndata):
        nnode = Node(ndata)
        if self.head == None:
            self.head = nnode
        else:
            last = self.head
            while last.next != None:
                last = last.next
            last.next = nnode
    
    def insertNodeAtPosition(self, index, ndata):
        if index == 1:
            insertNodeAtFront(self, ndata)
        else:
            cur = 1
            pos = self.head
            while cur < index-1 and pos != None:
                pos = pos.next
                cur += 1
            if pos == None:
                insertNodeAtEnd(self, ndata)
            else:
                nnode = Node(ndata)
                nnode.next = pos.next
                pos.next = nnode

    def deleteNodeAtFront(self):
        if self.head == None:
            print("Empty list, nothing to delete!")
        else:
            self.head = self.head.next

    def deleteNodeAtEnd(self):
        if self.head == None:
            print("Empty list, nothing to delete!")
        elif self.head.next == None:
            self.head=None
        else:
            pos = self.head
            while pos.next.next != None:
                pos = pos.next
            pos.next = None

    def deleteNodeAtPosition(self, index):
        if self.head == None:
            print("Empty list, nothing to delete!")
            return
        pos = self.head
        if index == 1:
            self.head = pos.next
            temp = None
            return
        for ind in range(1,index-1):
            pos = pos.next
            if pos == None:
                break
        if pos == None or pos.next == None:
            print("Index more than number of nodes!")
        else:
            next = pos.next.next
            pos.next = None
            pos.next = next

    def traverseList(self):
        if self.head == None:
            print("Empty list, nothing to print!")
        else:
            n = self.head
            while n != None:
                print(n.data)
                n = n.next

    def countNodes(self):
        cnt = 0
        ind = self.head
        while ind != None:
            cnt += 1
            ind = ind.next
        print(cnt)

if __name__=='__main__':
    newLinkedList = LinkedList()
    print("SINGLY LINKED LIST")
    print("1. Insert Node at Front")
    print("2. Insert Node at End")
    print("3. Insert Node at Position")
    print("4. Delete Node at Front")
    print("5. Delete Node at End")
    print("6. Delete Node at Position")
    print("7. Print the List")
    print("8. Count nodes in the List")
    print("9. Exit")
    print("--Use 1-based indexing--")
    while(True):
        ch = int(input("Enter your choice: "))
        if ch == 1:
            ndata = int(input("Enter the element to insert: "))
            newLinkedList.insertNodeAtFront(ndata)
        elif ch == 2:
            ndata = int(input("Enter the element to insert: "))
            newLinkedList.insertNodeAtEnd(ndata)
        elif ch == 3:
            ndata = int(input("Enter the element to insert: "))
            ind = int(input("Enter index to insert this element: "))
            newLinkedList.insertNodeAtPosition(ind,ndata)
        elif ch == 4:
            newLinkedList.deleteNodeAtFront()
        elif ch == 5:
            newLinkedList.deleteNodeAtEnd()
        elif ch == 6:
            ind = int(input("Enter index to delete element: "))
            newLinkedList.deleteNodeAtPosition(ind)
        elif ch == 7:
            newLinkedList.traverseList()
        elif ch == 8:
            newLinkedList.countNodes()
        elif ch == 9:
            break
        else:
            print("Enter a valid choice (1-9)")
            
            
# --- EXAMPLE ---

# SINGLY LINKED LIST
# 1. Insert Node at Front
# 2. Insert Node at End
# 3. Insert Node at Position
# 4. Delete Node at Front
# 5. Delete Node at End
# 6. Delete Node at Position
# 7. Print the List
# 8. Count nodes in the List
# 9. Exit
# --Use 1-based indexing--
# Enter your choice: 1
# Enter the element to insert: 10
# Enter your choice: 2
# Enter the element to insert: 5
# Enter your choice: 3
# Enter the element to insert: 3
# Enter index to insert this element: 2
# Enter your choice: 7
# 10
# 3
# 5
# Enter your choice: 6
# Enter index to delete element: 2
# Enter your choice: 7
# 10
# 5
# Enter your choice: 8
# 2
# Enter your choice: 4
# Enter your choice: 7
# 5
# Enter your choice: 5
# Enter your choice: 7
# Empty list, nothing to print!
# Enter your choice: 10
# Enter a valid choice (1-9)
# Enter your choice: 9
