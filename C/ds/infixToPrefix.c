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
    return  s -> top == -1;
}

int isFull(stack *s) {
    return s -> top == s -> capacity - 1;
}

void push(stack *s, int data) {
    s -> arr[ ++ s -> top] = data;
}

char pop(struct stack *s) {
    return s -> arr[s -> top --];
}

char peek(struct stack *s) {
    return s -> arr[s -> top];
}

int precedence(char ch) {
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
    for (int i = s -> top ; i >= 0; i --) {
            printf("%c", s -> arr[i]);
    }
    printf("\n");
}

void infToPre(char infixExp[100]) {
    stack *postfixExp = infToPost(infixExp);
    printf("The Prefix expression is:\n");
    displayInReverse(postfixExp); /* reversing finally to get prefix of the given expression */
}

int main() {
    char infixExp[100];
    printf("*****\nNOTE: \n1. Assuming there is a space between any two operators or operands\n2. Operands can be either variables or single digited numbers \n*****\n");
    printf("Enter the Infix expression:\n");
    fgets(infixExp, 100, stdin);
    infToPre(infixExp);
    return 0;
}


/*
SampleInput: (A + B) * (C + D)
Sample Output:  * + A B + C D
*/
