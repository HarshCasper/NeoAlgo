/*

Introduction 
Given a Binary Tree ,Print all its root to leaf paths

Argument/Return Type
Input of total no.of nodes is taken
Input of key values of nodes of tree are taken in level order form 
Incase of a null node , -1 is taken as input
Function  prints all its root to leaf paths recursively

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

//Utility Function to print given path
void PrintThisPath(vector<int>path)
{
   for( int i: path )   cout<<i<<" ";
   cout<<endl;
   return ;
}

//Utility Function to Generate paths
void GeneratePaths(struct Node* root, vector<int>path)
{
    if(root==NULL) 
    {
        //A null node is a leaf node obviously
        //Hence print its path
        PrintThisPath(path);
        return;
    }
    //If its not NULL node , append this node to the path array
    path.push_back(root->key);
    // If it is a leaf node , print its path 
    if(root->left==NULL && root->right==NULL)
    {
        PrintThisPath(path);
        return ;
    }
    //else continue generating paths
    GeneratePaths(root->left,path);
    GeneratePaths(root->right,path);
    return ;
}

// Function to print all root to leaf paths
void PrintRootToLeafPaths(struct Node* root)
{
    vector<int>path;
    GeneratePaths(root,path);
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
    cout<<"All root to leaf paths are "<<endl;
    PrintRootToLeafPaths(root);
    
    return 0; 
}
    
/*
Input:
0 <= node->key < 1000000000
if node is NULL , -1 is entered as it's key

Sample Test Case 1  
Input Binary Tree :                   

               1                                
           /         \                          
         2              11                    
     /       \        /   \               
    3        5       12    13             
   / \      /  \    / \   /  \            
  4 NULL    6  7    8  9 NULL  4         


Input Format : 
Example :
Enter total no.of nodes of the input Tree ( including NULL nodes ) : 15
Enter value of each node of the tree in level order ( if a node is NULL , enter -1 ) with spaces
1 2 11 3 5  12 13 4 -1 6 7 8 9 -1 4

Output Format :
Example : ( Output to the above input example ) 
All root to leaf paths are 
1 2 3 4
1 2 3
1 2 5 6
1 2 5 7
1 11 12 8
1 11 12 9
1 11 13
1 11 13 4

Sample Test Case 2  
Input Binary Tree :                   

                  12                                
          /               \                          
         9                 17                    
     /       \          /      \               
    8       10         NULL    18                                


Input Format : 
Example :
Enter total no.of nodes of the input Tree ( including NULL nodes ) : 7
Enter value of each node of the tree in level order ( if a node is NULL , enter -1 ) with spaces
12 9 17 8 10 -1 18 

Output Format :
Example : ( Output to the above input example ) 
All root to leaf paths are 
12 9 8
12 9 10
12 17
12 17 18

Time/Space Complexity
Time Complexity : O(n) 
   Where n is the no.of nodes 
Space Complexity : O(n) 
   Where n is the no.of nodes
*/
