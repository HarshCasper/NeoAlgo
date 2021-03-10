/*
 A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. It is a 
collection of nodes.Nodes consists of 2 parts data part and address part. Address part contains the address of the next or the 
successor node. In this program, duplicate elements present in sorted linked list is removed. 
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;


void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void create(int A[],int n)
{
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void removeDuplicate(struct Node *p)
{
    struct Node *q=p->next;

    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
                p=q;
                q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

int main()
{
    int A[]={10,20,20,40,50,50,50,60};
    clrscr();
    printf("Sorted list with no duplicate elements is : ");
    create(A,8);
    removeDuplicate(first);
    Display(first);
    getch();
    return 0;
}

/*
SAMPLE INPUT OUTPUT
 int A[]={10,20,20,40,50,50,50,60}
 output:
 Sorted list with no duplicate elements is : 10 20 40 50 60
  
  Time Complexity: O(n) 
  where n is the number of nodes in the given linked list

  Space Complexity: O(n) 
  where n is the number of nodes in the given linked list
  
  */


