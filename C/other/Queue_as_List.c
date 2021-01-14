#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// structure for the QueueElement - memeber of a queue
struct QueueElement{
    int value;
    struct QueueElement *next;
};

// structure for new Queue
typedef struct {
    struct QueueElement *write;
    struct QueueElement *read;
} Queue;

// initializint a new Queue
Queue* createQueue() {
    Queue *temp = (Queue*)malloc(sizeof(Queue)); 
    temp->write = temp->read = NULL; 
    return temp; 
}

// checks if queue is empty - there is nothing to read
bool isEmpty(Queue *queue) {
    if(queue->read == NULL) {
        return true;
    }
    return false;
}

// checks if queue is full - read and write queueElement point to the same
bool isFull(Queue *queue) {
    if(queue->write == queue->read) {
        return true;
    }
    return false;
}

struct QueueElement* peek(Queue *queue) {
    struct QueueElement *temp = (struct QueueElement*)malloc(sizeof(struct QueueElement));
    temp = queue->read;
    return temp;
}

// add new queueElement to the end of the queue
bool enqueue(Queue *queue, int value) {
    
    struct QueueElement *temp = (struct QueueElement*)malloc(sizeof(struct QueueElement));
    temp->value = value; 
    temp->next = NULL;

    if (queue->write == NULL) {
        queue->read = temp;
    } else {
        queue->write->next = temp;
    }
    queue->write = temp;
    return true;
}

bool dequeue(Queue *queue, int *value) {

    // there is nothing to read
    if(isEmpty(queue)) {{
        return false;
    }}

    *value = queue->read->value; // put the value you want to "outgoing" pointer
    struct QueueElement* temp = queue->read;
    queue->read = queue->read->next;
    if (queue->write == NULL) {
        queue->read = temp;
    } else {
        queue->write->next = temp;
    }
    queue->write = temp;
    free(queue->read);
    return true;
}

int main() {

    Queue *queue = createQueue();
    int res, *value = &res;

    enqueue(queue, 2);
    enqueue(queue, 4);
    enqueue(queue, 6);
    enqueue(queue, 8);

    dequeue(queue, value);  // value is 2
    printf("From queue: %d\n", *value);

    dequeue(queue, value);  // value is 4
    
    dequeue(queue, value);  // value is 6
    printf("From queue: %d\n", *value);

}