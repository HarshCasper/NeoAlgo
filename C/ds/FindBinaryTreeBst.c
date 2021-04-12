/* C Program to find whether a Binary Tree is a Binary Search Tree.
    This problem is solved using In-order traversal.We start with root node,
    and during the traversal , we compare the previous element with the current
   element and during that if we found current is greater than previous ,we
   conclude  that it is not a Binary Search Tree*/

#include <malloc.h>
#include <stdio.h>

// structure of the Node
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

// structure of the queue
struct Queue {
  struct Node *data;
  struct Queue *next;
};

// check whether Queue is empty or not
int isEmpty(struct Queue *q) {
  if (q == NULL) {
    return 1;
  }
  return 0;
}

// enqueue the element at the rear end
int enQueue(struct Queue **f, struct Queue **r, struct Node *data) {
  struct Queue *q;
  /*create new node*/
  q = (struct Queue *)malloc(sizeof(struct Queue));
  q->data = data;
  q->next = NULL;

  // If queue is empty
  if (*f == NULL) {
    *f = q;
  } else {
    (*r)->next = q;
  }

  *r = q;
  return 0;
}

// dequeue the element from the front end
struct Node *deQueue(struct Queue **f) {
  struct Node *temp;

  if (isEmpty(*f)) {
    printf("\n Queue is empty");

  } else {
    temp = (*f)->data;
    (*f) = (*f)->next;
  }

  return temp;
}

// insertion in Binary Tree
int insertBinaryTree(struct Node **root, int data) {
  struct Node *temp, *cur;
  struct Queue *f = NULL, *r = NULL;

  // new node creation based on data
  temp = (struct Node *)malloc(sizeof(struct Node));
  if (temp == NULL) {
    return -1;
  } else {
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
  }

  if (*root == NULL) {
    *root = temp;
    return;
  }
  // queue used to insert data to the binary tree
  enQueue(&f, &r, *root);
  while (!isEmpty(f)) {

    cur = deQueue(&f);

    // move left
    if (cur->left == NULL) {
      cur->left = temp;
      break;
    } else {
      enQueue(&f, &r, cur->left);
    }
    if (cur->right == NULL) {
      cur->right = temp;
      break;
    } else {
      enQueue(&f, &r, cur->right);
    }
  }

  return 0;
}

// check whether Binary Tree is Binary Search Tree
int curElement = 0, flag = 1;
int checkBST(struct Node *root) {
  if (root == NULL) {
    return;
  }
  checkBST(root->left);
  if (curElement != 0 && (root->data) <= curElement) {
    flag = 0;
  }
  // store the previous element
  curElement = root->data;
  checkBST(root->right);
  return flag;
}

int main() {

  int n, i, value, status;
  struct Node *root = NULL;

  printf("Enter the no of elements in the Binary Tree:");
  scanf("%d", &n);

  printf("\nEnter the values of the Binary Tree:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &value);
    insertBinaryTree(&root, value);
  }

  status = checkBST(root);

  if (status) {
    printf("\nThe Entered Binary Tree is a Binary Search Tree:");
  } else {
    printf("\nThe Entered Binary Tree is Not a Binary Search Tree");
  }

  return 0;
}

/*
  Sample input/output:
  Enter the no of elements in the Binary Tree:8

  Enter the values of the Binary Tree:
  204
  198
  207
  99
  199
  205
  251
  4

  The Entered Binary Tree is a Binary Search Tree

  Time complexity: O(n)
  Space complexity: O(n)
 */
