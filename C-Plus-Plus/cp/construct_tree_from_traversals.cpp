/*Problem Statement: 
You are given the nodes of two trees in preorder and inorder format respectively,
Your task is to construct a tree from the given traversals. */

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

node* Create(int *in,int *pre,int s,int e)
{
    static int i=0;
    if(s>e)
    {
        return NULL;
    }
    node* root=new node(pre[i]);
    int index=-1;
    for(int j=s;j<=e;j++)
    {
        if(in[j]==pre[i])
        {
            index=j;
            break;
        }
    }
    i++;
    root->left=Create(in,pre,s,index-1);
    root->right=Create(in,pre,index+1,e);
    return root;
}

void bfs(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<",";
            q.pop();

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return;
}

int main()
{
    int inorder[100],preorder[100],n;
    cout<<"Enter total elements"<<endl;
    cin>>n;
    cout<<"Enter Inorder tree elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>inorder[i];
    }
    cout<<"Enter Preorder tree elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>preorder[i];
    }
    node* root=Create(inorder,preorder,0,n-1);
    cout<<"The tree is: "<<endl;
    bfs(root);
    return 0;
}

/*
Example: 
Input:-
Enter total elements
8
Enter Inorder tree elements:
3 2 8 4 1 6 7 5
Enter Preorder tree elements:
1 2 3 4 8 5 6 7

Output:-
The tree is:
1,
2,5,
3,4,6,
8,7,

Time Complexity: O(n)
Space Complexity: O(n)
*/

