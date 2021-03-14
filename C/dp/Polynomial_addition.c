/*
To find the sum of two polynomials using linked list.

Polynomial Expression: An expression of more than two algebraic terms, especially the sum of several 
terms that contain different powers of the same variable
Example : x^2 − 4x + 7
*/


#include<stdio.h>
struct Node
{
    int coef,pow;
    struct Node *next;
};
typedef struct Node *NODE;
NODE res;
NODE insert(NODE head,int coef,int pow)
{
    NODE newnode,temp;
    newnode=(NODE)malloc(sizeof(struct Node));
    newnode->coef=coef;
    newnode->pow=pow;
    newnode->next=0;
    if(head==0)
        return newnode;
    temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
    return head;
}
void display(NODE head)
{
    NODE temp;
    if(head==0)
        printf("Polynomial is empty");
    else
    {
        temp=head;
        while(temp->next!=0)
        {
            if(temp->coef)
            {
                   if(temp->next->coef>=0)
                      printf("%dx^%d + ",temp->coef,temp->pow);
                   else
                      printf("%dx^%d ",temp->coef,temp->pow);
            }
            temp=temp->next;
        }
        printf("%d",temp->coef);
    }
}
NODE add(NODE head1,NODE head2)
{
    NODE p1=head1,p2=head2,res=0;
    int coef;
    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->pow>p2->pow)
        {
            res=insert(res,p1->coef,p1->pow);
            p1=p1->next;
        }
        else if(p2->pow>p1->pow)
        {
            res=insert(res,p2->coef,p2->pow);
            p2=p2->next;
        }
        else
        {
            coef=p1->coef+p2->coef;
            res=insert(res,coef,p1->pow);
            p1=p1->next;
            p2=p2->next;
        }
    }
    return res;
}
void main()
{
    NODE poly1=0,poly2=0,res;
    int n1,n2,i,coef,pow;
    printf("Enter number of terms of 1st polynomial\n");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
       printf("Enter coefficient and power of %d term : ",i);
       scanf("%d%d",&coef,&pow);
       poly1=insert(poly1,coef,pow);
    }
    printf("First polynomial : ");
    display(poly1);
    printf("\nEnter number of terms of 2nd polynomial\n");
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    {
       printf("Enter coefficient and power of %d term : ",i);
       scanf("%d%d",&coef,&pow);
       poly2=insert(poly2,coef,pow);
    }
    printf("Second polynomial : ");
    display(poly2);
    res=add(poly1,poly2);
    printf("\nResulting polynomial : ");
    display(res);
}


/*
Test case:

Enter number of terms of 1st polynomial                                                                                         
4                                                                                                                               
Enter coefficient and power of term 1: 8 3                                                                                      
Enter coefficient and power of term 2: 3 2                                                                                      
Enter coefficient and power of term 3: 2 1                                                                                      
Enter coefficient and power of term 4: 6 0                                                                                      
First polynomial : 8x^3 + 3x^2 + 2x^1 + 6                                                                                       
Enter number of terms of 2nd polynomial                                                                                         
3                                                                                                                               
Enter coefficient and power of term 1 : 23 4                                                                                    
Enter coefficient and power of term 2 : 18 1                                                                                    
Enter coefficient and power of term 3 : -3 0                                                                                    
Second polynomial : 23x^4 + 18x^1 -3                                                                                            
Resulting polynomial : 23x^4 + 8x^3 + 3x^2 + 20x^1 + 3

*/

