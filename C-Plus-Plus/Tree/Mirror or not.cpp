#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to
   left child and a pointer to right child */
struct Node
{
    int data;
    Node* left, *right;
};

/* Given two trees, return true if they are
   mirror of each other */
int areMirror(Node* a, Node* b)
{
    /* Base case : Both empty */
    if (a==NULL && b==NULL)
        return true;

    // If only one is empty
    if (a==NULL || b == NULL)
        return false;

    /* Both non-empty, compare them recursively
     Note that in recursive calls, we pass left
     of one tree and right of other tree */
    return  a->data == b->data &&
            areMirror(a->left, b->right) &&
            areMirror(a->right, b->left);
}

/* Helper function that allocates a new node */
Node* newNode(int data)
{
    Node* node = new Node;
    node->data  = data;
    node->left  =  node->right  = NULL;
    return(node);
}
int main()
{
    Node *a = newNode(1);
    Node *b = newNode(1);
    a->left = newNode(2);
    a->right = newNode(4);
    a->left->left  = newNode(3);
    a->left->right = newNode(5);

    b->left = newNode(4);
    b->right = newNode(2);
    b->right->left = newNode(5);
    b->right->right = newNode(3);

    areMirror(a, b)? cout << "Yes" : cout << "No";

    return 0;
}

// Input -     1                            1
//            / \                          / \
//           2   4                        4   2
//              / \                      / \
//             3   5                    5   3


// Output =  Yes
