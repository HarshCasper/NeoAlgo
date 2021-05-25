#Python program to implement stack using list (array)
class Stack:
    #constructor
    def __init__(self):
        self.stack = []
        self.top = None

    #inserting on top
    def push(self, value):
        self.stack.append(value)
        self.top = len(self.stack)-1

    #check if stack is empty
    def is_empty(self):
        if self.stack == []:
            print("Stack is empty !")
        else:
            print("Stack not empty yet")

    #removing an element from top
    def pop(self):
        if self.stack == []:
            print("Underflow")
        else:
            value = self.stack.pop()
            self.top = len(self.stack)
            print("The popped element is ", value)

    #get the top element
    def peek(self):
        if self.stack == []:
            print("Underflow")
        else:
            print("Top element is : " , self.stack[-1])

    #display stack elements
    def display(self):
        if self.stack == []:
            print("Underflow")
        else:
            print("Stack elements are :")
            for i in range(self.top, -1, -1):
                print(self.stack[i])

#executable code
if __name__ == '__main__':
    s = Stack()
    print("     MENU        ")
    print("1. Push\n2. Pop\n3. Peek\n4. Empty\n5. Display\n6. Exit")
    while True:
        ch = int(input("Enter your choice : "))
        if ch == 1:
            val = int(input("Enter a value : "))
            s.push(val)
        elif ch == 2:
            s.pop()
        elif ch == 3:
            s.peek()
        elif ch == 4:
            s.is_empty()
        elif ch == 5:
            s.display()
        elif ch == 6:
            break
        else:
            print("Wrong choice")
            
"""
SAMPLE I/O:

     MENU
1. Push
2. Pop
3. Peek
4. Empty
5. Display
6. Exit
Enter your choice : 1
Enter a value : 10
Enter your choice : 1
Enter a value : 20
Enter your choice : 1
Enter a value : 30
Enter your choice : 5
Stack elements are :
30
20
10
Enter your choice : 3
Top element is :  30
Enter your choice : 2
The popped element is  30
Enter your choice : 2
The popped element is  20
Enter your choice : 2
The popped element is  10
Enter your choice : 4
Stack is empty !
Enter your choice : 6

Time Complexity:
Push : O(1)
Pop : O(1)
Peek : O(1)
Empty : O(1)

Space Complexity: O(n)
"""
