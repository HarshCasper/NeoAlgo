/*
LOWEST COMMON ANCESTOR
--------------------------------------------------
For two nodes, a and b, the lowest common ancestor c 
is the lowest node in the binary tree that has a and b 
as its descendants.This is the Efficient Approach to 
find Lowest Common Ancestor.
--------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;

//Structure of Binary Tree
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Returns the LCA of the nodes with values n1 and n2
// in the BST rooted at 'root' 
Node* LCA(Node * root , int n1 , int n2)
{
   Node* a = root,*b = root;
   Node*lca = NULL;
   while(a && b && (a->data != n1 || b->data!=n2)){
       if(a==b)
       lca = a;
       
       if(a->data<n1)
       a = a->right;
       else if(a->data > n1){
           a=a->left;
       }
       if(b->data < n2){
           b = b->right;
       }
       else if(b->data > n2)
       b = b->left;
   }
    if(a&&b)
    return lca;
    return NULL;
}

// } Driver Code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int l , h;
        getline(cin,s);
        cin>>l;
        cin>>h;
        Node* root = buildTree(s);
        cout<<LCA(root ,  l ,  h)->data<<endl;
    }
    return 1;
}
/*
Time Complexity : O(m+n) ≈ O(n)

Example :-
Input:
              5
           /    \
         4       6
        /         \
       3           7
                    \
                     8
n1 = 7, n2 = 8
Output: 7
*/
