#### Implementing stacks using linked list

## Creating a Node Class
class Node(object):
    def __init__(self, value):
        self.value = value
        self.next = None

## Creating a Stack Class
class Stack(object):
    def __init__(self):
        self.head = None
        self.num_elements = 0

    # Implementing push method
    def push(self, value):
        # creating a new node
        new_node = Node(value)
        
        if self.head is None:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head = new_node
            
        self.num_elements += 1

    # returns size of stack
    def size(self):
        return self.num_elements
    
    # check if stack is empty or not
    def is_empty(self):
        return self.num_elements == 0

    # pop element from stack
    def pop(self):
        if self.is_empty():
            return None
        
        value = self.head.value
        self.head = self.head.next
        self.num_elements -= 1
        return value

    # returns top element
    def top(self):
        return self.head.value

    def printStack(self):
        temp = self.head

        while temp:
            print(temp.value,end = " ")
            temp = temp.next
        print()


# Implementation of Stack using List
class StackList:
    #Initialization of empty List
    def __init__(self):
        self.data = []
        self.count = 0

    # pushing value inside Stack
    def push(self,value):
        self.data.append(value)
        self.count += 1

    # pop function
    def pop(self):
        if self.is_empty():
            print("Stack is empty")
            return
        self.count -= 1
        return self.data.pop()

    # checking Stack is empty or not
    def is_empty(self):
        return self.count == 0

    # return the top element
    def peek(self):
        if not self.is_empty():
            return self.data[-1]

    # print the whole Stack List
    def get_stack(self):
        return self.data[::-1]

    ## returns the size of stack 
    def size(self):
        return self.count



if __name__ == '__main__':
    ## Testing Stack implementation using Linked List

    print("Representation using Linked List")

    stack = Stack()

    # taking input from user
    print("Enter the size of Stack")
    size = int(input())

    # Initialize stacks with some values
    arr = list(map(int,input().split()))
    
    for i in arr:
        stack.push(i)

    # Test size()
    print ("Pass" if (stack.size() == 5) else "Fail")

    # Test pop()
    print ("Pass" if (stack.pop() == 50) else "Fail")

    # test top()
    print("Pass" if (stack.top()) == 40 else "Fail")

    # Test push()
    stack.push(60)

    print ("Pass" if (stack.pop() == 60) else "Fail")
    print ("Pass" if (stack.pop() == 40) else "Fail")
    print ("Pass" if (stack.pop() == 30) else "Fail")
    stack.push(50)
    print ("Pass" if (stack.size() == 3) else "Fail")

    # Printing all elements in stack
    stack.printStack()



    ## Testing implementation of Stack using List

    print("--------------------------")

    # initialize Stack with  some value
    print("Representation using List")
    stack2 = StackList()
    stack2.push(10)
    stack2.push(20)
    stack2.push(30)
    stack2.push(40)
    stack2.push(50)

    # Test size()
    print ("Pass" if (stack2.size() == 5) else "Fail")

    # Test pop()
    print ("Pass" if (stack2.pop() == 50) else "Fail")

    # Test peek()
    print("Pass" if (stack2.peek() == 40) else "Fail")

    # Test push()
    stack2.push(60)
    print ("Pass" if (stack2.pop() == 60) else "Fail")
    print ("Pass" if (stack2.pop() == 40) else "Fail")
    print ("Pass" if (stack2.pop() == 30) else "Fail")
    stack2.push(50)
    
    print ("Pass" if (stack2.size() == 3) else "Fail")

    # Test printStack() from top to bottom
    print(stack2.get_stack())

