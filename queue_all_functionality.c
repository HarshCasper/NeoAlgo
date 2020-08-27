/*
All Basics Functionality of Queue
@author: cherryWood55
@created: 20/08/2020
      Here Indexing starts from 0
      All Insertion and Deletion are based on Index 0.
*/

#include <stdio.h>
#include <stdlib.h>

struct queue {
	int front;
	int rear;
	int curr_size;
	int max_size;
	int *arr;
};

//This function creates a queue and allocates space for the queue
struct queue* create_queue(int max_size) {
	struct queue* new_queue = (struct queue*)malloc(sizeof(struct queue));
	new_queue->max_size = max_size;
	new_queue->curr_size = 0;
	new_queue->front = 0;
	new_queue->rear = max_size - 1;
	new_queue->arr = (int*)malloc(sizeof(max_size * sizeof(int)));
	return new_queue;
}

//This function checks whether the queue is empty
int is_queue_empty(struct queue* q) {
	if (q->curr_size == 0)
		return 1;
	else
		return 0;
}

//This function checks whether the queue is full
int is_queue_full(struct queue* q) {
	if (q->curr_size == q->max_size)
		return 1;
	else
		return 0;
}

//This function adds an element to the queue
void enqueue(struct queue* q, int data) {
	if (is_queue_full(q)) {
		printf ("\nQueue is full.");
		return;
	}
	q->rear = (q->rear + 1) % q->max_size;
	q->arr[q->rear] = data;
	q->curr_size = q->curr_size + 1;
	printf ("\n%d is inserted into the queue at position %d.", data, q->rear);
}

//This function removes the front element of the queue every time it is called
int dequeue(struct queue* q) {
	if (is_queue_empty(q)) {
		printf ("\nQueue is empty. There are no elements to remove from it.");
		return;
	}
	int data = q->arr[q->front];
	q->front = (q->front + 1) % q->max_size;
	q->curr_size = q->curr_size - 1;
	printf ("\n%d is dequeued from the queue.", data);
}

//This function returns the first element of the queue, if there are no elements in the queue, it prints a message
void get_front(struct queue* q) {
	if (is_queue_empty(q)) {
		printf ("\nQueue is empty");
		return;
	}
	printf ("\n%d is the front element of the queue.", q->arr[q->front]);
}

//This function counts the number of elements in the queue
void count(struct queue* q) {
	printf ("\n%d is the number of elements in the queue.", q->curr_size);
}

//This function displays all the elements of the queue
void display(struct queue* q) {
	int i;
	printf ("\nThe elements of the queue are as follows : ");
	for (i = q->front; i <= q->rear; i++)
		printf ("%d, ", q->arr[i]);
}

int main() {

	int max_size;
	int ch;
	int data;
	printf("\nEnter the maximum size of the queue you want to create:");
	scanf("%d", &max_size);
	struct queue* q = create_queue(max_size);
	printf ("\nQueue created with capacity %d.", max_size);

	while (1) {
		printf ("\n\n1. Insert an element\n2. Remove an element\n3. See the front element\n4. Count the number of elements of the queue\n5. Display the elements of the queue\n6. Exit\n");
		scanf ("%d", &ch);
		switch (ch) {
		case 1: printf("\nYou asked to Insert an element.");
			printf("\nEnter element to insert:");
			scanf("%d", &data);
			enqueue(q, data);
			break;
		case 2: printf("\nYou asked to Remove an element.");
			dequeue(q);
			break;
		case 3 : printf("\nYou asked to Display the Front element.");
			get_front(q);
			break;
		case 4 : printf("\nYou asked to Count the Number of Elements in the Queue.");
			count(q);
			break;
		case 5 : printf("\nYou asked to Display all the Elements in the Queue.");
			display(q);
			break;
		case 6 : printf("Exiting..");
			exit(0);
		default : printf ("\nWrong choice. Please enter again.");
		}
	}

	return 0;
}
