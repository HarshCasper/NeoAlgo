/*
Binary tree is a data structure that has at most 2 child node i.e. left and right child
For BFS traversal, we will traverse all nodes level by level. That means first root node
is traversed, then all the direct children of the root node is traversed.
Similarly we move to their children and so on.
*/
#include <bits/stdc++.h>
using namespace std;
/*structure of the binary tree*/
struct Node
{
    int info;                      //data part
    struct Node *left, *right;     //left and right node which will contain address of left and right subtree
};
/*function to create tree*/
struct Node* create()
{
    int data;
    Node *tree;
    tree = new Node;
    cout<<"\nEnter data to be inserted or type -1 : ";
    cin>>data;
    //condition for termination
    if(data == -1)
        return 0;
    tree->info=data;
    cout<<"Enter left child of "<<data;
    tree->left=create();
    cout<<"Enter right child of "<<data;
    tree->right=create();
    return tree;
};
/*
BFS traversal is similar to the Level Order Traversal. We will travel the
tree row wise i.e. first row then second and so on.
So first, we will push root node into the queue,then dequeue(the root node)
and enqueue all of its children. Print the node that was dequeued
Then repeat this process until queue becomes empty.
*/
void BFS_traversal(Node *root)
{
    if(root == NULL)
        return;
    queue<Node*> q;
    cout<<root->info<<" ";
    q.push(root);
    while(!q.empty())
    {
        root = q.front();
        q.pop();
        if(root->left)
        {
            cout<<root->left->info<<" ";
            q.push(root->left);
        }
        if(root->right)
        {
            cout<<root->right->info<<" ";
            q.push(root->right);
        }
    }
}
/*Driver Program*/
int main()
{
    Node *root = NULL;
    root = create();
    cout << "BFS Traversal of the tree is : ";
    BFS_traversal(root);
    return 0;
}
/*

Sample Input/Output:

Enter data to be inserted or type -1 : 10
Enter left child of 10
Enter data to be inserted or type -1 : 20
Enter left child of 20
Enter data to be inserted or type -1 : 30
Enter left child of 30
Enter data to be inserted or type -1 : -1
Enter right child of 30
Enter data to be inserted or type -1 : -1
Enter right child of 20
Enter data to be inserted or type -1 : -1
Enter right child of 10
Enter data to be inserted or type -1 : 40
Enter left child of 40
Enter data to be inserted or type -1 : -1
Enter right child of 40
Enter data to be inserted or type -1 : 50
Enter left child of 50
Enter data to be inserted or type -1 : -1
Enter right child of 50
Enter data to be inserted or type -1 : -1
BFS Traversal of the tree is : 10 20 40 30 50
Tree Formed :
    10
    /\
  20  40
 /     \
30     50


Time Complexity : O(n), because we are traversing n-nodes on the tree.
Space Complexity: O(n), because we are using a queue.

*/
