/*
A Queue is a linear structure which follows a particular order in which the operations are performed.
The order is First In First Out. The below program reverses a queue using stack data structure.
Here stack and queue are implemented using linked list.
*/

#include <bits/stdc++.h>

using namespace std;

typedef struct Stack
{
    int data;
    struct Stack *next;
} Stack;
typedef struct Queue
{
    int data;
    struct Queue *next;
} Queue;
Stack *top = NULL;
Queue *front = NULL;
Queue *rear = NULL;
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
int pop()
{
    if (top != NULL)
    {
        Stack *ptr = top;
        top = top->next;
        return ptr->data;
    }
}
int isStackEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}
int isQueueEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    return 0;
}
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
int dequeue()
{
    if (front != NULL)
    {
        Queue *ptr = front;
        front = front->next;
        return ptr->data;
    }
}
void printQueue()
{
    Queue *ptr = front;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}
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
int main()
{
    int n;
    cout << "Enter the number of elements to insert into queue" << endl;
    cin >> n;
    int temp;
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        enqueue(temp);
    }
    cout << "Elements in the queue" << endl;
    printQueue();
    cout << "Elements in queue after reversing using stack" << endl;
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
