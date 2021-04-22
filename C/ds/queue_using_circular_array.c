/*
Queue is a linear data structure which follows FIFO
(First In First Out) Rule. It can be implemented using array/
linked list/ stacks.
*/

#include<stdio.h>
#include<stdlib.h>
/*We are creating a structure for Queue.*/
struct node
{
    int front,rear;
    int capacity;
    int *ptr;
};
/*Creating an empty node of the queue*/
struct node* createqueue(int cap)
{
    struct node *queue;
    queue=(struct node*)malloc(sizeof(struct node));
    queue->front=0;
    queue->rear=0;
    queue->capacity=cap;
    queue->ptr=malloc(sizeof(int)*queue->capacity);
    return(queue);
}
/*Checking if the Queue is empty or not*/
int isEmpty(struct node *queue)
{
    if(queue->rear==queue->front)
        return 1;
    return 0;
}
/*Checking if the Queue is full or not*/
int isFull(struct node *queue)
{
    if((queue->rear+1)%queue->capacity==queue->front)
        return 1;
    return 0;
}
/*Inserting data into the queue*/
void enQueue(struct node *queue)
{
    if(isFull(queue))
        printf("\nQueue is full.\n");
    else
    {
        int data;
        printf("\nEnter data t be inserted : ");
        scanf("%d",&data);
        queue->rear=(queue->rear+1)%queue->capacity;
        queue->ptr[queue->rear]=data;
    }
}
/*Deleting data from the queue*/
void deQueue(struct node *queue)
{
    if(isEmpty(queue))
        printf("\nQueue is empty.\n");
    else
    {
        int data;
        queue->front=(queue->front+1)%queue->capacity;
        data=queue->ptr[queue->front];
        printf("\n%d is deleted from queue.\n",data);
    }
}
/*Traversing queue and printing data*/
void display(struct node *queue)
{
    int i;
    if(isEmpty(queue))
        printf("\nQueue is empty.\n");
    else
    {
        printf("\nElements in Circular Queue are: \n");
        for(i=queue->front+1 ; i != queue->rear ; i = (i+1) % queue->capacity)
            printf("Data = %d\n",queue->ptr[i]);
        printf("Data = %d\n",queue->ptr[queue->rear]);
    }
}
/*Driver Program*/
int main()
{
    int cap,choice;
    struct node *queue;
    printf("Enter capacity of the array : ");
    scanf("%d",&cap);
    queue = createqueue(cap);
    while(1)
    {
        printf("\t1 To enter data i.e. en-Queue\n");
        printf("\t2 To delete data i.e. de-Queue\n");
        printf("\t3 To check the queue is empty?\n");
        printf("\t4 To check the queue is full?\n");
        printf("\t5 To view the queue\n");
        printf("\t6 To exit.\n");
        printf("\nEnter Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            enQueue(queue);
            break;
        case 2:
            deQueue(queue);
            break;
        case 3:
            if(isEmpty(queue))
                printf("\nQueue is empty.\n");
            else
                printf("\nQueue is not empty.\n");
            break;
        case 4:
            if(isFull(queue))
                printf("\nQueue is full.\n");
            else
                printf("\nQueue is not full.\n");
            break;
        case 5:
            display(queue);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nIncorrect Choice...\n");
        }
    }
    return 0;
}

/*

    Sample Input/Output:

    Enter capacity of the array : 5
            1 To enter data i.e. en-Queue
            2 To delete data i.e. de-Queue
            3 To check the queue is empty?
            4 To check the queue is full?
            5 To view the queue
            6 To exit.

    Enter Choice : 1

    Enter data t be inserted : 10
            1 To enter data i.e. en-Queue
            2 To delete data i.e. de-Queue
            3 To check the queue is empty?
            4 To check the queue is full?
            5 To view the queue
            6 To exit.

    Enter Choice : 1

    Enter data t be inserted : 20
            1 To enter data i.e. en-Queue
            2 To delete data i.e. de-Queue
            3 To check the queue is empty?
            4 To check the queue is full?
            5 To view the queue
            6 To exit.

    Enter Choice : 1

    Enter data t be inserted : 30
            1 To enter data i.e. en-Queue
            2 To delete data i.e. de-Queue
            3 To check the queue is empty?
            4 To check the queue is full?
            5 To view the queue
            6 To exit.

    Enter Choice : 1

    Enter data t be inserted : 40
            1 To enter data i.e. en-Queue
            2 To delete data i.e. de-Queue
            3 To check the queue is empty?
            4 To check the queue is full?
            5 To view the queue
            6 To exit.

    Enter Choice : 1

    Queue is full.
            1 To enter data i.e. en-Queue
            2 To delete data i.e. de-Queue
            3 To check the queue is empty?
            4 To check the queue is full?
            5 To view the queue
            6 To exit.

    Enter Choice : 3

    Queue is not empty.
            1 To enter data i.e. en-Queue
            2 To delete data i.e. de-Queue
            3 To check the queue is empty?
            4 To check the queue is full?
            5 To view the queue
            6 To exit.

    Enter Choice : 4

    Queue is full.
            1 To enter data i.e. en-Queue
            2 To delete data i.e. de-Queue
            3 To check the queue is empty?
            4 To check the queue is full?
            5 To view the queue
            6 To exit.

    Enter Choice : 5

    Elements in Circular Queue are:
    Data = 10
    Data = 20
    Data = 30
    Data = 40
            1 To enter data i.e. en-Queue
            2 To delete data i.e. de-Queue
            3 To check the queue is empty?
            4 To check the queue is full?
            5 To view the queue
            6 To exit.

    Enter Choice : 2

    10 is deleted from queue.
            1 To enter data i.e. en-Queue
            2 To delete data i.e. de-Queue
            3 To check the queue is empty?
            4 To check the queue is full?
            5 To view the queue
            6 To exit.

    Enter Choice : 5

    Elements in Circular Queue are:
    Data = 20
    Data = 30
    Data = 40
            1 To enter data i.e. en-Queue
            2 To delete data i.e. de-Queue
            3 To check the queue is empty?
            4 To check the queue is full?
            5 To view the queue
            6 To exit.

    Enter Choice : 1

    Enter data t be inserted : 55
            1 To enter data i.e. en-Queue
            2 To delete data i.e. de-Queue
            3 To check the queue is empty?
            4 To check the queue is full?
            5 To view the queue
            6 To exit.

    Enter Choice : 5

    Elements in Circular Queue are:
    Data = 20
    Data = 30
    Data = 40
    Data = 55
            1 To enter data i.e. en-Queue
            2 To delete data i.e. de-Queue
            3 To check the queue is empty?
            4 To check the queue is full?
            5 To view the queue
            6 To exit.

    Enter Choice : 6
    
    
    Time Complexities:
    Enqueue --> O(1)
    DeQueue --> O(1)
    IsEmpty --> O(1)
    IsFull  --> O(1)
    Traversal --> O(n)

    Space Complexity: O(n) [for array]
    
*/
