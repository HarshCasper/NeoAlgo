/* GIVEN A LINKED LIST ,TASK IS TO REVERSE THE LINKED LIST BY REVERSING THE LINKS */
#include<stdio.h>
#include<malloc.h>

/* structure containing data part and link part */
struct node
{
	int data;
	struct node *link;
};

void append(struct node** ,int);
void display(struct node*);
void reverse(struct node **);

int main()
{
    struct node* head = NULL;  
    int i,p,c;
    
    printf("ENTER THE NUMBER OF ELEMENTS IN LINKED LIST "); 
    scanf("%d",&i); 
    for(p=i;p>0;p--)  
    {  
        printf("\nENTER THE ELEMENT ");
        scanf("%d",&c);
        append(&head,c);  
    }
	
	printf("LINKED LIST: \n");
	display(head);
	reverse(&head);
	printf("\nREVERSED LINKED LIST: \n");	
	display(head);
						
	return 0;
}

/*adds node at the end of a linked list*/
void append(struct node **head_ref,int num)
{
	struct node *temp,*r;
	
	if(*head_ref==NULL)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=num;
		temp->link=NULL;
		*head_ref=temp;
	}
	else
	{
		temp=*head_ref;
		/* go to last node */
		while(temp->link != NULL)
		{
			temp = temp->link;
		}
		/* add node at end */
		r=(struct node*)malloc(sizeof(struct node));
		r->data=num;
		r->link=NULL;
		temp->link=r;
	}
}

/* displays the content of linked list */
void display(struct node *head_ref)
{	
	/* traverse the entire linked list */
	while(head_ref!=NULL)
	{
		printf("%d\t",head_ref->data);
		head_ref=head_ref->link;
	}
}

/*reverses the linked list*/
void reverse(struct node **head_ref)
{
	struct node *cur,*prev,*next;
	
	cur=*head_ref;
	prev=NULL;
	next=NULL;
	
	/*traverse the entire linked list*/
	while(cur!=NULL)
	{
		next=cur->link;
		/*reverse current node pointers*/
		cur->link=prev;
		/*move pointers one position ahead*/
		prev=cur;
		cur=next;
	}
	
	*head_ref=prev;
}

/*
SAMPLE INPUT OUTPUT

ENTER THE NUMBER OF ELEMENTS IN LINKED LIST 5

ENTER THE ELEMENT 4

ENTER THE ELEMENT 12

ENTER THE ELEMENT 6

ENTER THE ELEMENT 25

ENTER THE ELEMENT 41
LINKED LIST:
4       12      6       25      41
REVERSED LINKED LIST:
41      25      6       12      4

TIME COMPLEXITY -> O(n)
SPACE COMPLEXITY -> O(1)*/
