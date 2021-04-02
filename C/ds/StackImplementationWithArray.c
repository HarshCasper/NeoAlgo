/*
A stack is an Abstract Data Type (ADT), commonly used in most programming languages.This feature makes it LIFO data structure. LIFO stands for Last-in-first-out. Here, the element which is placed (inserted or added) last, is accessed first.
The Basic operation in Stack are:
1.push() − Pushing (storing) an element on the stack.
2.pop() − Removing (accessing) an element from the stack.
3.peek() − get the top data element of the stack, without removing it.
4.display() - used to display the elements
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define SIZE 10

void push(int);
void pop();
void peek();
void display();

int stack[SIZE], top = -1;

void main()
{
	int s;
        printf("Enter the array size: ");
        scanf("%d", &s);
        int a[s];
	int value, choice;
	while (1)
	{
		printf("\n\n*****MENU *****\n");
		printf("1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				printf("Enter the value to be insert: ");
				scanf("%d", &value);
				push(value);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				peek();
				break;
			case 5:
				exit(0);
			default:
				printf("\nWrong selection!!! Try again!!!");
		}
	}
}
void push(int value)
{
	if (top == SIZE - 1)
		printf("\nStack is Full!!! Insertion is not possible!!!");
	else
	{
		top++;
		stack[top] = value;
		printf("\nInsertion success!!!");
	}
}
void pop()
{
	if (top == -1)
		printf("\nStack is Empty!!! Deletion is not possible!!!");
	else
	{
		printf("\nDeleted Element : %d", stack[top]);
		top--;
	}
}
void display()
{
	if (top == -1)
		printf("\nStack is Empty!!!");
	else
	{
		int i;
		printf("\nStack elements are:\n");
		for (i = top; i >= 0; i--)
			printf("%d\n", stack[i]);
	}
}
void peek()
{
	if (top == -1)
		printf("\nstack is empty!!!");
	else
	{
		printf("\nTop element of stack is %d", stack[top]);
	}
}

/*
Enter the array size: 10
***** MENU *****
1.	Push
2.	Pop
3.	Display
4.	peek
5.	exit
Enter your choice: 1
Enter the value to be insert: 45 
Insertion Success!!!

***** MENU *****
1.	Push
2.	Pop
3.	Display
4.	peek
5.	exit
Enter your choice: 1
Enter the value to be insert: 20 
Insertion Success!!!

***** MENU *****
1.	Push
2.	Pop
3.	Display
4.	peek
5.	exit
Enter your choice: 3 
Stack elements are: 45 20

***** MENU *****
1.	Push
2.	Pop
3.	Display
4.	peek
5.	exit
Enter your choice: 4
Top element of Stack is: 20

***** MENU *****
1.	Push
2.	Pop
3.	Display
4.	peek
5.	exit
Enter your choice: 2 
Deleted Element : 20

***** MENU *****
1.	Push
2.	Pop
3.	Display
4.	peek
5.	exit
Enter your choice: 3 
Stack elements are: 45

Time complexity : O(1)
Space Complexity: O(n)
*/
