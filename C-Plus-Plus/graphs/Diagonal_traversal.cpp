/*
 Program to print diagonal traversal of a binary tree.
 The idea is to use a queue to store only the left child of current node.
 After printing the data of current node make the current node to its right child, if present.
 A delimiter NULL is used to mark the starting of next diagonal.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;
};
Node* root = NULL;

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to insert item in a tree
void insertItem(int item)
{
    Node *newnode = newNode(item);
    if(!root) {
        root = newnode;
        return;
    }
    Node *cur, *prev;
    cur = root;
    while(cur!= NULL) {
        prev = cur;
        if(cur->data > item)
            cur = cur->left;
        else
            cur = cur->right;
    }
    if(prev->data > item)
        prev->left = newnode;
    else
        prev->right = newnode;
}

vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> ans;
   queue<Node *> q;
    q.push(root);
    while(!q.empty()){
        Node *t=q.front();
        while(t){
            ans.push_back(t->data);
            if(t->left)
                q.push(t->left);
            t=t->right;
        }
        q.pop();
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
        insertItem(arr[i]);
    }
    vector<int> ans = diagonal(root);
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}

/*
 Sample I/O
 Input format: The first line contains n - number of nodes in the tree
               The next line contains n spaced integers
 Output format: n spaced integers.
 Example:
 9
 8 11 2 1 6 14 4 9 13

 Output - 8 11 14 2 6 9 13 1 4

 Explanation:
            8
          /   \
         2     11
       /  \     \
      1    6     14
         /   \   /
        4     9 13

 1st diagonal - 8 11 14
 2nd diagonal - 2 6 9 13
 3rd diagonal - 1 4

*/

/*
 Complexity:
 Time complexity: O(N)
 Space complexity: O(N)
*/

