#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct stack {
    int capacity, top;
    char* arr;
}stack;
/* creating a structure to implement stack */

int isEmpty(stack* s) {
    return s->top == -1;
}
/* to check if the stack is empty */

int isFull(stack* s) {
    return s->top == s->capacity - 1;
}
/* to check if the stack is full */

stack* createStack(int size) {
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->capacity = size;
    s->arr = (char*)malloc(size * sizeof(char));
    s->top = -1;
    return s;
}

void push(stack* s, char data) {
    s->arr[++s->top] = data;
}

char pop(stack* s) {
    return s->arr[s->top--];
}

void reverseWords(char sentence[100], int length) {
    stack* s = createStack(length);
    for (int i = 0; i < length; i++) {
        char letter = sentence[i];
        if ((!isspace(letter)) && (letter != '\n') && (letter != '\0')) {
            push(s, letter);
            /* anything other than an alphabet or number indicates that a word has ended */
        }
        else {
            while (!(isEmpty(s))) {
                printf("%c", pop(s));
            }
            printf("%c", letter);
        }
    }
}

int main() {
    int size, i = 0;
    char sentence[100];
    printf("Enter a sentence:\n");
    fgets(sentence, 100, stdin);
    printf("The sentence after reversing individual words is:\n");
    reverseWords(sentence, strlen(sentence));
    /* calling the reverseWords function */
    return 0;
}

/*
Sample Input1: Get me food
Sample Output1: teG em doof

Sample Input2: happy birthday
Sample Output2: yppah yadhtrib
*/

/*
Time complexity = O(n) [since each pop or push takes O(1) times]
Space Complexity = O(n)
*/