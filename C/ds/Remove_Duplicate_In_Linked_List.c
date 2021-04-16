/* C Program to Remove Duplicates from a Unsorted Linked List
Without using any Extra Space i.e while finding Duplicates we can't use any Data
Structure to store values. Then we can use two pointers approach :current and
runner ,current iterates through the linked list and runner check all subsequent
nodes for every current and try to find duplicates in the list.

*/

#include <malloc.h>
#include <stdio.h>

// structure of a node in a linked list
struct Node {
  int value;
  struct Node *next;
};

struct Node *head = NULL;

// Dynamically generate the node
struct Node *gen_node(int val) {
  struct Node *newnode;
  newnode = (struct Node *)malloc(sizeof(struct Node));
  if (newnode == NULL) {
    printf("\nMemory was not allocated");
    return 0;
  } else {
    newnode->value = val;
    newnode->next = NULL;
    return newnode;
  }
}

// Insert node at the beginning of the linked list
void insert_node_first() {
  int val;
  struct Node *newNode, *temp;
  printf("\nEnter the value for the node:");
  scanf("%d", &val);
  newNode = gen_node(val);
  if (head == NULL) {
    head = newNode;
    head->next = NULL;
  } else {
    temp = head;
    head = newNode;
    head->next = temp;
  }
}

/*
  Two pointers current and runner is used
  current will iterate through the linked list and runner will
  check all the subsequent nodes for duplicates
*/
void removeDup() {
  struct Node *cur = head;
  while (cur != NULL) {
    struct Node *runner = cur;
    // Remove all future nodes that have the same value
    while (runner->next != NULL) {
      if (runner->next->value == cur->value) {
        runner->next = runner->next->next;
      } else {
        runner = runner->next;
      }
    }
    cur = cur->next;
  }
}

// Display the entered list
void display() {
  struct Node *temp;
  temp = head;
  while (temp != NULL) {
    printf("%d ", temp->value);
    temp = temp->next;
  }
}

int main() {
  int size, i, val, status;
  printf("Enter the size of the Linked List:");
  scanf("%d", &size);

  for (i = 0; i < size; i++) {
    insert_node_first();
  }

  printf("\nLinked List with Duplicates:");
  display();
  removeDup();
  printf("\nLinked List after Removing Duplicates:");

  display();

  return 0;
}

/*
  Sample input/output:

  Enter the size of the Linked List:5

  Enter the value for the node:1

  Enter the value for the node:5

  Enter the value for the node:3

  Enter the value for the node:5

  Enter the value for the node:7

  Linked List with Duplicates:7 5 3 5 1
  Linked List after Removing Duplicates:7 5 3 1

  Time complexity: O(n^2) for finding duplicates
  Space complexity: O(n)

*/
