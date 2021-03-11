/* C Program to implement a Stack using Queue.Here we will try to realise STACK
    using the properties OR functions of QUEUE and by making pop operation
   costly*/

#include <malloc.h>
#include <stdio.h>

struct Node {
  int data;
  struct Node *next;
};

/*Maintaining a front,rear pointer
 where insertion takes place at rear end and deletion at front
 and O(1) time is taken  for insertion by maintaining a rear pointer
*/
struct Node *front = NULL, *rear = NULL;
// Store size of queue
int size = 0;

// check whether queue is empty or not
int isEmpty(struct Node *q) {
  if (q == NULL) {
    // return true i.e Queue is empty
    return 1;
  }
  return 0;
}


// Enqueue i.e insert at the REAR end
int enQueue(int item) {
  struct Node *q;
  // creation of new node
  q = (struct Node *)malloc(sizeof(struct Node));
  q->data = item;
  q->next = NULL;

  /* If queue is empty
  i.e front is pointing to NULL update front*/
  if (front == NULL) {
    front = q;
  } else {
    (rear)->next = q;
  }

  rear = q;
  // increase current queue size
  size++;
  return 0;
}

// Dequeue i.e delete at the FRONT end
int deQueue() {
  int delElement;
  /*Queue is empty
  dequeue not possible*/
  if (isEmpty(front)) {
    return -1;
  } else {
    // store the dequeued element
    delElement = front->data;
    (front) = (front)->next;

    if ((front) == NULL) {
      (rear) == NULL;
    }
    // reduce the current queue size
    size--;
  }
  return delElement;
}

void push(int data) { enQueue(data); }

int pop() {
  int i, element;
  /* dequeue upto n-1 elements in the queue
     and enqueue the respective dequeued element
         at the REAR end of the queue*/
  for (i = 0; i < size - 1; i++) {
    element = deQueue();
    enQueue(element);
  }
  /* dequeue the element which will be first value of the STACK
   and return the element*/
  element = deQueue();
  if (element == -1) {
    printf("\n Stack is empty");
    return 0;
  }

  return element;
}

void display(struct Node *temp) {

  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

int main() {

  int i;
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);

  printf("Stack size:%d\n", size);
  printf("Popped Elements are:\n");
  while (size > 0) {
    printf("%d\n ", pop());
  }
  printf("Stack size:%d\n", size);
  return 0;
}

/*
  Sample input/output:
   push(1);
   push(2);
   push(3);
   push(4);
   push(5);

  Output:
  Stack Size:5
  Popped Elements are:
  5
  4
  3
  2
  1
  Stack Size:0

  Time complexity: O(1) for push, O(n) for pop
  Space complexity: O(n)
 */
