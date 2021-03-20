/*C program to find whether a linked list is palindrome or not
Using two pointers approach i.e slow(moves at x speed)pointer and fast(moves at
2x speed)pointer By storing first half of the linked list in an array and then
comparing each element from the other half of the linked list
with the elements of array in reverse order till it get exhausted.

Note:when no of elements are odd in Linked List skip the middle element
Ex- Linked_List={1,2,3,4,3,2,1},size=7
        Storing the first half in an array
        arr=[1,2,3]

        Linked_List[4]==arr[2]
        Linked_List[5]==arr[1]
        ...
        ...
        Palindrome(If all elements from array are matched)
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
