/*

This program is about merging two Linked list. Here the user is going to enter
values of first and second linked list.
It will merge the two linked lists into one linked list by comparing the each
and every node values and convert into one linked list.

*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void Create(int Array1[], int size) {
    int i;
    struct Node *temp, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = Array1[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < size; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = Array1[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void Create2(int Array2[], int size) {
    int i;
    struct Node *temp, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = Array2[0];
    second->next = NULL;
    last = second;
    for (i = 1; i < size; i++) {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = Array2[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void Display(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void Merge(struct Node *p, struct Node *q) {
    struct Node *last;
    /*Merging the two linkedlists and making it as third linkedlist
    if the condition satisfies*/
    if (p->data < q->data) {
        third = last = p;
        p = p->next;
        third->next = NULL;
    } else {
          third = last = q;
          q = q->next;
          third->next = NULL;
    }
    while (p && q) {
        if (p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
      } else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
      }
  }
  /* Checking whether any node is left in the first and second linkedlist
  if so merging those nodes as well. */
  if (p)
      last->next = p;
  if (q)
      last->next = q;
}

int main() {
    int *Array1, *Array2;
    int size;
    printf("Enter the size of the array: \n");
    scanf("%d", &size);
    Array1 = (int *)malloc(size * sizeof(int));
    Array2 = (int *)malloc(size * sizeof(int));
    printf("Enter first LL Elements: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &Array1[i]);
    }
    Create(Array1, size);
    printf("Enter second LL Elements: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &Array2[i]);
    }
    Create2(Array2, size);
    Merge(first, second);
    Display(third);
    return 0;
}

// Output:-
/*
Enter the size of the array:
5
Enter first LL Elements:
2
4
7
8
9
Enter second LL Elements:
1
2
3
4
5

1 2 2 3 4 4 5 7 8 9

Time Complexity:- O(m+n)
Space Complexity:- O(1)

*/
