/*
Introduction 
Given a Binary Tree , Print all vertical level sum's.
It is guaranteed that all node's have unique key values.

Argument/Return Type
Input of total no.of nodes is taken
Input of key values of nodes of tree are taken in level order form 
Incase of a null node , -1 is taken as input
*/

#include <bits/stdc++.h> 
using namespace std;
//Declare Global maps to maintain sum of all vertical levels
map<int,int>verticalLevelSum;
//Define Global variable to keep track leftmost level and right most level
int LeftMostLevel;
int RightMostLevel;

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

//Utility function to update levels of roots recursively 
void UpdateLevelsUtil(struct Node* root,int level)
{
  //If root is NULL , return
  if(root==NULL)
    return;

  //else add the root's value to its corresponding level
  verticalLevelSum[level]=verticalLevelSum[level]+root->key;

  //update LeftMost and RightMost levels
  LeftMostLevel=min(LeftMostLevel,level);
  RightMostLevel=max(RightMostLevel,level);

  //Now recursively update levels of children , by giving corresponding level values
  UpdateLevelsUtil(root->left,level-1);
  UpdateLevelsUtil(root->right,level+1);
  return ;
}

//Function to call utility function and update all levels and corresponding sums
void UpdateLevels(struct Node* root)
{
  UpdateLevelsUtil(root,0);
  return ;
}

//Function to print level sums of all levels from left to right
void PrintVerticalLevelSums()
{
  //print level sums of all levels from left most level to right most level
  for(int i=LeftMostLevel;i<=RightMostLevel;i++)
    cout<<verticalLevelSum[i]<<" ";
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
    
    //initialise the variables as follows
    LeftMostLevel=INT_MAX;
    RightMostLevel=INT_MIN;

    //call the function to update Vertical Levels of all node's
    UpdateLevels(root);

    //Call the function and print the result
    cout<<"Hence vertical Level Sum's from left to right are : ";
    PrintVerticalLevelSums();
    
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

Vertically Level wise representation will be as follows :
                                        1
                                2               11
                           3            5,12           13
                       4      6,8,NULL         7,9,NULL      4

Input Format : 
Example :
Enter total no.of nodes of the input Tree ( including NULL nodes ) : 15
Enter value of each node of the tree in level order ( if a node is NULL , enter -1 ) with spaces
1 2 11 3 5 12 13 4 -1 6 7 8 9 -1 4

Output Format :
Example : ( Output to the above input example ) 
Hence vertical Level Sum's from left to right are : 4 3 16 18 27 13 4

Time/Space Complexity
Time Complexity : O(n) 
   Where n is the no.of nodes 
Space Complexity : O(w) 
   Where w is the width of the tree
*/
