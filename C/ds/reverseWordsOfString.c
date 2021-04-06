/*
Reversing individual words of a string using stacks
Algorithm/Approach:
We iterate through the string character-by-character.
If the current character is not a space, or not a newline character or not a null character,
we push it into the stack
Otherwise, we pop the elements from the stack until it's empty. 
(Because a space or newline or null character marks the end of a word.)
*/

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
/* push a given element into the stack */

char pop(stack* s) {
    return s->arr[s->top--];
}
/* to pop the top element from stack */

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
Sample I/O:
Enter a sentence:
Get me food
The sentence after reversing individual words is:
teG em doof
*/

/*
Time complexity = O(n) [since each pop or push takes O(1) times]
Space Complexity = O(n)
*/