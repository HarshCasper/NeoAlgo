/*
Code Description :
A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations.
It consists of nodes.A Node has 2 parts;One is the data part and the other is the address part. Address part contains the address of the next or the 
successor node and data part contains value of the node.
Through this C program,Nodes of a linked list are arranged such that the odd and the even nodes are segregated.
Here,all even nodes appear before all the odd nodes in the modified linked list. 
*/

#include <stdio.h>
#include <malloc.h>

//Defining the structure of a Node
struct node
{
  int data;
  struct node *next;
};

//Header to point to the first node and Last to point to the Last one
struct node *header, *last;

//Function Declarations
void SegregateOddEven();
void create();
void show();

//Driver Function
void main()
{
    int i, num;
  
    printf("Enter the number of nodes : ");
    scanf("%d", &num);
  
    for (i = 1; i <= num; i++)
    {
    	create();
	}
  	
    printf("\nLinked List is : \n");
    show();
  
    SegregateOddEven();
  
    printf("\nModified Linked List is : \n");
    show();
}

//Function for Creation of a Linked List
void create()
{
    struct node *temp = malloc(sizeof(struct node));
    printf("Enter value of Node: ");
    scanf("%d", &temp->data);
    temp->next= NULL;
	if (header == NULL)
	{
    	header = temp;
    	last = temp;
    	return;
	}
    else
    {
    	last->next = temp;
    	last = temp;
    	return;
    }
}

//Function to Display Nodes of a Linked List
void show()
{
    struct node *temp = header;
    
    while (temp != NULL)
  	{
    	printf("-->%d", temp->data);
    	temp = temp->next;
    }
    
}

//Function to Segregate Even and Odd Nodes of a Linked List
void SegregateOddEven()
{
    struct node *temp = header, *p1 = last, *next_node = NULL, *prev;
  
    while (temp != p1)	//Traversing of Nodes till last second node
	{
		/* If the data of node is ODD */
    	if (temp->data % 2 != 0)	
    	{
      		if (temp == header)		//If the first node is odd,set prev as header and then update header to the next node 
      		{
        		prev = header;
        		header = header->next;
      		}
      		next_node = temp->next;		//Store value of current odd node's next in next_node
     		prev->next = next_node;		//Set previous odd node's next to next_node
      		last->next = temp;			//Make current odd node as the last node of the list
      		temp->next = NULL;			//Make the last node to point to NULL
      		last = temp;				//Make last equal to current odd node
      		temp = next_node;			//Update current pointer to next of the moved node
    	}		
    	/* If data of node is EVEN */
    	else						
    	{
      		prev = temp;
      		temp = temp->next;
    	}
	}
	/* If the last node is ODD */
    if (p1->data % 2 != 0)		//p1 points to the last node here
  	{
    	next_node = temp->next;
    	prev->next = next_node;
    	last->next = temp;
    	temp->next = NULL;
    	last = temp;
  	}
}
