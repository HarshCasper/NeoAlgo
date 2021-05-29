/*
AIM : A string is provided with some parenthesis and we need to print whether it is balanced or not.
Approach : We will use a stack. We will push the starting parenthesis i.e. { or ( or [
and we will pop the ending parenthesis. Now, if the popped parenthesis is not equivalent to the 
starting one then the parenthesis is not matching else it's a match.
Also, at the end of the traversal, if our stack is not empty then the parenthesis is not matching.
*/
#include<stdio.h>
#include<stdlib.h>

/*Decleartion of stack-structure*/
struct arraystack
{
    int top;
    int capacity;
    char *ptr;
};
/*Function that creates a stack-node and returns pointer to the stack*/
struct arraystack* createstack()
{
    struct arraystack *stackblock;
    stackblock=malloc(sizeof(struct arraystack));
    stackblock->capacity=50;
    stackblock->top=-1;
    stackblock->ptr=malloc(sizeof(char)*stackblock->capacity);
    return(stackblock);
}
/*Function to return the top of the stack*/
char stacktop(struct arraystack *stack)
{
    return stack->ptr[stack->top];
}
/*Function to check if the stack is empty or not*/
int isEmpty(struct arraystack *stack)
{
    if(stack->top == -1)
        return 1;
    else
        return 0;
}
/*Function to check if the stack is full or not*/
int isFull(struct arraystack *stack)
{
    if(stack->top == stack->capacity-1)
        return 1;
    else
        return 0;
}
/*Function to push data into the stack*/
void push(struct arraystack *stack,char data)
{
    if(isFull(stack))
        printf("\nStack overflow!\n");
    else
    {
        stack->top++;
        stack->ptr[stack->top]=data;
    }
}
/*Function to pop or delete data from the stack*/
char pop(struct arraystack *stack)
{
    if(isEmpty(stack))
    {
        printf("\nStack underflow!\n");
        return -1;
    }
    else
    {
        char y;
        y=stack->ptr[stack->top];
        stack->top--;
        return y;
    }
}
/*Function to compare the two given parenthesis*/
int match(char a , char b)
{
    if(a=='{' && b=='}')
        return 1;
    else if(a=='(' && b==')')
        return 1;
    else if(a=='[' && b==']')
        return 1;
    else
        return 0;
}
/*Function to check if the parenthesis is balanced or not*/
int isBalance(char *c)
{
    struct arraystack *stack;
    stack=createstack();

    int i;
    char popped;

    for(i=0 ; c[i]!='\0' ; i++)                     //runs loop until array ends
    {
        if(c[i]=='(' || c[i]=='{' || c[i]=='[')
            push(stack,c[i]);
        else if(c[i]==')' || c[i]=='}' || c[i]==']')
        {
            if(isEmpty(stack))
                return 0;
            popped=pop(stack);
            if(!match(popped,c[i]))
                return 0;
        }
    }
    if(isEmpty(stack))
        return 1;
    else
        return 0;
}
/*Driver program*/
int main()
{
    int result;
    char *c[50];
    printf("Enter the parenthesis-string : ");
    gets(c);
    if(isBalance(c))
        printf("Balanced\n");
    else
        printf("Imbalanced");
    return 0;
}

/*

Sample Input/Output:
Enter the parenthesis-string : abc{de(+bg)}
Balanced


Time Complexity : O(n)
Space Complexity : O(n)

*/
