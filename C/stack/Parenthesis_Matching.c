/* This program is of parenthesis matching which is an application of stack in C */
/* TIME COMPLEXITY: O(n) */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//global declarations
#define MAX 30
int top=-1;
int stack[MAX];

//function prototypes
void push(char);
char pop();
int match(char a,char b);
int check(char []);

//main
int main()
{
        //declaration
        char exp[MAX];
        int valid;

        //taking input
        printf("Enter an algebraic expression : ");
        gets(exp);

        //calling function check
        valid=check(exp);

        //checking if valid is equal to 1 or not
        if(valid==1)
              {  printf("Valid expression\n");}
        else
              {printf("Invalid expression\n");}

                return 0;

}

//function to check parenthesis
int check(char exp[] )
{
        //declaration
        int i,n;
        char temp;
        n=strlen(exp);
        /*loop for traversing through the expression
        storing(pushing) parenthesis into stack
        poping if the match of that parenthesis is found*/
        for(i=0;i <n;i++)
        {
                if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
                        push(exp[i]);
                if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
                {         //stack empty
                        if(top==-1)
                        {
                                //when there are more parenthesis on the right
                                printf("Right parentheses are more than left parentheses\n");
                                return 0;
                        }
                        else
                        {
                                temp=pop();
                                //calling function match to match parenthesis
                                if(!match(temp, exp[i]))
                                {
                                        //to print the parenthesis  which gets mismatched
                                        printf("Mismatched parentheses are : ");
                                        printf("%c and %c\n",temp,exp[i]);
                                        return 0;
                                }
                        }
                }
        }

        //if stack is empty
        if(top==-1)
        {
                //if stack gets empty
                printf("Balanced Parentheses\n");
                return 1;
        }
        else
        {
                //if stack isn't empty
                printf("Left parentheses more than right parentheses\n");
                return 0;
        }
}

//function to match parenthesis
int match(char a,char b)
{
        //if a=[ and b=]
        if(a=='[' && b==']')
              {  return 1;}
        //if a={ and b=}
        if(a=='{' && b=='}')
              {  return 1;}
        //if a=( and b=)
        if(a=='(' && b==')')
              {  return 1;}
        return 0;
}

//function to push element into stack
void push(char item)
{
        if(top==(MAX-1))
        {
                //printing message if stack is full
                printf("Stack Overflow\n");
                return;
        }
        top=top+1;
        stack[top]=item;
}

//function to pop element from stack
char pop()
{
        if(top==-1)
        {
                //printing message if stack is empty
                printf("Stack Underflow\n");
                exit(1);
        }
        return(stack[top--]);
}

/* sample input/output */
/*  1.
Enter an algebraic expression : (((5+7)*6)/2)
Balanced Parentheses
Valid expression

Press any key to continue . . .

    2.
Enter an algebraic expression : [a(b+c}]
Mismatched parentheses are : ( and }
Invalid expression

Press any key to continue . . .


*/
