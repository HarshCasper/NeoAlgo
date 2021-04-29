/*
A Queue is a linear structure which follows a particular order in which the operations are performed. 
The order is First In First Out. The below program reverses a queue using stack data structure.
Here stack and queue are implemented using linked list.
*/

#include <stdio.h>
#include <stdlib.h>
//Struct for the stack
typedef struct Stack
{
    int data;
    struct Stack *next;
} Stack;
//Struct for the queue
typedef struct Queue
{
    int data;
    struct Queue *next;
} Queue;
Stack *top = NULL;
Queue *front = NULL;
Queue *rear = NULL;
//push function pushes an element onto the top of the stack
void push(int n)
{
    Stack *New = (Stack *)malloc(sizeof(Stack));
    if (top == NULL)
    {
        top = New;
        top->data = n;
        top->next = NULL;
    }
    else
    {
        New->next = top;
        top = New;
        top->data = n;
    }
}
// pop function pops out an element from the top of the stack
int pop()
{
    if (top != NULL)
    {
        Stack *ptr = top;
        top = top->next;
        return ptr->data;
    }
}
//isStackEmpty function checks whether the stack is empty
int isStackEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}
//isQueueEmpty function checks whether the queue is empty
int isQueueEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    return 0;
}
// The enqueue function inserts an element into the queue
void enqueue(int n)
{
    Queue *New = (Queue *)malloc(sizeof(Queue));
    if (front == NULL)
    {
        front = New;
        rear = front;
        front->data = n;
        rear->next = NULL;
    }
    else
    {
        rear->next = New;
        New->data = n;
        rear = New;
        rear->next = NULL;
    }
}
//dequeue function deletes an element from the queue
int dequeue()
{
    if (front != NULL)
    {
        Queue *ptr = front;
        front = front->next;
        return ptr->data;
    }
}
// printQueue function prints out the elements in the queue
void printQueue()
{
    Queue *ptr = front;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
// reverseQueue function reverses the elements in the queue
void reverseQueue()
{
    while (!isQueueEmpty())
    {
        push(dequeue());
    }
    while (!isStackEmpty())
    {
        enqueue(pop());
    }
}

//Driver code
int main()
{
    int n;
    printf("Enter the number of elements to insert into queue\n");
    scanf("%d", &n);
    int temp;
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        enqueue(temp);
    }
    printf("Elements in the queue\n");
    printQueue();
    printf("Elements in queue after reversing using stack\n");
    reverseQueue();
    printQueue();
}

/*
Sample I/O:

Enter the number of elements to insert into queue
5
Enter the elements
2 4 3 1 5
Elements in the queue
2
4
3
1
5
Elements in queue after reversing using stack
5
1
3
4
2

Time complexity : O(n)
Space complexity : O(n)
*/
