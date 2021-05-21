/*Problem Statement: 
We are given a binary tree having N+1 nodes, N edges and an integer x.
The task is to find the count of the total number of subtrees having total node's
data sum equal to value X. */

#include<bits/stdc++.h>
using namespace std;

char a[1000];
vector<int> v;

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

void StringToNums()
{
    //Dividing the string characters by a space
    char *ans=strtok(a," ");
    while(ans!=NULL)
    {
        //The corresponding integer of the character is being pushed
        v.push_back(stoi(ans));
        ans=strtok(NULL," ");
    }
}

Node* CreateTree()
{
    if(strlen(a)==0 or v.size()==0)
    {
        return NULL;
    }
    int no=v[0];
    Node* root=new Node(no);
    int i=1;
    queue<Node*> q;
    q.push(root);
    while(!q.empty() and i<v.size())
    {
        Node* temp=q.front();
        q.pop();
        no=v[i];
        i++;
        temp->left=new Node(no);
        q.push(temp->left);
        if(i>=v.size())
        {
            break;
        }
        //If elements are remaining in the array, then make it the right child
        no=v[i++];
        temp->right=new Node(no);
        q.push(temp->right);
        if(i>=v.size())
        {
            break;
        }
    }
    return root;
}

int Sum(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left=Sum(root->left);
    int right=Sum(root->right);
    return root->data+left+right;
}

int countSubtrees(Node* root,int x)
{
    if(root==NULL)
    {
        return 0;
    }
    int ans=0;
    /*If the data value of the node+left child+right child is equal to x, 
    then we have found the subtree */
    if(Sum(root)==x)
    {
        ans=1;
    }
    int left=countSubtrees(root->left,x);
    int right=countSubtrees(root->right,x);
    return ans+left+right;
}

int main()
{
    int x;
    cin.ignore();
    cout<<"Enter the nodes of the tree: "<<endl;
    cin.getline(a,1000);
    cout<<"Enter the value x: "<<endl;
    StringToNums();
    Node* root=CreateTree();
    cout<<"Total subtrees are: "<<countSubtrees(root,x)<<endl;
    return 0;
}
/*Example:-

Input:-
Enter the nodes of the tree:
1 2 3 
Enter the value x: 
5

Output:-
Total subtrees are: 0

Time Complexity: O(n)
Space Complexity: O(n)
*/
