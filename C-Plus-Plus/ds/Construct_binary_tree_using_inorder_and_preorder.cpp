/*
Construct a binary tree using inorder and preorder.

Given preorder and inorder traversal of a tree, construct the binary tree.
Problem link: https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/
e.g.
Input :
Preorder : [1, 2, 3]
Inorder : [2, 1, 3]

        Return :
                    1
                   / \
                  2   3
(To verify the tree I will print its PostOrder traversal i.e [2, 3, 1].)
*/

#include <bits/stdc++.h>
using namespace std;
// structure to define the tree
struct TreeRoot
{
    // data varible of type int to store the integer data in the node.
    int data;
    // left pointer of the same type as of node to point at left subtree of the node.
    struct TreeRoot *left;
    // right pointer of the same type as of node to point at right subtree of the node.
    struct TreeRoot *right;
    // constructor to initialize/ create the node.
    TreeRoot(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void postorder(TreeRoot *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

TreeRoot *buildTree(vector<int> &preorder, vector<int> &inorder, int start, int end)
{
    // a static variable to keep the track of preorder vector.
    static int index = 0;
    if (start > end)
        return NULL;
    // to store the value at given index in preorder vector.
    int current = preorder[index];
    // after storing the value increment the index.
    index++;
    // creating the node of the current element.
    TreeRoot *node = new TreeRoot(current);
    // a varible to find the position of the element in the inorder vector.
    if (start == end)
        return node;
    int position;
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == current)
            position = i;
    }
    // creating the left sub-tree.
    node->left = buildTree(preorder, inorder, start, position - 1);
    // creating the right sub-tree.
    node->right = buildTree(preorder, inorder, position + 1, end);
    // return node.
    return node;
}

int main()
{
    cout << "Enter the number of node in the tree: ";
    int nodes;
    cin >> nodes;
    vector<int> preorder(nodes);
    cout << "Enter the elements of the prorder: ";
    for (auto &it : preorder)
        cin >> it;
    cout << "Enter the elements of the inorder: ";
    vector<int> inorder(nodes);
    for (auto &it : inorder)
        cin >> it;
    // a tree is built by passing the preorder, inorder the location of first and last elements of the vectors.
    TreeRoot *root = buildTree(preorder, inorder, 0, nodes - 1);
    // passed this tree to postorder function to print its postorder traversal
    cout << "The postorder traversal of the created tree is: ";
    postorder(root);
    return 0;
}

/*
    Sample Input/Output: 

    Input #1: 
        Enter the number of node in the tree: 5
        Enter the elements of the prorder: 1 2 4 5 3
        Enter the elements of the inorder: 4 2 5 1 3
    Output #1: 
        The postorder traversal of the created tree is: 4 5 2 3 1

    Input #2: 
        Enter the number of node in the tree: 3
        Enter the elements of the prorder: 1 2 3
        Enter the elements of the inorder: 2 1 3
    Output #2: 
        The postorder traversal of the created tree is: 2 3 1    

    Input #3: 
        Enter the number of node in the tree: 5
        Enter the elements of the prorder: 1 2 4 3 5
        Enter the elements of the inorder: 4 2 1 5 3
    Output #3: 
        The postorder traversal of the created tree is: 4 2 5 3 1

    Time Complexity = O(n^2) {Worst Case: when tree is skewed}
    Space Complexity = O(n^2) {Worst Case: when tree is skewed}
*/

