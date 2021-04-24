/*

Introduction 
Given a Binary Tree , check if it is a valid Binary Search Tree

A valid Binary Search Tree is defined as follows:
- The left subtree of a node contains only nodes with keys less than the node's key.
- The right subtree of a node contains only nodes with keys greater than the node's key.
- Both the left and right subtrees must also be binary search trees.

Argument/Return Type
Input of total no.of nodes is taken
Input of key values of nodes of tree are taken in level order form 
Incase of a null node , -1 is taken as input
Bool is returned as a result and corresponding statement is printed

*/

//  Code / Solution

#include <bits/stdc++.h> 
using namespace std;

//Define Node as structure
struct Node 
{
    int key;
    Node* left;
    Node* right;
};
 
// Function to create a node with 'value' as the data stored in it. 
// Both the children of this new Node are initially null.
struct Node* newNode(int value)
{
    Node* n = new Node;
    n->key = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function to build tree with given input
struct Node* createTree(vector<int>v)
{
    int n=v.size();
    if(n==0) 
      return NULL;
    vector<struct Node* >a(n);
    //Create a vector of individual nodes with given node values
    for(int i=0;i<n;i++)  
    {
        //If the data is -1 , create a null node
        if(v[i]==-1)  
          a[i] = NULL;
        else 
          a[i] = newNode(v[i]);
    }
    //Interlink all created nodes to create a tree
    //Use two pointers using int to store indexes
    //One to keep track of parent node and one for children nodes
    for(int i=0,j=1;j<n;i++) 
    {
        //If the parent node is NULL , advance children pointer twice
        if(!a[i])
        {
          j=j+2;
          continue;
        } 
        //Connect the two children nodes to parent node
        //First left and then right nodes
        a[i]->left = a[j++];
        if(j<n) 
          a[i]->right = a[j++];
    }
    return a[0];
}

// Utility function which keeps checking , three essential conditions to be a BST 
// Returns true if the given tree is a BST and its values are >= min and <= max. 
bool IsValidBSTUtil(struct Node* root, int min, int max)
{
    // an empty tree is BST as it obeys all the conditions
    if (root==NULL)
        return true;
             
    //return false if this node violates the min/max constraint 
    if (root->key < min || root->key > max)
        return false;
     
    //Check if both subtrees are valid BST's recursively 
    //Update corresponding min , max values
    return  IsValidBSTUtil(root->left, min, root->key-1) && IsValidBSTUtil(root->right, root->key+1, max); 
}

// Function to check if it is a valid binary tree
bool IsValidBST(struct Node* root)
{
    return(IsValidBSTUtil(root, INT_MIN, INT_MAX));
}
 

int main()
{

    int n;
    cout<<"Enter total no.of nodes of the input Tree ( including NULL nodes ) : ";
    cin>>n;

    vector<int>v(n);
    cout<<"Enter value of each node of the tree in level order ( if a node is NULL , enter -1 ) with spaces"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>v[i]; //store the input values in a vector
    }

    //create the tree using input node values  
    struct Node* root=createTree(v); 

    //Call the function and print the result
    bool result=IsValidBST(root); 
    if(result)
        cout<<"The given tree is a valid Binary Search Tree";
    else
        cout<<"The given tree is not a valid Binary Search Tree";
      
    return 0; 
}
    
/*
Input:
0 <= node->key < 1000000000
if node is NULL , -1 is entered as it's key

Sample Test Case 1  
Input Binary Tree :                   

               10                                
           /         \                          
         11              12                    
     /       \        /   \               
    5       NULL     6     13             
   / \      /  \    / \   /  \            
  4 NULL  NULL NULL 8  9 10  NULL         


Input Format : 
Example :
Enter total no.of nodes of the input Tree ( including NULL nodes ) : 15
Enter value of each node of the tree in level order ( if a node is NULL , enter -1 ) with spaces
10 11 12 5 -1 6 13 4 -1 -1 -1 8 9 10 -1

Output Format :
Example : ( Output to the above input example ) 
The given tree is not a valid Binary Search Tree

Sample Test Case 2  
Input Binary Tree :                   

                  12                                
          /               \                          
         9                 17                    
     /       \          /      \               
    8       10         15       18             
   / \      /  \      / \      /  \            
  7 NULL  NULL NULL 14  16 NULL  20         


Input Format : 
Example :
Enter total no.of nodes of the input Tree ( including NULL nodes ) : 15
Enter value of each node of the tree in level order ( if a node is NULL , enter -1 ) with spaces
12 9 17 8 10 15 18 7 -1 -1 -1 14 16 -1 20

Output Format :
Example : ( Output to the above input example ) 
The given tree is a valid Binary Search Tree

Time/Space Complexity
Time Complexity : O(n) 
   Where n is the no.of nodes 
Space Complexity : O(n) 
   Where n is the no.of nodes
*/
