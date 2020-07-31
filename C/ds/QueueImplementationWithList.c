#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    struct Queue *head;
    struct Queue *next;
    int value;
    int size;
}Queue;

/*
 * create empty queue
*/
Queue *create_queue()
{
    Queue *ret = (Queue*) malloc(sizeof(Queue));

    ret->head = ret->next = NULL;

    ret->size = 0;

    return ret;
}

void enqueue(Queue *q, int value)
{
    Queue *cur = q;
    
    // queue is empty, initialize head
    if( !q->head )
    {
        Queue *head = (Queue*) malloc(sizeof(Queue));

        if( !head )
        {
            perror("create queue");

            exit(-1);
        }
        head->value = value;
        head->next = NULL;
        
        cur->head = head;
        cur->size++;
    }
    else
    {
        // go until end of queue
        cur = cur->head;
        while( cur->next )
        {
            cur = cur->next;
        }

        Queue *temp = (Queue*) malloc(sizeof(Queue));

        temp->value = value;
        temp->next = NULL;
        
        cur->next = temp;

        q->size++;
    }
    
    return;
}

int dequeue(Queue *q)
{
    Queue *cur = q->head;
    int ret = cur->value;
    q->size--;

    // advance the head of the queue
    q->head = q->head->next;
    
    // free memory
    free(cur);
    cur = NULL;

    return ret;
}

void print_queue(Queue *q)
{
    Queue *cur = q->head;

    printf("[");
    while( cur )
    {
        printf(" %d ", cur->value);
        cur = cur->next;
    }
    printf("]\n");

    return;
}

int main()
{
    Queue *q1 = create_queue();

    enqueue(q1, 5);
    enqueue(q1, 9);

    print_queue(q1);

    int d = dequeue(q1);
    printf("d is %d\n", d);

    print_queue(q1);

    enqueue(q1, 45);

    print_queue(q1);

    return 0;
}
