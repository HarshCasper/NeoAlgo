class circular_llist:

    
    # constructor function called during object creation
    def __init__(self,node):
        self.head = node
        self.tail = self.head
        self.size = 1

    # creates the list by values entered by user at the time of creation
    def create(self,node):
        
        self.tail.next = node
        self.tail = node
        node.next = self.head
        self.size = self.size+1


    # Insert node given as argument to the end of the list
    def append(self,node):
        '''Insert node given as argument to the end of the list'''
        self.tail.next = node
        self.tail = node
        node.next = self.head
        self.size = self.size+1
        print("Value",node.value,"adding at the END of list")
        self.printAll()
        

    # Insert node given as argument to the start of the list
    def prepend(self,node):
        '''insert node given as argument to the start of the list'''
        node.next = self.head
        self.head = node
        self.tail.next = self.head
        self.size = self.size+1
        print("Value",node.value,"adding at the START of list")
        self.printAll()

    # Prints the no of nodes or size of linked list
    def getSize(self):
        '''Prints the no of nodes or size of linked list'''
        print("Total No of Nodes :",end=" ")
        print(self.size)


    # Print all the nodes of list
    def printAll(self):
        '''Print all the nodes of list'''
        node = self.head

        print("Your Current List: ")

        while node.next!=self.head:

            print(node.value,end='')
            print("--->",end='')
            node = node.next

        else:
            print(node.value)


    # Insert node at position passed in argument
    def insert(self,n,index):
        '''Insert node at position passed in argument

        usage : insert(Node,position)

        '''
        i = 0
        node = self.head
        while node:
            if i==index-1:
                nextNode = node.next
                node.next = n
                n.next = nextNode
                self.size = self.size+1
                break
            else:
                i+=1
                node=node.next
        else:
            print("Given index is not in proper range")

        print("Inserting",n.value,"at index",index)
        
        self.printAll()

    # Remove node at position passed in argument
    def remove(self,data):
        '''Remove node at position passed in argument

        usage : remove(value)

        '''
        node = self.head
        while node:
            if node.next.value == data:
                nextNode = node.next.next
                node.next = nextNode
                self.size = self.size-1
                break
            else:
                node = node.next

        else:
            print("Value not Found")

        print("Removing",data,"from the list")
        
        self.printAll()


# Class for creation of nodes in Linked List
class Node:
    def __init__(self,data):
        self.value = data
        self.next = None

if __name__ == '__main__':

    # Taking Input from User
    user_input = list(map(int,input("Enter initial values to be added in List \n").split()))

    # Setting First Value as HEAD
    l  = circular_llist(Node(user_input[0]))

    # Creation of the list
    for inputs in range(1,len(user_input)):
        l.create(Node(user_input[inputs]))

    print('''
     PRESS  :  TO 
     ----------------------
       1    :  APPEND value at the END of list.
       2    :  PREPEND value at the START of the list.
       3    :  INSERT value at the desired Index
       4    :  DELETE value from the list
       5    :  PRINT ALL the values of your list
       6    :  GET SIZE of your List
       7    :  QUIT The program
    -----------------------------
    ''')


    choice = 1
    while choice!=7:
        print("Enter Your Choice")
        choice = int(input())
        if choice==1:
            user_value = int(input("Enter the value you want to APPEND\n"))
            l.append(Node(user_value))
        elif choice==2:
            user_value = int(input("Enter the value you want to PREPEND\n"))
            l.prepend(Node(user_value))
        elif choice==3:
            user_value = int(input("Enter the value you want to INSERT\n"))
            user_desired_index = int(input(f"Enter the position for {user_value}\n"))
            l.insert(Node(user_value),user_desired_index)
        elif choice==4:
            user_value = int(input("Enter the value to be DELETED\n"))
            l.remove(user_value)
        elif choice==5:
            l.printAll()
        elif choice==6:
            l.getSize()
        elif choice!=7:
            print("Invalid choice. Try Again!")
        
    else:
        print("ThankYou! for using our LinkedList\nHAve a Nice Day")
  
    
    # l.printAll()
    # l.append(Node(10))
    # l.prepend(Node(5))
    # l.insert(Node(23),7)
    # l.remove(23)
    # l.getSize()

    # OUTPUT :
    # ----------------------------------------------------------------------------------
    # Enter values to be added in List
    # 1 2 3 4 5 6 7 8 9
    # Your Current List:
    # 1--->2--->3--->4--->5--->6--->7--->8--->9
    # Value 10 adding at the END of list
    # Your Current List:
    # 1--->2--->3--->4--->5--->6--->7--->8--->9--->10
    # Value 5 adding at the START of list
    # Your Current List:
    # 5--->1--->2--->3--->4--->5--->6--->7--->8--->9--->10
    # Inserting 23 at index 7
    # Your Current List:
    # 5--->1--->2--->3--->4--->5--->6--->23--->7--->8--->9--->10
    # Removing 23 from the list
    # Your Current List:
    # 5--->1--->2--->3--->4--->5--->6--->7--->8--->9--->10
    # Total No of Nodes : 11



