/*INFIX TO POSTFIX CONVERSION USING STACK*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max 10000

int j = 0;

//Defining a satck.
struct stack
{
    char data;
    struct stack *next;
};
struct stack *top;

//Push operation of stack.
void push(char c)
{
    struct stack *temp;
    temp = (struct stack *)malloc(sizeof(struct stack));
    if (temp == NULL)
    {
        printf("memory error\n");
        return;
    }

    temp->data = c;

    if (top == NULL)
    {
        temp->next = NULL;
    }
    else
    {
        temp->next = top;
    }
    top = temp;
    return;
}

//Pop operatioj of stack.
char pop()
{
    char c;
    struct stack *temp;
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return -1;
    }

    temp = top;
    c = top->data;
    top = top->next;
    free(temp);
    return c;
}

//Function to check whether the character is an operator or not.
int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 1;
    else
        return 0;
}

//Function to check the precedency of operator.
int precedence(char o)
{
    if (o == '(')
        return 0;
    else if (o == '+' || o == '-')
        return 1;
    else if (o == '*' || o == '/')
        return 2;
    else
        return 3;
}

//Function which takes infix expression as an arguement and return a postfix expression.
char *infix_to_postfix(char infix[], int size)
{
    char *postfix;
    int x = 0;
    postfix = (char *)malloc((size) * sizeof(char));
    while (x < size)
    {
        if (infix[x] == ')')
        {
            while (top->data != '(')
            {
                postfix[j++] = pop();
            }
            pop();
            x++;
            continue;
        }
        if (infix[x] == '(')
        {
            push('(');
            x++;
            continue;
        }
        if (isOperator(infix[x]))
        {
            if (top == NULL)
            {
                push(infix[x++]);
                continue;
            }

            if (precedence(infix[x]) >= precedence(top->data) && top != NULL)
            {
                push(infix[x++]);
                continue;
            }
            if (precedence(top->data) > precedence(infix[x]))
            {
                while (precedence(top->data) > precedence(infix[x]))
                {
                    postfix[j++] = pop();
                    if (top == NULL)
                        break;
                }

                push(infix[x++]);
                continue;
            }
        }
        else
        {
            postfix[j++] = infix[x++];
        }
    }
    while (top != NULL)
    {
        postfix[j++] = pop();
    }
    return postfix;
}

//Main function.
int main()
{
    char infix[Max], *postfix;
    int size, i;

    //Taking infix expression as input.
    printf("Enter the infix expression : ");
    scanf("%s", &infix);

    //size of the given infix expression.
    size = strlen(infix);

    //Calling funtion to convert the expression.
    postfix = infix_to_postfix(infix, size);

    printf("Postfix of given expression is : ");

    for (i = 0; i < j; i++)
        printf("%c", postfix[i]);

    return 0;
}
