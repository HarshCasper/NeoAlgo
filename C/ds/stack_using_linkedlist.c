#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int data;
	struct node *link;
};
struct node *top=0;

void push(int n)//push operation
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=n;
	newnode->link=top;
	top=newnode;
}

void pop()
{
	struct node *temp;
	temp=top;
	if(top==0)
	{
		printf("Underflow Condition.");
	}
	else
	{
		printf("Element popped out: %d\n",top->data);
		top=top->link;
		free(temp);
	}
}

void display()
{
	struct node *temp;
	temp=top;
	if(top==0)
	{
		printf("Stack is empty.");
	}
	else
	{
		while(temp!=0)
		{
			printf("%d",temp->data);
			printf("\n");
			temp=temp->link;
		}
	}
}

void main()
{
	push(2);
	push(3);
	push(10);
	display();
	pop("Element popped out!");
	display();
}
