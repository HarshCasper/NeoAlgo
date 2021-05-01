/*
Detecting a loop/cycle in a linked list.
Algorithm/Approach:
We use two pointers- slow and fast pointers to traverse the linked list.
If there is a loop in the linked list, then we will never encounter a NULL pointer. 
Also, since we are using a slow and a fast pointer, these two pointers will point the same node at one oint of time.
This indicates a loop/cycle in linked list.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;
Node *head;

Node * newNode(int val) {
    Node *new_node = (Node *)malloc(sizeof(Node ));
    new_node -> data = val;
    new_node -> next = NULL;
    return new_node;
}

void insertNode(int value) {
    /* inserting a new node */
    Node *new_node = newNode(value);
    if (!head) {
        head = new_node;
    }
    else {
        new_node -> next = head;
        head = new_node;
    }
}

int detectLoop(Node *head) {
    Node *fastPtr, *slowPtr;
    /* using two pointer */
    slowPtr = fastPtr = head;
    do {
        slowPtr = slowPtr -> next;
        fastPtr = fastPtr -> next;
        fastPtr = fastPtr ? fastPtr -> next : fastPtr;
    } while (fastPtr && slowPtr && fastPtr != slowPtr);
    return slowPtr == fastPtr;
}

void display() {
    Node *p = head;
    while (p) {
        printf("%d ", p -> data);
        p = p -> next;
    }
    printf("\n");
}

int main() {
    int size, val;
    printf("Enter the size of linked list:\n");
    scanf("%d", &size);
    printf("Enter the elements of the linked list:\n");
    for (int i = 0; i < size; i ++) {
        scanf("%d", &val);
        insertNode(val);
    }
    
    /* before introducing a loop */
    if (detectLoop(head)) {
        printf("A loop has been detected in the linked list!\n");
    }
    else {
        printf("No loop detected in the linked list!\n");
    }

    /* after introducing a loop */
    head -> next -> next = head;
    if (detectLoop(head)) {
        printf("A loop has been detected in the linked list!\n");
    }
    else {
        printf("No loop detected in the linked list!\n");
    }
    
    return 0;
}

/*

Sample I/O:
Enter the size of linked list:
5
Enter the elements of the linked list:
1
2
3
4
5
No loop detected in the linked list!
A loop has been detected in the linked list!

Time Complexity: O(n)
Space complexity: O(1)

*/
