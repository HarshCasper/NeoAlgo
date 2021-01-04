''' 
Euler-circuit-and-Path

Problem Statement : Implement a Queue using 2 stacks s1 and s2 .
                    A Query Q is of 2 Types
                    (i) 1 x (a query of this type means  pushing 'x' into the queue)
                    (ii) 2 (a query of this type means to pop element
                    from queue and print the poped element)


Input : Enter the no of elements and the list of integers.


Output : Print the final Queue.


Time Complexity : O(V)
Space Complexity : O(N)

'''

# Create The Queue
class Queue:
    
    def __init__(self): 
        self.stack1 = [] 
        self.stack2 = [] 
  
    def enter(self, n): 
          
        # Move all elements from stack1 to stack2
        
        while(len(self.stack1) != 0):
            self.stack2.append(self.stack1[-1])  
            self.stack1.pop() 
  
        # Push item into stack1
        
        self.stack1.append(n)  
  
        # Push everything back to stack1
        
        while len(self.stack2) != 0:  
            self.stack1.append(self.stack2[-1])  
            self.stack2.pop() 
  
    # Dequeue an item from the queue  
    def delete(self): 
          
        # If first stack is empty  
        if len(self.stack1) == 0:  
            print("Q is Empty") 
      
        # Return top of self.s1  
        n = self.stack1[-1]  
        self.stack1.pop()  
        return n 

# -----------------------Driver Code-----------------------

#INPUT

# Enter the number of inputs
inputs = int(input("Enter the no. of inputs: "))
# Enter the list of the no. of integers
list_inputs = list(map(int,input("Enter the list of inputs: ").rstrip().rsplit()))
queue = Queue()
for i in list_inputs:
    queue.enter(i)

#OUTPUT

print("The deleted element is: ", queue.delete())
print("The deleted element is: ",queue.delete())
print("The deleted element is: ",queue.delete())

'''
SAMPLE INPUT/OUTPUT:

INPUT

    Enter the no. of inputs: 6
    Enter the list of inputs: 1 2 3 4 5 6

OUTPUT

    The deleted element is:  1
    The deleted element is:  2
    The deleted element is:  3
    
'''
