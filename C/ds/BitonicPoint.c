/* 
Code Description:
Through this C program ,we find the Bitonic Point in a Linked List.
Bitonic Point is a point in bitonic sequence( Sequence of numbers which is first strictly increasing then after a point strictly decreasing) before
which elements are strictly increasing and after which elements are strictly decreasing.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/* Defining a Node */
struct Node {
	int data;
	struct Node* next;
};

/* Header points to first node and Last points to last one */
struct Node *header,*last;

int Bitonic_Point()
{
	struct Node *t1 = header;
	/* If list is empty or contains one Node */
	if(header == NULL || header->next == NULL)
	{
		return -1;
	}
	/* Not in Bitonic sequence */
    if (t1->data > t1->next->data)
        return -1;	
        
	while(t1->next != NULL)
	{
		/* If the data in current Node is greater than Next Node */
		if(t1->data > t1->next->data)
		{
			break;			
		}
		/* Otherwise Traversal continues */
		t1=t1->next;		
	}
	
	/* Storing data (Bitonic Point )of the Current Node */
	int val = t1->data;
	
	/* Updating to its Next Node */
	t1=t1->next;
	
	while(t1->next != NULL)
	{
		/* If data in current Node is less than Next Node's data */
		if(t1->data < t1->next->data)
		{
			/* Bitnoic Point doesn't exist */
			return -1;		
		}
		t1=t1->next;
	}
	return val;
}


/* Function to create a Linked List */
void create()
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
  	
 	printf("\nEnter value of node : ");
 	
  	scanf("%d",&temp->data);
  	temp->next=NULL;
  	
    if (header==NULL)
  	{
    	header=temp;
    	last=temp;
    	return;
  	}
  	else
  	{
    	last->next=temp;
    	last=temp;
    	return;
  	}
}

/* Function to print nodes in a given linked list */
void show()
{
  	struct Node *temp=header;
  	while(temp!=NULL)
  	{
		printf("-->%d",temp->data);
    	temp=temp->next;
  	}
  	printf("\n");
}

/* Driver Function */
void main()
{
	int i,num,B_point;
	
	printf("Enter the number of nodes: ");
	scanf("%d",&num);
	
	for(i=1;i<=num;i++)
	create();
	
	printf("\nLinked List is : \n");
	show();
	
	printf("\nBitonic Point in the Linked List :- \n");
	B_point=Bitonic_Point();
	
	if(B_point == -1)
	{
		printf("\nNo Bitonic Point exists\n");
		return;
	}

	printf("\nValue of Bitonic Point is %d",B_point);
	
}

/*
COMPLEXITY:
Time Complexity:O(n)
Space Complexity:O(n)

OUTPUT:
Enter the number of nodes: 7

Enter value of node : 1

Enter value of node : 2

Enter value of node : 3

Enter value of node : 4

Enter value of node : 3

Enter value of node : 2

Enter value of node : 1

Linked List is :
-->1-->2-->3-->4-->3-->2-->1

Bitonic Point in the Linked List :-

Value of Bitonic Point is 4

*/
