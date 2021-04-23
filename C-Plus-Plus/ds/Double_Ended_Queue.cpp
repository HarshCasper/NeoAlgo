/*  DOUBLE ENDED QUEUE
    Double ended queue or dequeue is a special type of queue
    wherein elements can be inserted or deleted from both ends
    i.e front and rear
*/

#include <bits/stdc++.h>
using namespace std;
//Declare dequeue with an array arr, front and rear as members
typedef struct
{
    int arr[10];
    int front, rear;
} dequeue;
dequeue dq;

//to insert an element to the front of double ended queue
void enqueue_front(int n)
{
    //If dequeue is not full
    if ((dq.rear + 1) % 10 != dq.front)
    {
        //If dequeue is empty insert as first element
        if (dq.front == -1)
        {
            dq.front = 0;
            dq.rear = 0;
        }
        //decrement front in circular manner and insert
        else
            dq.front = (dq.front + 9) % 10;
        dq.arr[dq.front] = n;
    }
}

//to insert an element to the rear of double ended queue
void enqueue_rear(int n)
{
    if ((dq.rear + 1) % 10 != dq.front)
    {
        if (dq.rear == -1)
        {
            dq.front = 0;
            dq.rear = 0;
        }
        //increment rear in circular manner and insert
        else
            dq.rear = (dq.rear + 1) % 10;
        dq.arr[dq.rear] = n;
    }
}

//to delete an element and return it from the front of dequeue
int delete_front()
{
    int item;
    //If dequeue is empty
    if (dq.front == -1)
        return -1;
    else
    {
        item = dq.arr[dq.front];
        //if there is only one element
        if (dq.front == dq.rear)
        {
            dq.front = -1;
            dq.rear = -1;
        }
        else
            dq.front = (dq.front + 1) % 10;
    }
    return item;
}

//to delete an element and return it from the rear of dequeue
int delete_rear()
{
    int item;
    if (dq.rear == -1)
        return -1;
    else
    {
        item = dq.arr[dq.rear];
        if (dq.front == dq.rear)
        {
            dq.front = -1;
            dq.rear = -1;
        }
        else
            dq.rear = (dq.rear + 9)%10;
    }
    return item;
}

//to display the double ended queue from front to rear
void display()
{
    //If dequeue is not empty
    if (dq.front!=-1){
        if (dq.front <= dq.rear)
        {
            for (int i = dq.front; i <= dq.rear; i++)
                printf("%d ", dq.arr[i]);
        }
        else
        {
            for (int i = dq.front; i <= 9; i++)
                printf("%d ", dq.arr[i]);
            for (int i = 0; i <= dq.rear; i++)
                printf("%d ", dq.arr[i]);
        }
        printf("\n");
    }
    else
        printf("Empty Dequeue!");
}

//driver code
int main()
{
    int q, t, n;
    printf("1. Insert at front\n2. Insert at rear\n3. Delete from front\n");
    printf("4. Delete from rear\n5. Display Dequeue\n");
    //input no of queries
    printf("\nEnter the number of queries: ");
    scanf("%d", &q);
    dq.front = -1;
    dq.rear = -1;

    //menu driven program to insert,delete or display dequeue
    while (q--)
    {
        printf("Enter a choice: ");
        scanf("%d", &t);
        switch (t)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &n);
            enqueue_front(n);
            break;
        case 2:
            printf("Enter the value to be inserted: ");
            scanf("%d", &n);
            enqueue_rear(n);
            break;
        case 3:
            printf("Enter the value to be deleted: ");
            printf("%d\n", delete_front());
            break;
        case 4:
            printf("Enter the value to be deleted: ");
            printf("%d\n", delete_rear());
            break;
        case 5:
            display();
            break;
        }
    }
    return 0;
}
/*
    Sample Input/Output:
    1. Insert at front
    2. Insert at rear
    3. Delete from front
    4. Delete from rear
    5. Display Dequeue

    Enter the number of queries: 5
    Enter a choice: 1
    Enter the value to be inserted: 3
    Enter a choice: 2
    Enter the value to be inserted: 1
    Enter a choice: 1
    Enter the value to be inserted: 5
    Enter a choice: 1
    Enter the value to be inserted: 4
    Enter a choice: 5
    4 5 3 1
*/
/*
    Time Complexity of insertion and deletion operations: O(1)
    Time Complexity of display function : O(n)
    Time complexity of random access by index : O(1)
    Space complexity: O(1)
*/
