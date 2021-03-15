/*
It is a Avl tree program. These are height balanced binary trees so, we need to
find out the balance factor i.e.,
Balance factor = Height of the left subtree - Height of right subtree.

Here this program going to converted all the inserted elements into balanced
tree. Below I have mentioned rules for balanced and Imbalanced tree.

if bf = |hl-hr|<=1 {-1,0,1} (Balanced tree)
if bf = |hl-hr|>1 (Imbalanced tree)

This program checks whether it is balance or imbalance. If it is Imbalance then
it will convert into balanced tree.

In order traversal of binary tree will always print the values in the sorted
order. The code has also included in order traversal as well.
so, You can also check whether the code is printing binary tree or not.

*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
  struct Node *lchild;
  int data;
  int height;
  struct Node *rchild;
} *root = NULL;
// Function to find out the height of the node
int NodeHeight(struct Node *p) {
  int hl, hr;
  hl = p && p->lchild ? p->lchild->height : 0;
  hr = p && p->rchild ? p->rchild->height : 0;

  return hl > hr ? hl + 1 : hr + 1;
}
int BalanceFactor(struct Node *p) {
  int hl, hr;
  hl = p && p->lchild ? p->lchild->height : 0;
  hr = p && p->rchild ? p->rchild->height : 0;

  return hl - hr;
}
struct Node *LLRotation(struct Node *p) {
  // lbf means Left balance factor and rbf means Right balance factor.
  int lbf, rbf;
  // p pointer will point on root node and pl will point on p's left.
  struct Node *pl = p->lchild;
  pl->height = 0;
  p->lchild = pl->rchild;
  pl->rchild = p;
  lbf = NodeHeight(p->lchild) + 1;
  rbf = NodeHeight(p->rchild) + 1;
  p->height = lbf - rbf;
  if (p == root)
    root = pl;
  return pl;
}
struct Node *LRRotation(struct Node *p) {
  int lbf, rbf;
  struct Node *pl = p->lchild;
  // plr means pl's right child
  struct Node *plr = pl->rchild;
  plr->height = 0;
  p->lchild = plr->rchild;
  pl->rchild = plr->lchild;
  plr->lchild = pl;
  plr->rchild = p;
  lbf = NodeHeight(p->lchild) + 1;
  rbf = NodeHeight(p->rchild) + 1;
  p->height = lbf - rbf;
  lbf = NodeHeight(pl->lchild) + 1;
  rbf = NodeHeight(pl->rchild) + 1;
  pl->height = lbf - rbf;
  if (p == root)
    root = plr;
  return plr;
}
struct Node *RRRotation(struct Node *p) {
  int lbf, rbf;
  // pr means p's right child
  struct Node *pr = p->rchild;
  pr->height = 0;
  p->rchild = pr->lchild;
  pr->lchild = p;
  lbf = NodeHeight(p->lchild) + 1;
  rbf = NodeHeight(p->rchild) + 1;
  p->height = lbf - rbf;
  if (p == root)
    root = pr;
  return pr;
}
struct Node *RLRotation(struct Node *p) {
  int lbf, rbf;
  struct Node *pr = p->rchild;
  // prl means pr's left child
  struct Node *prl = pr->lchild;
  prl->height = 0;
  p->rchild = prl->lchild;
  pr->lchild = prl->rchild;
  prl->rchild = pr;
  prl->lchild = p;
  lbf = NodeHeight(p->lchild) + 1;
  rbf = NodeHeight(p->rchild) + 1;
  p->height = lbf - rbf;
  lbf = NodeHeight(pr->lchild) + 1;
  rbf = NodeHeight(pr->rchild) + 1;
  pr->height = lbf - rbf;
  if (p == root)
    root = prl;
  return prl;
}
struct Node *RInsert(struct Node *p, int key) {
  struct Node *t = NULL;
  if (p == NULL) {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->height = 1;
    t->lchild = t->rchild = NULL;
    return t;
  }
  /*Checking values if the key value is less than p's data then it will assign
   to left child else
   assign to right child.
   */
  if (key < p->data)
    p->lchild = RInsert(p->lchild, key);
  else if (key > p->data)
    p->rchild = RInsert(p->rchild, key);
  p->height = NodeHeight(p);
  // Based upon the balance factor it will perform the rotation.
  if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    return LLRotation(p);
  else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    return LRRotation(p);
  else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    return RRRotation(p);
  else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    return RLRotation(p);
  return p;
}
void Inorder(struct Node *p) {
  if (p) {
    Inorder(p->lchild);
    printf("%d ", p->data);
    Inorder(p->rchild);
  }
}
int main() {
  int ch, a;
  do {
    printf("\n1. Insert the value in Avl tree : \n");
    printf("2. In order traversal: \n");
    printf("3. Exit\n");
    printf("Enter you choice: ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      printf("1. Enter the number: \n");
      scanf("%d", &a);
      root = RInsert(root, a);
      break;
    case 2:
      Inorder(root);
      break;
    }
  } while (ch < 3);
  free(root);
  root = NULL;
  return 0;
}
/*
Output:-


1. Insert the value in Avl tree :
2. In order traversal:
3. Exit
Enter you choice: 1
1. Enter the number:
40

1. Insert the value in Avl tree :
2. In order traversal:
3. Exit
Enter you choice: 1
1. Enter the number:
20

1. Insert the value in Avl tree :
2. In order traversal:
3. Exit
Enter you choice: 1
1. Enter the number:
50

1. Insert the value in Avl tree :
2. In order traversal:
3. Exit
Enter you choice: 1
1. Enter the number:
10

1. Insert the value in Avl tree :
2. In order traversal:
3. Exit
Enter you choice: 1
1. Enter the number:
30

1. Insert the value in Avl tree :
2. In order traversal:
3. Exit
Enter you choice: 1
1. Enter the number:
5

1. Insert the value in Avl tree :
2. In order traversal:
3. Exit
Enter you choice: 1
1. Enter the number:
25

1. Insert the value in Avl tree :
2. In order traversal:
3. Exit
Enter you choice: 1
1. Enter the number:
35

1. Insert the value in Avl tree :
2. In order traversal:
3. Exit
Enter you choice: 1
1. Enter the number:
27

1. Insert the value in Avl tree :
2. In order traversal:
3. Exit
Enter you choice: 1
1. Enter the number:
60

1. Insert the value in Avl tree :
2. In order traversal:
3. Exit
Enter you choice: 2
5 10 20 25 27 30 35 40 50 60

*/
