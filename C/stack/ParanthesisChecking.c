/*
To check wheather the entered algebraic expression is correct or not by checking the correct 
sequence of appropriate open and close parenthesis with the help of STACK DATA STRUCTURE
If the entred expression is balancing with open and close parenthesis the it will return true.
*/
#include<stdio.h>
#include<conio.h>
#include<string.h>

# define MAX 10


int top = -1 ;
int stack [MAX] ;

void push (char);
char pop ();
int match (char a, char b);
int check (char[]);

void main ()
{
    char exp[MAX] ;
    int valid ;
    printf ("Enter an algebraic expression : ");
    gets (exp);
    valid = check (exp) ;
    if (valid == 1)
    {
        printf ("\nIt is a Valid Expression");
    }
    else
    {
        printf ("\nIt is an Invalid Expression");
    }
}
int check(char exp[])
{
    int i ;
    char temp ;
    for (i = 0; i<strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
                {
                    push (exp[i]);
                }
        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == -1)
            {
                printf ("Right Parenthesis are more than the left parenthis ");
                return 0 ;
            }
            else
            {
                temp = pop ();
                if (!match(temp , exp[i]))
                {
                    printf ("Mismatched parenthesis are : %c and %c", temp, exp[i]);
                    return 0 ;
                }
            }

        }
    }
   if (top == -1 )
   {
       printf ("Balanced Parenthesis");
       return 1 ;
   }
   else
   {
       printf ("Left parenthesis are more than right parenthesis");
       return 0 ;
   }
}

int match (char a , char b)
{
    if (a == '[' && b == ']')
    {
        return 1 ;
    }
    if (a == '{' && b == '}')
    {
        return 1 ;
    }
    if (a == '(' && b == ')')
    {
        return 1 ;
    }
   return 0 ;
}
void push (char item)
{
    if (top == (MAX - 1))
    {
        printf ("Stack overflow\n");
    }
    else
    {
        top = top+1 ;
        stack [top] = item ;
    }
}
char pop ()
{
    if (top == -1 )
    {
        printf ("\nStack Underflow");
        
    }
    else
    {
        return (stack [top--]);
    }
}

/*
Test Case :
Enter algebraic expression : [a(b+c)d]
 
Output : Balanced parenthesis
         Valid Parenthesis

Test Case :
Enter algebraic expression : [(a+b)

Output : Not Balanced Parenthesis
         Left Parenthesis are more than the right parenthesis
         Invalid parenthesis
*/