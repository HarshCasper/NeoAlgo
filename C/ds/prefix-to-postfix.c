/*
An expression is called prefix , if the operator appears in the expression before the operands. (operator operand operand)
An expression is called postfix , if the operator appears in the expression after the operands . (operand operand operator)
The program below accepts an expression in prefix and outputs the corresponding postfix expression .
*/
#include <stdio.h>
#include <string.h>
// Struct for stack
typedef struct
{
    char arr[20][20];
    int top;
} stack;

stack s = {.top = -1};
// push function pushes an element to the top of the stack
void push(char arr[])
{
    if (s.top == 20)
    {
        return;
    }
    s.top++;
    strcpy(s.arr[s.top], arr);
}
// pop function pops an item from the top of the stack
char *pop()
{
    if (s.top == -1)
    {
        return "0";
    }
    else
    {
        return s.arr[s.top--];
    }
}
// if operand function checks if the element is an operand
int ifoperand(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return 1;
    }
    return 0;
}
// prefixtopostfix function converts a prefix expression to postfix
void prefixtopostfix(char expression[])
{
    int len = strlen(expression);
    for (int i = len - 1; i >= 0; i--)
    {
        if (ifoperand(expression[i]))
        {
            char exp[2];
            exp[0] = expression[i];
            exp[1] = '\0';
            push(exp);
        }

        else
        {
            char exp[2];
            exp[0] = expression[i];
            exp[1] = '\0';
            char op1[20];
            strcpy(op1, pop());
            char op2[20];
            strcpy(op2, pop());
            char temp[20];
            strcpy(temp, strcat(op1, op2));
            strcat(temp, exp);
            push(temp);
        }
    }
    printf("the postfix expresssion is : %s", pop());
}
// Driver code
int main()
{
    char exp[100];
    printf("Enter the prefix expression \n");
    scanf("%s", exp);
    prefixtopostfix(exp);
    return 0;
}

/*
Sample I/O:

Enter the prefix expression
*+abc
the postfix expresssion is : ab+c*

Time complexity : O(n)
space complexity : O (n)
*/
