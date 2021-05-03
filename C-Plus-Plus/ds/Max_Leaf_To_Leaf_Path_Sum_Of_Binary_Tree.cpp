/*

Introduction 
Given a Binary Tree , print maximum leaf to leaf path sum

Argument/Return Type
Input of total no.of nodes is taken
Input of key values of nodes of tree are taken in level order form 
Incase of a null node , -1 is taken as input
Function to find and return maximum leaf to leaf path sum

*/

//  Code / Solution

#include <bits/stdc++.h> 
using namespace std;
//Define a global variable and keep updating it whenever u get a maximum value
long MaxSum;

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

//Function to calculate leaf to leaf sum and update it recursively
//If root->key is negative it may happen that leaf to leaf path sum < coresponding root to leaf path sum 
//Hence this function returns max root to leaf path sum in each case
long MaxLeafToLeafPathSum(struct Node* root)
{
    // If its a NULL node return 0
    if (root==NULL) return 0;
    //If it is a leaf node return its node value
    if (!root->left && !root->right) 
       return root->key;
 
    // Update MaxSum by recursively calling the function for subtrees
    // Store the values returned by function in variables
    //These are root to leaf max path sum for the coresponding subtrees
    long LeftMaxRtoLSum = MaxLeafToLeafPathSum(root->left);
    long RightMaxRtoLSum = MaxLeafToLeafPathSum(root->right);
 
 
    // If both left and right children exist
    if (root->left && root->right)
    {
        //If root->key is negative it may happen that 
        // leaf to leaf path sum < coresponding root to leaf path sum 
        // Hence Update result if needed
        MaxSum = max(MaxSum, LeftMaxRtoLSum + RightMaxRtoLSum  + root->key);
 
        // Return maxium root to leaf path with root as head
        return max(LeftMaxRtoLSum, RightMaxRtoLSum) + root->key;
    }
 
    // If one of the two children is empty, return
    // return the root to leaf path sum of existing child
    return (!root->left) ? RightMaxRtoLSum + root->key : LeftMaxRtoLSum + root->key;
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

    //Initiate MaxSum with 0
    MaxSum=0;

    //Call the function and print the result
    MaxLeafToLeafPathSum(root);
    cout<<"Hence the maximum leaf to leaf path sum of given Binary Tree is "<<MaxSum;
    
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
1 2 11 3 5 12 13 4 -1 6 7 8 9 -1 4

Output Format :
Example : ( Output to the above input example ) 
Hence the maximum leaf to leaf path sum of given Binary Tree is 49

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
Hence the maximum leaf to leaf path sum of given Binary Tree is 66

Time/Space Complexity
Time Complexity : O(n) 
   Where n is the no.of nodes 
Space Complexity : O(1) 
   No additional space required
*/
