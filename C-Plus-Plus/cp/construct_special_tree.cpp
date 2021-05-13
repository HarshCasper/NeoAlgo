/*Problem Statement:
Given an array with no duplicates. Atree is considered special if it is defined as follows:
1)The root is the maximum number in the array
2)The left subtree is the special tree constructed from left part subarray divided by the 
maximum number.
3)The right subtree is the special tree constructed from right part subarray divided by the 
maximum number.
Construct the special tree and print its inorder traversal */

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node*left;
    Node*right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }

};

void inorder(Node*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

Node* specialTree(int *a,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int k=s;
    for(int i=s;i<=e;i++)
    {
        if(a[i]>a[k])
        {
            k=i;
        }
    }
    Node* root=new Node(a[k]);
    root->left=specialTree(a,s,k-1);
    root->right=specialTree(a,k+1,e);
    return root;
}

int main()
{
    int total;
    int arr[100];
    cout<<"Enter the total number of nodes: "<<endl;
    cin>>total;
    cout<<"Enter nodes: "<<endl;
    for(int i=0;i<total;i++)
    {
        cin>>arr[i];
    }
    Node* root=specialTree(arr,0,total-1);
    cout<<"Special tree: "<<endl;
    inorder(root);
    return 0;
}
/*
Example:-

Input:-
Enter the total number of nodes:
4
Enter nodes:
1 5 3 4

Output:-
Special tree:
1 5 3 4

Time Complexity: O(n)
Space Complexity: O(n)
*/

