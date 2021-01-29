/*
A postfix expression is a collection of operators and operands in which the operator is placed after the operands. That means, in a postfix expression the operator follows the operands.
A postfix expression can be evaluated using the Stack data structure. To evaluate a postfix expression using Stack data structure we can use the following steps...
1.Read all the symbols one by one from left to right in the given Postfix Expression
2.If the reading symbol is operand, then push it on to the Stack.
3.If the reading symbol is operator (+ , - , * , / etc.,), then perform TWO pop operations and store the two popped oparands in two different variables (operand1 and operand2). Then perform reading symbol operation using operand1 and operand2 and push result back on to the Stack.
4.Finally! perform a pop operation and display the popped value as final result.
*/

#include <stdio.h>
#include <unistd.h>
struct stack
{
    int top;
    float a[50];
}
s;
void main()
{
    char pf[50];
    float d1, d2, d3;
    int i;
    s.top = -1;
    printf("\n\n Enter the postfix expression: ");
    scanf("%s", pf);
    for (i = 0; pf[i] != '\0'; i++)
    {
        switch (pf[i])
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
                s.a[++s.top] = pf[i] - '0';
                break;
            case '+':
                d1 = s.a[s.top--];
                d2 = s.a[s.top--];
                s.a[++s.top] = d1 + d2;
                break;
            case '-':
                d2 = s.a[s.top--];
                d1 = s.a[s.top--];
                s.a[++s.top] = d1 - d2;
                break;
            case '*':
                d2 = s.a[s.top--];
                d1 = s.a[s.top--];
                s.a[++s.top] = d1 * d2;
                break;
            case '/':
                d2 = s.a[s.top--];
                d1 = s.a[s.top--];
                s.a[++s.top] = d1 / d2;
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
