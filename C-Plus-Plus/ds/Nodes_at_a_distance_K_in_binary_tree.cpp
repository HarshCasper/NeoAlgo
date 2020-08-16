/*
    Given a binary tree with unique values, a target node in the binary tree, and an integer value k, print all the nodes 
    that are at a distance k from the given target node.

    Sample preorder input : 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
            target node   : 4
            k             : 2

    Sample output         : 10 11 5 1

    @author : shankhanil007
    @created : 16-08-2020

*/


#include <iostream>
using namespace std;

// Basic definition of a node in binary tree
class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d)
        {
            data = d;
            left = NULL;
            right = NULL;
        }
};


// Function to build the binary tree from preorder input
node* buildTree()
{
    int d; cin>>d;

    if(d == -1){
        return NULL;
    }

    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
}


// Function to print the Kth level of the tree starting from a given node
void printKthLevel(node* root, int k)
{
    if(root == NULL)
        return;

    if(k == 0)
    {
        cout<<root->data<<" ";
        return;
    }

    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);

    return;
}


// Function to find the nodes at a distance K from a given node
int printAtDistanceK(node* root, int target, int k)
{
    // base case
    if(root == NULL){
        return -1;
    }

    //reach the target node
    if(root->data == target){
        printKthLevel(root , k);
        return 0;
    }

    // next step - ancestor 
    int dl = printAtDistanceK(root->left, target, k);

    if(dl != -1){

        // Again there are 2 cases
        // Ancestor itself or you need to go to the right ancestor
        if(dl+1 == k){
            cout<<root->data<<" ";
        }
        else{
            printKthLevel(root->right, k-2-dl);
        }

        return dl+1;
    }

    // next step - ancestor
    int dr = printAtDistanceK(root->right, target, k);

    if(dr != -1){

        // Again there are 2 cases
        // Ancestor itself or You need to go to the left ancestor
        if(dr+1 == k){
            cout<<root->data<<" ";
        }
        else{
            printKthLevel(root->left, k-2-dr);
        }

        return dr+1;
    }

    //node was not present in left and right subtree
    return -1;
}


int main()
{
    node* root = buildTree();
    
    int target, k; cin>>target>>k;   // input for target node and value of K

    printAtDistanceK(root, target, k);

    return 0;
}



