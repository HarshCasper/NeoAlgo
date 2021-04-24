/*

Introduction 
Given a Binary Tree Check if its Symmetric or not.
A Tree is said to be symmetric around its centre ,
If it is a mirror image of itself

Argument/Return Type
Input of total no.of nodes is taken
Input of key values of nodes of tree are taken in level order form 
Incase of a null node , -1 is taken as input
Function returns a bool and a statement is printed correspondingly

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

// Function to find if the given trees are mirror images to each other
bool IsMirror(struct Node* root1, struct Node* root2)
{
    //If both roots are NULL , return True
    if (root1 == NULL && root2 == NULL) 
       return true;
    //If one of the roots is NULL and other is not , return False
    if (root1 == NULL || root2 == NULL) 
       return false;
    //Recursively check if left,right subtrees are mirror images of right,left subtrees of the other
    //And key of the roots are equal
    return (root1->key == root2->key) && IsMirror(root1->right, root2->left) && IsMirror(root1->left, root2->right);
}

// Function to find if a Tree is symmetric
bool IsSymmetric(struct Node* root)
{
    //A tree is said to be symmetric if it is a mirror image of itself
   return IsMirror(root,root);
}
 
// Driver code
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
    if(IsSymmetric(root))
      cout<<"Given Tree is symmetric";
    else
      cout<<"Given Tree is not symmetric";
    
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
         11              11                    
     /       \        /   \               
    5       NULL    NULL   5             
   / \      /  \    / \   /  \            
  4 NULL    9  8    8  9 NULL  4         


Input Format : 
Example :
Enter total no.of nodes of the input Tree ( including NULL nodes ) : 15
Enter value of each node of the tree in level order ( if a node is NULL , enter -1 ) with spaces
10 11 11 5 -1 -1 5 4 -1 9 8 8 9 -1 4

Output Format :
Example : ( Output to the above input example ) 
Given Tree is symmetric

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
Given Tree is not symmetric

Time/Space Complexity
Time Complexity : O(n) 
   Where n is the no.of nodes 
Space Complexity : O(n) 
   Where n is the no.of nodes
*/
