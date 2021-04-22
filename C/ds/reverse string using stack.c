//Stack is a linear data structure in which elements are inserted and deleted at same end.
//The order is  LIFO(Last In First Out) or FILO(First In Last Out).
//Reversing a string using stack can be done with stack operations i.e push and pop.

#include <stdio.h>
#include <string.h>
#define MAX 100
int top=-1;
int data;
char stack[MAX];
void push(char data);
char pop();
int isEmpty();
int isFull();

int main()
{
    char string[MAX];
    printf("Enter word to reverse :\n ");
    scanf("%[^\n]s",string);
    for(int i=0;i<strlen(string);i++)
        push(string[i]);
    for(int i=0;i<strlen(string);i++)
        string[i]=pop();

    printf("Reversed word  is:\n %s",string);
    return 0;
}

void push(char item)
{
    if(isFull())
    {
        return;
    }
     top=top+1;
    stack[top]=item;
}

 char pop()
{

    if(isEmpty())
    {
        printf("\nNo letters in word\n");
        return 0;
    }
    data = stack[top];
    top=top-1;
    return data;
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
