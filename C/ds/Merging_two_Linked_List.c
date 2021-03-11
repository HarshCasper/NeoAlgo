#include <stdio.h>
#include <stdlib.h>
struct Node //Defining a structure 
{
    int data;
    struct Node *next;
}*first = NULL,*second = NULL,*third = NULL;
void Create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node)); //Creating a node dynamically for first linkedlist 
    first->data = A[0]; //Assiging a data to it.
    first->next = NULL; //making first next to null
    last = first; //Making last pointer to point on first
    for(i=1;i<n;i++) 
    {
        t = (struct Node *)malloc(sizeof (struct Node)); //Creating a t node 
        t->data = A[i]; //Assigning a data to it.
        t->next = NULL; //Making t next to null. 
        last->next = t; //Making last next pointer to point on t.
        last = t; //Making last pointer to point on t.
    }
}
void Create2(int A[],int n)
{
    int i;
    struct Node *t,*last; //Defining struct pointers
    second=(struct Node *)malloc(sizeof(struct Node)); //Creating a node dynamically for second linkedlist 
    second->data=A[0]; //Assiging a data to it
    second->next=NULL;//Making second next to null
    last=second;//Making last pointer to point on second

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node)); //Creating a t node 
        t->data=A[i]; //Assigning a data to it.
        t->next=NULL; //Making t next to null. 
        last->next=t; //Making last next pointer to point on t.
        last=t; //Making last pointer to point on t.
    }
}
void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data); //it will display the value until condition becomes false. 
        p=p->next; //Mqaking p point on p next.
    }
    printf("\n");
}
void Merge(struct Node *p,struct Node*q)
{
    struct Node *last; //Defning struct pointer
    if(p->data<q->data)  //Checking whether a q data is greater than p data
    {
        third = last = p; //Assigning third,last to p.
        p = p->next; //Making as p pointer to point on p's next.
        third->next = NULL; //making third next pointer to point on null
    }
    else
    {
        third = last = q; //Making third and last pointers to point on q
        q = q->next; //Making q pointer to point on q's next
        third->next = NULL; //Making third next pointer to point on null.
    }
    while(p&&q) 
    {
        if(p->data<q->data) //Checking whether a q data is greater than p data
        {
            last->next = p; //Making last next pointer to point on p.
            last = p; //Making last pointer to point on p.
            p=p->next; //Making p pointer to point on p's next.
            last->next = NULL; //Making last next pointer to point on null. 
        }
        else
        {
            last->next = q; //Making last next pointer to point on q. 
            last = q; //Making last pointer to point on q.
            q = q->next; //Making q's pointer to point on q's next.
            last->next = NULL; //Making last next pointer to point on null.
        }
    }
    if(p) 
        last->next = p; //Moving last next pointer to point on p until the condition becomes false.
    if(q)
        last->next = q; // Moving last next pointer to point on q until the condition becomes false.
}
int main()
{
    struct Node *t; //Defining struct pointer 
    int *A,*B; //Defining integer type pointers
    int n; //Declaring variable
    printf("Enter the size of the array: \n");
    scanf("%d",&n); //Asking user to enter size of the array.
    A = (int *)malloc(n*sizeof(int)); //Creating an first array dynamically
    B = (int *)malloc(n*sizeof(int)); //Creating an second array dynamically
    printf("Enter first LL Elements: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]); //Asking user to enter first array values. 
    }
    Create(A,n); //Calling function to create first Linkedlist
    printf("Enter second LL Elements: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&B[i]); //Asking user to enter second array values. 
    }
    Create2(B,n); //Calling function to create second Linkedlist
	Merge(first,second); //Calling Merge function to merge both the Linkedlist.
	Display(third); //Displaying the Linkedlist.
    return 0;
}
//Output:- 
/*
Enter the size of the array:
5
Enter first LL Elements:
1
2
3
4
5
Enter second LL Elements:
9
8
7
2
5

1 2 3 4 5 9 8 7 2 5

*/
