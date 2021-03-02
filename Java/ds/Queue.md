# Queue

A Queue is a linear structure which follows a particular order in which the operations are performed.

Its implementation is here [Queue](Queuell.java)

The order is First In First Out (FIFO).

The real life examples are queue in front of counter ,queue of students.

## Operations

The operations that are performed on a queue are
1)Enqueue
2)Dequeue
3)Front
4)Rear

It can be implemented either using arrays or linkedlist.

Discussing different cases helps in devising a efficient algorithm.

### 1)Enqueue

Different cases:

i)If Queue is empty then assign the new node as front and rear.

ii)else we move the rear pointer as new nodes are added.

### 2)Dequeue

Different cases:

i)If queue is empty then return an error.

ii)If only one element is there then return the value and set both pointer as null.

iii)else return the front element then move the front pointer to next element of the front.

### 3)Front

Different cases:

i)If queue is empty then return null.

ii)else return front element value.

### 4)Rear

Different cases:

i)If queue is empty then return null.

ii)else return rear element value.

It can be implemented using array also.
