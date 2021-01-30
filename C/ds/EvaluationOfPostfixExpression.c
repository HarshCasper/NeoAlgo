/*
A postfix expression is a collection of operators and operands in which the operator is placed after the operands. 
To evaluate a postfix expression using Stack data structure we can use the following steps...
1.Create an empty stack and start scanning the postfix expression from left to right. 
2.If the element is an operand, push it into the stack.
3.If the element is an operator O, pop twice and get A and B respectively. Calculate B operator A and push it back to the stack.
4.When the expression is ended, the value in the stack is the final answer.
*/

#include <stdio.h>
#include <unistd.h>
struct stack
{
    int top;
    float a[50];
}
s;
int main()
{
    char ch[50];
    float x, y, z;
    int i;
    s.top = -1;
    printf("\n\n Enter the postfix expression: ");
    scanf("%s", ch);
    for (i = 0; ch[i] != '\0'; i++)
    {
        switch (ch[i])
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                s.a[++s.top] = ch[i] - '0';
                break;
            case '+':
                x = s.a[s.top--];
                y = s.a[s.top--];
                s.a[++s.top] = x + y;
                break;
            case '-':
                y = s.a[s.top--];
                x = s.a[s.top--];
                s.a[++s.top] = x - y;
                break;
            case '*':
                y = s.a[s.top--];
                x = s.a[s.top--];
                s.a[++s.top] = x * y;
                break;
            case '/':
                y = s.a[s.top--];
                x = s.a[s.top--];
                s.a[++s.top] = x / y;
                break;
        }
    }
    printf("\n Expression value is %5.2f", s.a[s.top]);
    getchar();
}

/*
Sample Case:
Example 1:
Enter the postfix expression: 56*7+
Expression value is :37.00

Example 2:
Enter the postfix expression: 6523+8*+3+*
Expression value is :288.00
*/
