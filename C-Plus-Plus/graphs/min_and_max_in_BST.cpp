/*
 Program to find the maximum and minimum value in a Binary search Tree.
 The maximum value in the BST will be the right most node of the right sub-tree
 The minimum value in the BST will be the left most node of the left sub-tree
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

// Function to insert item in a tree
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

// Function to find the minimum value in a BST
int minValue()
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}

// Function to find the maximum value in a BST
int maxValue()
{
    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp->data;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        insertItem(arr[i]);
    }
    cout<<maxValue()<<minValue();
    return 0;
}

/*
 Sample I/O
 Input format: The first line contains n - number of nodes in the tree
               The next line contains n spaced integers
 Output format: Two spaced integers denoting max and min value respectively.
 Example:
 5
 30 60 10 63 25

 Output - 63 10

 Explanation:
    30
   /  \
  10  60
    \   \
    25   63
 Max-element - 63 (rightmost element)
 Min-element - 10 (leftmost element)

*/

/*
 Complexity:
 Time complexity: O(Height of tree)
 Space complexity: O(1)
*/
