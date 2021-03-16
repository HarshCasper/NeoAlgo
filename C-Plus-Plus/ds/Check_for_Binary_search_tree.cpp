/*
Validating BST: This program check if the given tree is BST or not.

Author: @Mohim-Singla
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

//initializing structure
struct node{
int data;
node* lchild;
node* rchild;
};
//Function to create tree
node* create_node(int data)
{
    node* temp=new node;
    temp->data=data;
    temp->lchild=temp->rchild=NULL;
    return temp;
}

node* create(node* root, int data)
{
    if(root==NULL)
    {
        root = create_node(data);
        return root;
    }
    else
    {
        if (data<root->data)
        {
            root->lchild = create(root->lchild,data);
        }
        else
        {
            root->rchild=create(root->rchild, data);
        }
        return root;
    }
}
//BST Check Function
bool check(node* root, int minv, int maxv)
{
    if(root==NULL)
    {
        return true;
    }
    else if (root->data>minv && root->data<maxv && check(root->lchild, minv, root->data) && check(root->rchild, root->data, maxv))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Displaying output
void check_output(node* root, int minv, int maxv)
{
    bool ans=check(root,INT_MIN,INT_MAX);
    if(ans)
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }
}

int main()
{
    //creating a BST
    node* root=NULL;
    root=create(root, 16);
    root=create(root, 4);
    root=create(root, 10);
    root=create(root, 20);
    root=create(root, 11);
    root=create(root, 25);
    root=create(root, 8);
    root=create(root, 6);
    root=create(root, 14);
    root=create(root, 2);
    root=create(root, 21);
    root=create(root, 31);
    root=create(root, 7);
    root=create(root, 32);

    check_output(root,INT_MIN,INT_MAX);

    //converting bst to binary tree
    root->lchild->data=18;
    check_output(root,INT_MIN,INT_MAX);
    return 0;
}

/*
Test case:
Input:
A BST
A non-BST

Output:
True
False

Time complexity: O(nlogn)
Space complexity: O(n)
*/
