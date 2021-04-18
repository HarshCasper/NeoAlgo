/*Problem Statement:
You are given a binary tree, 
your task is to replace each node of the binary tree by the sum of its child nodes. */

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

node* buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void print(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

int replaceSum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL and root->right == NULL)
    {
        return root->data;
    }

    int lsum = replaceSum(root->left);
    int rsum = replaceSum(root->right);
    int temp = root->data;
    root->data = lsum + rsum;

    return temp + root->data;
}

int main()
{
    cout << "Enter the nodes of the binary tree: " << endl;
    node *root = buildTree();
    cout << "Initial tree: "<<endl;
    print(root);
    replaceSum(root);
    cout << "Final tree: "<<endl;
    print(root);
    return 0;
}

/*
Example: 
Input:-
Enter the nodes of the binary tree:
1 2 -1 -1 3 -1 -1

Output:-
Initial tree: 1 2 3
Final tree: 5 2 3

Time Complexity: O(n)
Space Complexity: O(n)
*/

