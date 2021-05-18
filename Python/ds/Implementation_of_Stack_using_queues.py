"""
Python Program to implement a stack using two queues
by making the push operation costly
"""


class my_stack:
    def __init__(self):
        self.my_queue1 = my_queue()
        self.my_queue2 = my_queue()
    """
    push method takes an argument and enqueues it in my_queue1
    After enqueuing in my_queue1 every element of my_queue2 is
    dequeued and enqueued in my_queue1.
    The names of my_queue1 and my_queue2 are then swapped.
    """

    def push(self, value):
        self.my_queue1.enqueue(value)
        while not self.my_queue2.isempty():
            y = self.my_queue2.dequeue()
            self.my_queue1.enqueue(y)
        temp_name = self.my_queue1
        self.my_queue1 = self.my_queue2
        self.my_queue2 = temp_name

    # pop method dequeues from my_queue2 and returns the dequeued value
    def pop(self):
        return self.my_queue2.dequeue()

    # isempty method returns false if my_queue2 is not empty else it returns true
    def isempty(self):
        return self.my_queue2.isempty()

 
class my_queue:
    # initialize the instance variable item_list of class Queue to an empty list
    def __init__(self):
        self.item_list = []
        
    # enqueue method adds data to items.
    def enqueue(self, value):
        self.item_list.append(value)
        
    # dequeue method dequeues the first element in item_list.
    def dequeue(self):
        return self.item_list.pop(0)

    # isempty method returns false if item_list is not empty else it returns true
    def isempty(self):
        return self.item_list == []

 
if __name__ == '__main__':
    object1 = my_stack()
    print('Enter the size of the numbers you want to push')
    n = int(input())
    print('Enter', n, 'nubmers that you want to push into stack')
    for i in range(0, n):
        m = int(input())
        object1.push(m)
    print('')
    for i in range(0, n+1):
        if object1.isempty():
            print('Stack does not contain any data')
        else:
            print('Value popped out from stack is ', object1.pop())
            
# Time complexity: O(n)
# Space complexity: O(n)

"""
result-
Enter the size of the numbers you want to push
4
Enter 4 nubmers that you want to push into stack
1
2
3
4

Value popped out from stack is  4
Value popped out from stack is  3
Value popped out from stack is  2
Value popped out from stack is  1
Stack does not contain any data
"""
