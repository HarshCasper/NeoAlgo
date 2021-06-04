### Stack : -
- Stack A stack is an Abstract Data Type (ADT), commonly used in most programming languages. It is named stack as it behaves like a real-world stack.
  for example – a deck of cards or a pile of plates, etc.
 - A real-world stack allows operations at one end only. For example, we can place or remove a card or plate from the top of the stack only. Likewise, Stack ADT allow all data 
 operations at one end only. At any given time, we can only access the top element of a stack.This feature makes it LIFO data structure. 
 - LIFO stands for Last-in-first-out. Here, the element which is placed (inserted or added) last, is accessed first. In stack terminology, insertion operation is called PUSH operation and removal operation is called 
 POP operation.

### Queue : -
- Queue is an abstract data structure, somewhat similar to Stacks. Unlike stacks, a queue is open at both its ends. One end is always used to insert data (enqueue) and the other is used to remove data (dequeue). Queue follows First-In-First-Out methodology, i.e., the data item stored first will be accessed first.
- Queue Example : -
A real-world example of queue can be a single-lane one-way road, where the vehicle enters first, exits first. More real-world examples can be seen as queues at the ticket windows and bus-stops.

### Implementing Queue using Stacks
- We are given a stack data structure with push and pop operations, the task is to implement a queue using instances of stack data structure and operations on them. 
- While implementing a queue data structure using stacks, we will have to consider the natural behaviour of stack too, which is First in Last Out.
- For performing enqueue we require only one stack as we can directly push data onto the stack.
- To perform dequeue we will require two Stacks, because we need to follow queue's FIFO property and if we directly pop any data element out of Stack, it will follow LIFO approach.



