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

//function to check parathesis
int check(char exp[] )
{
        //declaration
        int i,n;
        char temp;
        n=strlen(exp);
        //loop for traversing through the expression
        //storing(pushing) parathesis into stack
        //poping if the match of that parathesis is found
        for(i=0;i <n;i++)
        {
                if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
                        push(exp[i]);
                if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
                {         //stack empty
                        if(top==-1)
                        {
                                printf("Right parentheses are more than left parentheses\n");
                                return 0;
                        }
                        else
                        {
                                temp=pop();
                                //calling function match to match parathesis
                                if(!match(temp, exp[i]))
                                {
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
                printf("Balanced Parentheses\n");
                return 1;
        }
        else
        {
                printf("Left parentheses more than right parentheses\n");
                return 0;
        }
}

//function to match parathesis
int match(char a,char b)
{
        if(a=='[' && b==']')
                return 1;
        if(a=='{' && b=='}')
                return 1;
        if(a=='(' && b==')')
                return 1;
        return 0;
}

//function to push element into stack
void push(char item)
{
        if(top==(MAX-1))
        {
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
                printf("Stack Underflow\n");
                exit(1);
        }
        return(stack[top--]);
}
