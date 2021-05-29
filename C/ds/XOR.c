/*
CODE DESCRPTION:
XOR Linked List is memory efficient Doubly Linked List .
It's Memory Efficient as the list uses bitwise XOR operation to save space for one address.
Instead of storing actual memory addresses, every node stores the XOR of addresses of previous and next nodes. 
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<inttypes.h>

/* Structure of a Node has the data and XOR of the previous and next address i.e npx */
struct node
{
  	int data;
  	struct node *npx;
};

/*Function to create the XOR Linked List */
struct node *xor(struct node *prev,struct node *next)
{
  	return (struct node *)((uintptr_t)(prev)^(uintptr_t)(next));
}

struct node *header,*last;

/* Function to create a Linked List */
void create()
{
	/*Allocate memory for the New node*/
  	struct node *temp= malloc(sizeof(struct node));
  	printf("\nEnter value of Node : ");
  	scanf("%d",&temp->data);
	
	/*Initialize temp npx's as NULL*/
  	temp->npx=NULL;
  	
  	/* If list is empty */
  	if(header==NULL)
  	{
    	header=last=temp;
    	return;
  	}
	/* If linked list is not empty, then present head node's npx 
	will be xor of temp and npx of current head node */
  	else
  	{
   	 	last->npx=xor(last->npx,temp);
    	temp->npx=last;
		/*Update last as temp*/
    	last=temp;
    	return;
  	}	
}

/* Function to display the Nodes of a Linked List */
void show()
{
  	struct node *t1=header;
  	struct node *prev,*current;
  	prev=current=NULL;

  	while(t1!=NULL)
  	{
		/* Print current node */
   	 	printf("->%d",t1->data);
		/* Update prev and current for next iteration */
    	current=t1;
    	t1=xor(prev,t1->npx);
    	prev=current;
  	}
}

void main()
{
  	int i,num;
	printf("Enter number of nodes: ");
	scanf("%d",&num);
	
	for(i=0;i<num;i++)
	create();
	
  	printf("\nXOR LINKED LIST IS \n");
  	show();
}

/*
COMPLEXITY 
Time Complexity : O(n)
Space Complexity : O(1)

OUTPUT:
Enter number of nodes: 5

Enter value of Node : 9

Enter value of Node : 6

Enter value of Node : 4

Enter value of Node : 2

Enter value of Node : 3

XOR LINKED LIST IS
->9->6->4->2->3

*/
