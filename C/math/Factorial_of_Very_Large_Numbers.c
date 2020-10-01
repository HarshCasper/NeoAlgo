#include<stdio.h>
#include<stdlib.h>

// Structure of node
struct node
{
    int val;
    struct node *next;
    struct node *prev;
};
struct node *head;
struct node *t3;

// Calculates the Factorial of very large numbers
void calculate(int n)
{    
    head=(struct node*)malloc(sizeof(struct node));
    head->val=4;
    head->next=NULL;
    struct node *t1;
    t1=(struct node*)malloc(sizeof(struct node));
    t1->next=head;
    t1->val=2;
    head->prev=t1;
    t1->prev=NULL;
    int pr1,pr2,carry=0;
    int c=0;int t;
    
    for(int i=5;i<=n;i++)
    {
        t3=head;
        while(t3->prev!=NULL)
        {
            pr2=0;
            pr2=t3->val*i +carry;
            t3->val=pr2%10;
            carry=pr2/10;
            t3=t3->prev;
        }
        
        pr2=t3->val*i +carry;
        t3->val=pr2%10;
        carry=pr2/10;
        t=carry;
        if(t3->prev==NULL)
        {
            while(t>0)
            {
                c++;
                t=t/10;
            }
            for(int i=1;i<=c;i++)
            {
                struct node *temp;
                temp=(struct node*)malloc(sizeof(struct node));
                temp->val=carry%10;
                carry=carry/10;
                temp->next=t3;
                t3->prev=temp;
                t3=temp;
            }
        }
    }
    
}

int main()
{
    // Number of testcases
    int testcases;
    scanf("%d",&testcases);
    while(testcases-->0)
    {
        int a,x;
        // Enter the value whose factorial needs to be calculated
        scanf("%d",&a);
        if(a==0)
            printf("1");
        else if(a==1)
            printf("1");
        else if(a==2)
            printf("2");
        else if(a==3)
            printf("6");
        else if(a==4)
            printf("24"); // hard coded for the initial numbers.
        else
        {
            
            calculate(a);
            // Printing the values
            x=t3->val;
            if(x>0)
            {
                while(t3->next!=NULL)
                {
                    printf("%d",t3->val);
                    t3=t3->next;
                }
            }
            else if(x==0)
            {
                while(x==0)
                {
                    t3=t3->next;
                    x=t3->val;
                }
                while(t3->next!=NULL)
                {
                    printf("%d",t3->val);
                    t3=t3->next;
                }
            }
        }
        printf("%d",head->val);
    }
    return 0;
}