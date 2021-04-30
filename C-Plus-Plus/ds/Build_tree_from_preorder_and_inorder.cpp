/*
Description : 
            User will be giving array of preorder and inorder traversal , 
            you have to build and display a binary tree in inorder traversal format.
*/

#include <bits/stdc++.h>
using namespace std;

//base data
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//for searching the currr in inorder
int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

//for building the tree
Node *build_Tree(int preorder[], int inorder[], int start, int end)
{
    //it will keep track in preorder array
    static int index = 0;
    if (start > end)
    {
        return NULL;
    }

    //making new node with first element in preorder
    int curr = preorder[index];
    index++;
    Node *node = new Node(curr);

    //if there is single element in inorder
    //there is no left and right child
    if (start == end)
    {
        return node;
    }

    //now we have to build left and right subtree
    // so we will search the curr in inorder (position)
    int pos = search(inorder, start, end, curr);

    //using recursion we will form the tree
    node->left = build_Tree(preorder, inorder, start, pos - 1);
    node->right = build_Tree(preorder, inorder, pos + 1, end);

    return node;
}

//function for printing tree in inorder format
void print_in_inorder(Node *root)
{
    //base case
    if (root == NULL)
    {
        return;
    }
    //using recursion
    print_in_inorder(root->left);
    cout << root->data << " ";
    print_in_inorder(root->right);
}

int main()
{
    //size of preorder array
    int pre;
    cout << "Enter the size of preorder array : " << endl;
    cin >> pre;
    int preorder[pre];

    //taking input in preorder
    cout << "Enter the elements in postorder : " << endl;
    for (int i = 0; i < pre; i++)
    {
        cin >> preorder[i];
    }

    //size will be same
    int inorder[pre];
    //taking input in inorder
    cout << "Enter the elements in inorder : " << endl;
    for (int i = 0; i < pre; i++)
    {
        cin >> inorder[i];
    }
    Node *root = build_Tree(preorder, inorder, 0, pre - 1);

    //printing tree in inorder format.
    cout << "Tree in inorder traversal : " << endl;
    print_in_inorder(root);

    return 0;
}

/*
Time complexity : O(n)
Space complexity : O(1)
*/

/*
Test Case :
 Input:
 Enter the size of preorder array :
 5
 Enter the elements in postorder :
 1 2 4 3 5
 Enter the elements in inorder :
 4 2 1 5 3

 Output :
 Tree in inorder traversal : 
  4 2 1 5 3
*/

