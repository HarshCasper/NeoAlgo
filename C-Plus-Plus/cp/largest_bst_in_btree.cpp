/*Problem Statement: 
Given a Binary Tree, 
write a program that returns the size of the largest subtree which is also a Binary Search Tree (BST) */

#include <bits/stdc++.h>
using namespace std;

class node
{
  public:
    int data;
  node * left;
  node * right;

  node(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};
node* build(int *preorder_tree, int *postorder_tree, int s, int e)
{
  static int i = 0;
  int index = -1;
  if (s > e)
  {
    return NULL;
  }

  //making the root node as the first node of the preorder form
  node *root = new node(preorder_tree[i++]);
  if (s == e)
  {
    return root;
  }

  for (int j = s; s <= e; j++)
  {
    if (postorder_tree[j] == root->data)
    {
      index = j;
      break;
    }
  }

  root->left = build(preorder_tree, postorder_tree, s, index - 1);
  root->right = build(preorder_tree, postorder_tree, index + 1, e);
  return root;

}

bool isbst(node *root, int min, int max)
{
  if (root == NULL)
  {
    return true;
  }

  /*If the left subtree is small in value and the right subtree is big in value than the root,
  then it is a BST */
  if (root->data >= min && root->data <= max && isbst(root->left, min, root->data) && isbst(root->right, root->data, max))
  {
    return true;
  }

  return false;

}

int nodes(node *root)
{
  if (root == NULL)
  {
    return 0;
  }

  return nodes(root->left) + nodes(root->right) + 1;
}

int isvalidbst(node *root)
{
  if (root == NULL)
  {
    return NULL;
  }

  if (isbst(root, INT_MIN, INT_MAX))
  {
    return nodes(root);
  }

  return max(isvalidbst(root->left), isvalidbst(root->right));
}

int main()
{
  int total_nodes;
  cout << "Total nodes in binary tree: " << endl;
  cin >> total_nodes;
  int preorder_tree[total_nodes];
  cout << "Enter preorder form: " << endl;
  for (int i = 0; i < total_nodes; i++)
  {
    cin >> preorder_tree[i];
  }

  cout << "Enter postorder form: " << endl;
  int postorder_tree[total_nodes];
  for (int i = 0; i < total_nodes; i++)
  {
    cin >> postorder_tree[i];
  }

  node *root = build(preorder_tree, postorder_tree, 0, total_nodes - 1);
  cout << "Total nodes in the largest tree: " << isvalidbst(root);
  return 0;
}
/*Example:-

Input:-
Total nodes in binary tree: 
4
Enter preorder form: 
60 65 50 70
Enter postorder form: 
50 65 60 70

Output:-
Total nodes in the largest tree: 2

Time Complexity: O(n)
Space Complexity: O(n)
*/

