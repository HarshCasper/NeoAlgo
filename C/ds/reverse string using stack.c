//Stack is a linear data structure in which elements are inserted and deleted at same end.
//The order is  LIFO(Last In First Out) or FILO(First In Last Out).
//Reversing a string using stack can be done with stack operations i.e push and pop.

#include <stdio.h>
#include <string.h>
#define MAX 100
int top=-1;
int item;
char s[MAX];
void push(char item);
char pop();
int isEmpty();
int isFull();

int main()
{
    char str[MAX];
    int i;
    while
    printf("\nEnter word to reverse :\n ");
    scanf("%[^\n]s\n",str);
    for(i=0;i<strlen(str);i++)
        push(str[i]);
    for(i=0;i<strlen(str);i++)
        str[i]=pop();
    printf("Reversed word  is:\n %s\n\n",str);
    return 0;
}
void push(char item)
{
    if(isFull())
    {
        return;
    }
     top=top+1;
    s[top]=item;
}

 char  pop()
{

    if(isEmpty())
    {
        printf("\nNo letters in word\n");
        return 0;
    }
    item = s[top];
    top=top-1;
    return item;
}


int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}


//output:
//Enter word to reverse : girlscriptsummerofcode
//Reversed word  is: edocforemmustpircslrig
