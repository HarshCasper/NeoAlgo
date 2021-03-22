/*
C Program to check whether a number is Palindrome or not
An integer is a palindrome if the reverse of that number is equal to the original number.
Example of Palindromes are 11,44,101,121,
*/
 #include <stdio.h>
#include <stdlib.h>

typedef struct node{
    short num;
    struct node *next;
    struct node *prev;
} node;

typedef node* ptrNode;
typedef enum {false,true} bool;

//Init a new Node
ptrNode getNode(short n){
    ptrNode newNode = (ptrNode)malloc(sizeof(node));
    newNode->next = newNode->prev = NULL;
    newNode->num = n;
    return newNode;
}

//Append a new value
void appendNode(ptrNode *s, ptrNode *e, short n){
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
    long n; //number to test

    printf("Insert a number:\n");
    scanf("%ld",&n);
    for(int k = n; k; k/=10)
        appendNode(&start,&end,(short)(k%10));

    printf("\n\n%ld %s palindrome", n, (verifyPalindromeDoubleLinkList(start,end))?"is":"isn't");
    freeMemory(&start,&end);

    return EXIT_SUCCESS;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
