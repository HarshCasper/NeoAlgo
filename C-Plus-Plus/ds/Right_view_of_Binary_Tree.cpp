/* Right View of Binary Tree

Given a binary tree, print the nodes which are visible from the right side of the binary tree

Example::

For - 1, 2 ,3 ,4 ,5 ,6 ,7 ,-1,-1,-1,-1,-1,-1,-1,-1

Tree will look like::

            1
          /   \
        2      3
      /   \   /  \
    4     5  6    7

so, The right view of the Bianry Tree will give us node with data :: 1 ,3 ,7
*/

#include<bits/stdc++.h>
using namespace std;

//Creating a class named node
class node
{
    public:
    int data;
    node* left;
    node* right;

    //Creating a constructor
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

//Function To make tree
node* createtree()
{
    int rootval;
    cout<<"\n Enter the data of root:";
    cin>>rootval;

    //Creating a Queue
    queue<node*> q;
    
    node* root=new node(rootval);   //Creating root node
    q.push(root);

    while(!q.empty())
    {
        node* topnode= q.front();
        q.pop();

        int leftval;
        int rightval;

        cout<<"\n Enter Left value of the parent node  ("<<topnode->data<<") ::";
        cin>>leftval;
        cout<<"\n Enter Right value of the parent node ("<<topnode->data<<") ::";
        cin>>rightval;

        if(leftval!=-1)
        {
            topnode->left= new node(leftval);
            q.push(topnode->left);
        }

        if(rightval!=-1)
        {
            topnode->right= new node(rightval);
            q.push(topnode->right);
        }

        if(leftval==-1)
            topnode->left=NULL;

        if(rightval==-1)
            topnode->right=NULL;

    }
    cout<<endl;
    return root;
}

//Function for printing right view
void rightview(node* root)
{
    if(root==NULL)
        return;

    queue<node*> q;     //Created a queue
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* top=q.front();
        q.pop();

        if(top!=NULL)
        {
            if(top->left)
                q.push(top->left);

            if(top->right)
                q.push(top->right);

            if(q.front()==NULL)
                cout<<top->data<<" ";
        }

        else
            q.push(NULL);
    }
}

int main()
{
    node* root=createtree();    //Creating Binary Tree

    cout<<"\n Right view of the tree will be::  ";
    rightview(root);

    return 0;
}

/*
    Sample Testcase::
    ------------------

 Sample Input:
    
 Enter the data of root:1

 Enter Left value of the parent node  (1) ::2

 Enter Right value of the parent node (1) ::3

 Enter Left value of the parent node  (2) ::4

 Enter Right value of the parent node (2) ::5

 Enter Left value of the parent node  (3) ::6

 Enter Right value of the parent node (3) ::7

 Enter Left value of the parent node  (4) ::-1

 Enter Right value of the parent node (4) ::-1

 Enter Left value of the parent node  (5) ::-1

 Enter Right value of the parent node (5) ::-1

 Enter Left value of the parent node  (6) ::-1

 Enter Right value of the parent node (6) ::-1

 Enter Left value of the parent node  (7) ::-1

 Enter Right value of the parent node (7) ::-1

 Sample Output:

 Right view of the tree will be::  1 3 7


*/