// Program to Implement a Queue
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
void insert();
void delete();
void display();
int queue_array[MAX];
int rear = -1;
int front = -1;
int main()
{
	int choice;
	while (1)
	{
		printf("1.Insert element to queue \n");
		printf("2.Delete element from queue \n");
		printf("3.Display all elements of queue \n");
		printf("4.Quit \n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
			default:
				printf("Wrong choice \n");
		}
	}
}
// Inserting an element
void insert()
{
	int item;
	if (rear == MAX - 1)
		printf("Queue Overflow \n");
	else
	{
		if (front == -1)
			front = 0;
		printf("Inset the element in queue : ");
		scanf("%d", &item);
		rear = rear + 1;
		queue_array[rear] = item;
	}
}
// Deleting an element
void delete()
{
	if (front == -1 || front > rear)
	{
		printf("Queue Underflow \n");
		return;
	}
	else
	{
		printf("Element deleted from queue is : %d\n", queue_array[front]);
		front = front + 1;
	}
}
// Displaying the elements in the queue
void display()
{
	int i;
	if (front == -1)
		printf("Queue is empty \n");
	else
	{
		printf("Queue is : \n");
		for (i = front; i <= rear; i++)
			printf("%d ", queue_array[i]);
		printf("\n");
	}
}

/*
Sample Output
1.Insert element to queue 
2.Delete element from queue 
3.Display all elements of queue 
4.Quit 
Enter your choice : 1
Insert the element in queue : 2
1.Insert element to queue 
2.Delete element from queue 
3.Display all elements of queue 
4.Quit 
Enter your choice : 1
Insert the element in queue : 1
.Insert element to queue 
2.Delete element from queue 
3.Display all elements of queue 
4.Quit 
Enter your choice : 3
Queue is : 
2 1 
1.Insert element to queue 
2.Delete element from queue 
3.Display all elements of queue 
4.Quit 
Enter your choice : 4

Complexities
Time Complexity:O(n)
Space Complexity:O(n)
*/

