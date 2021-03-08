#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first = NULL,*second = NULL,*third = NULL;
void Create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof (struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void Create2(int A[],int n)
{
    int i;
    struct Node *t,*last;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void Merge(struct Node *p,struct Node*q)
{
    struct Node *last;
    if(p->data<q->data)
    {
        third = last = p;
        p = p->next;
        third->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    while(p&&q)
    {
        if(p->data<q->data)
        {
            last->next = p;
            last = p;
            p=p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p)
        last->next = p;
    if(q)
        last->next = q;
}
int main()
{
    struct Node *t;
    int *A,*B;
    int n;
    printf("Enter the size of the array: \n");
    scanf("%d",&n);
    A = (int *)malloc(n*sizeof(int));
    B = (int *)malloc(n*sizeof(int));
    printf("Enter first LL Elements: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    Create(A,n);
    printf("Enter second LL Elements: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&B[i]);
    }
    Create2(B,n);
	Merge(first,second);
	Display(third);
    return 0;
}
