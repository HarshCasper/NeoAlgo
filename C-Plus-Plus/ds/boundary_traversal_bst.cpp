/* 
   Program to print the boundary traversal of a Binary Search Tree.
   The given approach uses iterative method to print the boundary nodes of 
   the given Binary Search Tree.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};
Node* root = NULL;

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to insert item in a BST
void insertItem(int item)
{
    Node *newnode = newNode(item);
    if(!root) {
        root = newnode;
        return;
    }
    Node *cur, *prev;
    cur = root;
    while(cur!= NULL) {
        prev = cur;
        if(cur->data > item)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if(prev->data > item)
        prev->left = newnode;
    else
        prev->right = newnode;
}

// Function to add leaf nodes of the Binary Search Tree
void addLeafNodes(Node* root, vector<int>& boundary) {
        if (root->left == NULL && root->right == NULL) {
            boundary.push_back(root->data);
            return;
        }
        if(root->left) addLeafNodes(root->left, boundary);
        if(root->right) addLeafNodes(root->right, boundary);
    }

// Function to print to boundary of a BST
vector<int> boundaryTraversal() {
    if(root == NULL)
        return {};

    vector<int> boundary;

    if(root->left != NULL && root->right != NULL)
        boundary.push_back(root->data);

    Node *curr = root->left;
    while(curr != NULL) {
        if(curr->left != NULL && curr->right != NULL)
            boundary.push_back(curr->data);
        if(curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }

    addLeafNodes(root, boundary);

    curr = root->right;

    vector<int> rightBoundary;
    
    while(curr != NULL) {
        if(curr->left != NULL && curr->right != NULL)
            rightBoundary.push_back(curr->data);
        if(curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for(int i = rightBoundary.size() - 1; i >= 0; i--)
        boundary.push_back(rightBoundary[i]);

    return boundary;

}

// Printing Boundary Traversal
void printBoundary() {
    vector<int> boundary = boundaryTraversal();
    for (int i = 0; i < boundary.size(); ++i)
    {
        cout << boundary[i] << " ";
    }
}

int main() {
    cout << "Enter the number of nodes you want to enter in the tree: ";
    int n, item;
    cin >> n;
    cout << "Start entering the nodes separated by space: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> item;
        insertItem(item);
    }
    cout << "\nBoundary Traversal is: ";
    printBoundary();
}

/*
  Sample Input/Output:
  Input:
  The first line contains a single integer n - number of nodes in the tree
  The next line contains n spaced integers
  Output: 
  Contains spaced integers representing the boundary of the tree
  
  Sample Input:
  Enter the number of nodes you want to enter in the tree: 8
  Start entering the nodes separated by space: 
  20 8 4 12 10 14 25
  Sample Output:
  Boundary Traversal is: 20 8 4 10 14 25 
  
  Explanation: Tree is
        20
       /  \
      8   25
     / \
    4  10
         \
         14

  Complexity Analysis:
  Time Complexity: O(n);
  Space Complexity: O(n);

*/

