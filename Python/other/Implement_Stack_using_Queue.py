''' 
Euler-circuit-and-Path

Problem Statement : Implement a Stack using two queues q1 and q2.


Input : Enter the values in the stack as push() function or
        pop() function.


Output : Do some functions on the stack.


Time Complexity : O(V)
Space Complexity : O(N)

'''

# Importing Queue from queue
from queue import Queue 


# Create The Stack
class Stack: 
      
    def __init__(self): 
          
        # Two inbuilt queues
        
        self.queue1 = Queue() 
        self.queue2 = Queue()  
              
        # To maintain current number of elements
        
        self.size = 0
  
    def push(self, x):
        
        self.size += 1
  
        # Push x first in empty q2
        
        self.queue2.put(x)  
  
        # Push all the remaining elements in q1 to q2.
        
        while (not self.queue1.empty()): 
            self.queue2.put(self.queue1.queue[0])  
            self.queue1.get() 
  
        # swap the names of two queues
        
        self.queue = self.queue1  
        self.queue1 = self.queue2  
        self.queue2 = self.queue 
  
    def pop(self): 
  
        # if no elements are there in queue1
        
        if (self.queue1.empty()):  
            return
        self.queue1.get()  
        self.size -= 1
  
    def top(self): 
        if (self.queue1.empty()): 
            return -1
        return self.queue1.queue[0] 
  
    def Currsize(self): 
        return self.size

# -----------------------Driver Code-----------------------

#INPUT

# Enter the number of inputs
inputs = int(input("Enter the no. of inputs: "))
# Enter the list of the no. of integers
list_inputs = list(map(int,input("Enter the list of inputs: ").rstrip().rsplit()))
stack = Stack()
for i in list_inputs:
    stack.push(i)

#OUTPUT

print("Current size: ", stack.Currsize())
print(stack.top())

stack.pop()

print(stack.top())

stack.pop()

print(stack.top())
print("Current size: ", stack.Currsize()) 

'''
SAMPLE INPUT/OUTPUT:

INPUT

    Enter the no. of inputs: 6
    Enter the list of inputs: 1 2 3 4 5 6

OUTPUT

    Current size:  6
    6
    5
    4
    Current size:  4
    
'''
