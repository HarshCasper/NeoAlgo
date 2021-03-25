/*INFIX TO PREFIX CONVERSION USING STACK*/

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
    if (o == ')')
        return 0;
    else if (o == '+' || o == '-')
        return 1;
    else if (o == '*' || o == '/')
        return 2;
    else
        return 3;
}

//Function for reversing the expression.
void reverse(char *prefix)
{
    int s = j, r, i;
    char c;
    r = s;
    r--;
    for (i = 0; i < s / 2; i++)
    {
        c = prefix[i];
        prefix[i] = prefix[r];
        prefix[r--] = c;
    }
}

//Function which takes infix expression as an arguement and return a prefix expression.
char *infix_to_prefix(char infix[], int size)
{
    char *prefix;
    int x;
    size--;
    prefix = (char *)malloc((size) * sizeof(char));
    while (size >= 0)
    {
        if (infix[size] == '(')
        {
            while (top->data != ')')
            {
                prefix[j++] = pop();
            }
            pop();
            size--;
            continue;
        }
        if (infix[size] == ')')
        {
            push(')');
            size--;
            continue;
        }
        if (isOperator(infix[size]))
        {
            if (top == NULL)
            {
                push(infix[size--]);
                continue;
            }

            if (precedence(infix[size]) >= precedence(top->data) && top != NULL)
            {
                push(infix[size--]);
                continue;
            }
            if (precedence(top->data) > precedence(infix[size]))
            {
                while (precedence(top->data) > precedence(infix[size]))
                {
                    prefix[j++] = pop();
                    if (top == NULL)
                        break;
                }

                push(infix[size--]);
                continue;
            }
        }
        else
        {
            prefix[j++] = infix[size--];
        }
    }
    while (top != NULL)
    {
        prefix[j++] = pop();
    }
    reverse(prefix);
    return prefix;
}

//Main function.
int main()
{
    char infix[Max], *prefix;
    int size, i;

    //Taking infix expression as input.
    printf("Enter the infix expression : ");
    scanf("%s", &infix);

    //size of the given infix expression.
    size = strlen(infix);

    //Calling funtion to convert the expression.
    prefix = infix_to_prefix(infix, size);

    printf("Prefix of given expression is : ");
    // printf("%d %s", strlen(prefix), prefix);

    for(i = 0; i < j; i++)
    printf("%c", prefix[i]);
    return 0;
}
