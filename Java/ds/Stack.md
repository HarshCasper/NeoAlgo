# Stack
Stack is a type of Linear data structure .Its implementation is here [Stack](Stack.java).

It follows LIFO or FILO order ie (Last In First Out) or(First In Last Out).

The order can be best understoob by real life examples like balls in jar , stack of file ,paper in a printer
in all of these examples the first one to be picked is the last one kept ie on the top and vice versa.

It can also be implemented using Array.

Java implements a Stack ADT(Abstract Data Type) using a LinkedList(class).

when an algorithm is designed for any problem it is important to cover the corner cases in order to make the 
solution efficient.

##Operations
The operations which are normally performed on stack has are 
1.push
2.peep
3.pop

we are using linkedlist implementation(My preference because no problem of size).
we are using a pointer as base(head) to help to move in the stack.


when using linked list we have to keep in mind we have to move Top pointer.

### 1)Push:
It is used to add elements to stack.

Different Cases :
i)when stack is empty 
ii)when using array if array is full.

### 2)Pop:
It is used to remove elements.

Different Cases :
i)when stack is empty we have to throw error.
ii)when only one element is there and we have to remove we must set the top pointer null.
iii)else we have to delete the top before which its value is stored in a variable then head is assigned to next top.

### 3)Peep:
It is used to get top element.

Different cases:
i)if stack empty return null.
ii)else return head. 
