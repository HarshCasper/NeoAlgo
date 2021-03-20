/*
To find whether the given string is a palindrome or not.
A palindrome is a word, number, phrase, or other sequence of characters which reads the same backward as forward, such as madam or racecar.
*/

#include<stdio.h>
#include<conio.h>
struct Node
{
    char data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head,*ptr;
void insert(char data)
{
    //allocate dynamic memory
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
       printf("Overflow");
       return;
    }
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=data;
    if(head==NULL)
        head=newnode;
    else
    {
        ptr=head;
        while(ptr->next!=NULL)  
           ptr=ptr->next;
        ptr->next=newnode;
        newnode->prev=ptr;
    }
}
int isPalindrome()
{
    if(head==NULL)
        return 1;
    struct Node *right,*left;
    right=left=head;
    while(right->next!=NULL)
        right=right->next;
    while(left!=right)
    {
        if(left->data!=right->data)
            return 0;
        left=left->next;
        right=right->prev;
    }
    return 1;
}
void main()
{
    char s[20];
    int l=0,i=0,res;
    head=NULL;
    scanf("%s",&s);
    while(s[i]!='\0')
    {
        l++;
        i++;
    }
    for(i=0;i<l;i++)
        insert(s[i]);
    res=isPalindrome();
    if(res==1)
        printf("Palindrome");
    else
        printf("Not palindrome");
}

/*
Test case 1:
Input : malayalam
Output : Palindrome

Time complexity : O(n)
Space complexity : O(n)
*/
