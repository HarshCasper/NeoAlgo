/* C program to find whether a linked list is palindrome or not.
We need to detect whether the front half of the list is the reverse of the second half.
By reversing the front half of the list and for that stack can be used.

We know the size of the linked list, we can iterate onto the first half of the elements in a for loop,
pushing each element onto a stack. Now, we iterate the rest of the linked list. At each step, we compare
the node to the top of the stack. If we complete the iteration without finding the difference, 
then the linked list is a palindrome.

*/
#include <bits/stdc++.h>
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

// Find palindrome in the linked list
int find_Palindrome(int size) {
  int arr[size / 2], i = 0, j = 0;
  struct Node *fast = head;
  struct Node *slow = head;
  /* Push elements from first half of the linked list onto array.
  When fast pointer (which is moving at 2x speed)reaches the end of the linked
  list, then we know we are at the middle
  */
  while (fast != NULL && fast->next != NULL) {
    arr[i] = slow->value;
    slow = slow->next;
    fast = fast->next->next;
    i++;
  }

  // Has odd number of elements,so skip the middle elements
  if (fast != NULL) {
    slow = slow->next;
  }
  j = i - 1;
  while (slow != NULL) {
    int val = arr[j];

    // If the value are different ,then it's not a palindrome
    if (val != slow->value) {
      return 0;
    }
    slow = slow->next;
    j--;
  }
  return 1;
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

  printf("\nLinked List after Insertion:");
  display();

  status = find_Palindrome(size);

  if (status) {
    printf("\nThe above Linked List is Palindrome");
  } else {
    printf("\nThe above Linked List is Not Palindrome");
  }

  return 0;
}

/*
Sample input/output:

Enter the size of the Linked List:7

Enter the value for the node:1

Enter the value for the node:2

Enter the value for the node:3

Enter the value for the node:4

Enter the value for the node:3

Enter the value for the node:2

Enter the value for the node:1

Linked List after Insertion:1 2 3 4 3 2 1
The above Linked List is Palindrome

Time complexity: O(n)
Space complexity: O(n)

*/
