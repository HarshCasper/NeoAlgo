"""
A Queue is a linear structure which follows a particular order in which the operations are performed.
The order is First In First Out. The below program reverses a queue using stack data structure.
"""
stack = []
queue = []

def reverse(queue):
    while(len(queue)):
        stack.append(queue.pop(0))
    while(len(stack)):
        queue.append(stack.pop())


n = int(input("Enter the elements to insert into queue : "))
print("Enter the elements")
temp = list(map(int,input().split(" ")))
for i in range(n):
    queue.append(temp[i])
print("The elements in the queue are ")
for i in range(n):
    print(queue[i],end = " ")
print()
print("Elements in queue after reversing using stack")
reverse(queue)
for i in range(n):
    print(queue[i],end = " ")

"""
Sample I/O:

Enter the elements to insert into queue : 5
Enter the elements
2 4 3 1 5
The elements in the queue are
2 4 3 1 5
Elements in queue after reversing using stack
5 1 3 4 2

Time complexity : O(n)
Space complexity : O(n)
"""

