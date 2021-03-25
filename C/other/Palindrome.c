/*
Check palindrome words using double linked list in C

Input:
aabbaa

Output:
aabbaa is palindrome
*/

#include <stdio.h>
#include <stdlib.h>

   struct node{
    char num;
    struct node *next;
    struct node *prev;
} node;

typedef struct node* ptrNode;
typedef enum {false,true} bool;

//Init a new Node
ptrNode getNode(char n){
    ptrNode newNode = (ptrNode)malloc(sizeof(node));
    newNode->next = newNode->prev = NULL;
    newNode->num = n;
    return newNode;
}

//Append a new value
void appendNode(ptrNode *s, ptrNode *e, char n){
    ptrNode newNode = getNode(n);

    if(*s){
        (*e)->next = newNode;
        newNode->prev = *e;
        *e = newNode;
    }else
        *s = *e = newNode;
}

//Verify for palindrome list
bool verifyPalindromeDoubleLinkList(ptrNode s, ptrNode e){
    while(s!=e && e->next!=s){
        if(s->num!=e->num)
            return false;
        s=s->next;
        e=e->prev;
    }
    return true;
}

//memory deallocation
void freeMemory(ptrNode *s, ptrNode *e){
    ptrNode temp;
    while(*s){
        temp = *s;
        *s=(*s)->next;
        free(temp);
    }
    *e=*s;
}

int main(){
    ptrNode start = NULL, end = NULL;//Start and End double linked list
    char n[100]; //number to test

    printf("Insert a string:\n");
    scanf("%s",n);
    for(char* k =n; *k!='\0'; k++)
        appendNode(&start,&end,*k);

    printf("\n\n%s %s palindrome", n, (verifyPalindromeDoubleLinkList(start,end))?"is":"isn't");
    freeMemory(&start,&end);

    return EXIT_SUCCESS;
}
