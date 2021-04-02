/*C program to find Minimum Element in a Stack in Constant Time i.e O(1).
    Maintain an additional stack that will keep track of the minimum element
    of the Original Stack.

    Every push to the primary STACK, compare the current value
    with the TOS of the temporary Stack and IF the current value is less
    than the TOS push the current value to the temporary STACK,such that
    the minimum element is always at the top of the STACK

*/

#include <stdio.h>
#include <malloc.h>

typedef struct Node {
  int value;
  struct Node *next;
} Node;

/* Stack1 pointer points to the original stack and stack2 pointer
   points to the temporary stack which will hold the minimum values
*/
Node *stack1 = NULL, *stack2 = NULL;

// check whether stack is empty or not
int isEmpty(Node *head) {
  // When stack-1 is empty return true
  if (head == NULL) {
    return 1;
  }
  return 0;
}

// Dynamically generate the node
Node *gen_node(int val) {
  Node *newnode;
  newnode = (Node *)malloc(sizeof(Node));
  if (newnode == NULL) {
    printf("\nMemory was not allocated");
    return 0;
  } else {
    newnode->value = val;
    newnode->next = NULL;
    return newnode;
  }
}

// Returns the top of the temporary stack
int peek() {
  int topVal;
  if (stack2 != NULL) {
    topVal = stack2->value;
  }
  return topVal;
}

// Push the element at the top of the stack
void push() {
  int val;
  Node *newNode, *temp;
  scanf("%d", &val);
  newNode = gen_node(val);

  if (stack1 == NULL) {
    stack1 = newNode;
    stack2 = newNode;
    stack1->next = stack2->next = NULL;
  } else {
    /* IF passed value is less than TOS of the temporary stack i.e stack2
        push the value,such that minimum element is always at the TOS of stack2
    */
    if (val <= peek()) {
      temp = stack2;
      stack2 = newNode;
      stack2->next = temp;
    }

    // Push data to original stack i.e stack1
    temp = stack1;
    stack1 = newNode;
    stack1->next = temp;
  }
}

int pop() {
  Node *temp;
  int tempVal;

  if (isEmpty(stack1)) {
    printf("\nStack is empty");
    return;
  } else {
    /* pop the min element from temporary stack ,if the value at originl STACK
     matches,such that minimum element is always at the top
     */
    if (stack1->value == peek()) {
      temp = stack2;
      stack2 = stack2->next;
    }
    temp = stack1;
    tempVal = temp->value;
    stack1 = stack1->next;
    free(temp);
  }
  return tempVal;
}

// Finding the minimum element from the temporary stack
int findMin() { peek(); }

int main() {
  int size, i;
  printf("Enter the size of the Stack:");
  scanf("%d",&size);

  printf("\nEnter the elements of the Stack:\n");
  for (i = 0; i < size; i++) {
    push();
  }

  printf("\n%d is popped from the stack", pop());
  printf("\nSmallest element in the Current Stack: %d", peek());

  return 0;
}

/*
  Time complexity: O(1) for finding the minimum
  Space complexity: O(n)
  
  Sample input/output:
  Enter the size of the Stack:5

  Enter the elements of the Stack:
  11
  5
  7
  2
  -5

  -5 is popped from the stack:
  Smallest element in the Current Stack: 2
  
 */
