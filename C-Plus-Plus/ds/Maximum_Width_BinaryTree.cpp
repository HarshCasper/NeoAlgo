// C++ Program to find Maximum Width of Binary Tree

#include <bits/stdc++.h>
#include <string.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

// function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> v;
    istringstream iss(str);
    for(string str; iss >> str; )
        v.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(v[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < v.size()) {
        
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = v[i];
            
        // If the left child is not null
        if(currVal != "N") {
         
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= v.size())
            break;
        currVal = v[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

/* Function to get the maximum width of a binary tree*/
// follows level order traversal
int getMaxWidth(Node* root)
{
    
   int i,count,res=0;
   
    if(root == NULL) // If root is NULL
    return 0;
    
     //Create queue of nodes
    queue<Node*>q;  
    // Pushing root in queue
    q.push(root);   
    
    while(q.empty()==false)
    { 
        // Count size of queue
        count=q.size();
        
        // Calculate maximum width
        res=max(res,count);  
        
        for(i=0;i<count;i++) 
        {
            // Get and remove the front of the queue
            Node *curr = q.front();
            q.pop();
            
            // If the left child is not null
            if(curr->left!=NULL)
            {
             // Push it to the queue
              q.push(curr->left);
            }
            
            // If the right child is not null
            if(curr->right!=NULL)
            {
             // Push it to the queue
              q.push(curr->right);
            }
        }
   }

   return res;
}

int main()
{
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        // maximum width
        cout << getMaxWidth(root);
   
    return 0;
}

/* Test Cases
  
Input: 1 2 3 4 5 6 7
Output: 4

Input: 1 2 3 N N 4 6 N 5 N N 7 N
Output: 2

Time Complexity:  O(N) where N is the total number of nodes in the tree.
Space Complexity: O(w) where w is the maximum width of the tree.

*/
