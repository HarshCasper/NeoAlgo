/*
Given an infix expression, the aim is to convert it into prefix expression.
In order to do this, we first reverse the expression, and find it's postfix expression.
(Postfix expression can be found with the help of an operator stack, and precedence of operators)
The reverse of this resulting expression gives us the final infix expression.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct stack {
    int capacity, top;
    char *arr;
} stack;

stack * createStack(int size) {
    struct stack *s = (struct stack *) malloc(sizeof(struct stack));
    s -> arr = (char *)malloc (size * sizeof(char));
    s -> top = -1;
    s -> capacity = size;
    return s;
}

int isEmpty(stack *s) {
    /* tells whether the stack is empty or not */
    return  s -> top == -1;
}

int isFull(stack *s) {
    /* tells whether a stack is full or not */
    return s -> top == s -> capacity - 1;
}

void push(stack *s, int data) {
    /* push a given element into the stack */
    s -> arr[ ++ s -> top] = data;
}

char pop(struct stack *s) {
    /* to pop the top element from stack */
    return s -> arr[s -> top --];
}

char peek(struct stack *s) {
    /* to get the top element of stack */
    return s -> arr[s -> top];
}

int precedence(char ch) {
    /* gives the precedence of operators */
    switch(ch) {
        case '+':
        case '-': return 1;
        case '/': 
        case '*': return 2;
        case '^': return 3;
        case ')': return 4;
    }
}

stack * infToPost(char infixExp[100]) {
    /* To reverse a given infix expression and convert to postfix expression */
    int index = 0;
    int contains = 0; /* using a variable to see if the operator stack contains a '(' at any time */
    int len = strlen(infixExp);
    stack *operatorStack = createStack(len);
    stack *postfixExp = createStack(len + 1);

    /* converting the reverse of given expression into postfix */
    for ( index = len - 2; index >= 0; index --) { 
        char ch = infixExp[index];
        if ( isspace(ch)) {
            continue;
        }
        if ( isalnum(ch) ) { /* if its an operand */
                push(postfixExp, ch);
                push(postfixExp, ' ');
        }
        else { /* if its an operator */
            if (ch == ')' ) {
                push(operatorStack, ch);
                contains += 1;
            }
            else if (isEmpty(operatorStack)) {
                push(operatorStack, ch);
            }
            else if ( ch == '(') { /* if the current character is '(', we empty the stack until we encounter ')' */
                while ( peek(operatorStack) != ')'){
                    push(postfixExp, pop(operatorStack));
                    push(postfixExp, ' ');
                }
                char waste = pop(operatorStack);
                contains -= 1;
            }
            else if ( (precedence( peek(operatorStack)) <= precedence(ch)) || contains  ) { /* comparing the preceedence */
                push(operatorStack, ch);
            }
            else {
                while (precedence( peek(operatorStack)) > precedence(ch)) { /* comparing the preceedence */
                    push(postfixExp, pop(operatorStack));
                    push(postfixExp, ' ');
                    if (isEmpty(operatorStack)) {
                        break;
                    }
                }
                push(operatorStack, ch);
            }    
        }
    }
    while ( !isEmpty(operatorStack)) {
        push(postfixExp, pop(operatorStack));
        push(postfixExp, ' ');
    }
    return postfixExp;
}

void displayInReverse(stack *s) {
    /* to display the stack in reverse order */
    for (int i = s -> top ; i >= 0; i --) {
            printf("%c", s -> arr[i]);
    }
    printf("\n");
}

void infToPre(char infixExp[100]) {
    /* converts a given infix expression to infix expression */
    stack *postfixExp = infToPost(infixExp);
    displayInReverse(postfixExp); /* reversing finally to get prefix of the given expression */
}

int main() {
    char infixExp[100];
    printf("Enter the Infix expression:\n");
    fgets(infixExp, 100, stdin);
    printf("The Prefix expression is:\n");
    infToPre(infixExp);
    return 0;
}


/*
SampleInput: (A + B) * (C + D)
Sample Output:  * + A B + C D
*/
