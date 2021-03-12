/*

This program is about merging two Linkedlist. Here user going to enter values of
first and second linkedlist. It will merge the
two linkedlists into one linkedlist by comparing the each and every node values
and convert into one linkelist in the ascending order.

*/
#include <stdio.h>
#include <stdlib.h>
// Defining a structure
struct Node {
  int data;
  struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;
void Create(int A[], int n) {
  int i;
  struct Node *t, *last;
  // Creating a node dynamically for first linkedlist
  first = (struct Node *)malloc(sizeof(struct Node));
  // Assiging a data to it.
  first->data = A[0];
  // making first next to null
  first->next = NULL;
  // Making last pointer to point on first
  last = first;
  for (i = 1; i < n; i++) {
    // Creating a t node
    t = (struct Node *)malloc(sizeof(struct Node));
    // Assigning a data to it.
    t->data = A[i];
    // Making t next to null.
    t->next = NULL;
    // Making last next pointer to point on t.
    last->next = t;
    // Making last pointer to point on t.
    last = t;
  }
}
void Create2(int A[], int n) {
  int i;
  // Defining struct pointer
  struct Node *t, *last;
  // Creating a node dynamically for second linkedlist
  second = (struct Node *)malloc(sizeof(struct Node));
  // Assiging a data to it
  second->data = A[0];
  // Making second next to null
  second->next = NULL;
  // Making last pointer to point on second
  last = second;

  for (i = 1; i < n; i++) {
    // Creating a t node
    t = (struct Node *)malloc(sizeof(struct Node));
    // Assigning a data to it.
    t->data = A[i];
    // Making t next to null.
    t->next = NULL;
    // Making last next pointer to point on t.
    last->next = t;
    // Making last pointer to point on t.
    last = t;
  }
}
void Display(struct Node *p) {
  while (p != NULL) {
    // It will display the value until condition becomes false.
    printf("%d ", p->data);
    // Making p point on p next.
    p = p->next;
  }
  printf("\n");
}
void Merge(struct Node *p, struct Node *q) {
  // Defining struct pointer
  struct Node *last;
  // Checking whether a q data is greater than p data
  if (p->data < q->data) {
    // Assigning third,last to p.
    third = last = p;
    // Making as p pointer to point on p's next.
    p = p->next;
    // Making third next pointer to point on null
    third->next = NULL;
  } else {
    // Making third and last pointers to point on q
    third = last = q;
    // Making q pointer to point on q's next
    q = q->next;
    // Making third next pointer to point on null.
    third->next = NULL;
  }
  while (p && q) {
    // Checking whether a q data is greater than p data
    if (p->data < q->data) {
      // Making last next pointer to point on p.
      last->next = p;
      // Making last pointer to point on p.
      last = p;
      // Making p pointer to point on p's next.
      p = p->next;
      // Making last next pointer to point on null.
      last->next = NULL;
    } else {
      // Making last next pointer to point on q.
      last->next = q;
      // Making last pointer to point on q.
      last = q;
      // Making q's pointer to point on q's next.
      q = q->next;
      // Making last next pointer to point on null.
      last->next = NULL;
    }
  }
  // Moving last next pointer to point on p until the condition becomes false.
  if (p)
    last->next = p;
  // Moving last next pointer to point on q until the condition becomes false.
  if (q)
    last->next = q;
}
int main() {
  // Defining struct pointer
  struct Node *t;
  // Defining integer type pointers
  int *A, *B;
  // Declaring variable
  int n;
  printf("Enter the size of the array: \n");
  // Asking user to enter size of the array.
  scanf("%d", &n);
  // Creating an first array dynamically
  A = (int *)malloc(n * sizeof(int));
  // Creating an second array dynamically
  B = (int *)malloc(n * sizeof(int));
  printf("Enter first LL Elements: \n");
  for (int i = 0; i < n; i++) {
    // Asking user to enter first array values.
    scanf("%d", &A[i]);
  }
  // Calling function to create first Linkedlist
  Create(A, n);
  printf("Enter second LL Elements: \n");
  for (int i = 0; i < n; i++) {
    // Asking user to enter second array values.
    scanf("%d", &B[i]);
  }
  // Calling function to create second Linkedlist
  Create2(B, n);
  // Calling Merge function to merge both the Linkedlist.
  Merge(first, second);
  // Displaying the Linkedlist.
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

*/
