/*

Introduction 
Given a Binary Tree , print all common ancestors of given two nodes
It is guaranteed that given Binary Tree will have all unique node values

Argument/Return Type
Input of total no.of nodes is taken
Input of key values of nodes of tree are taken in level order form 
Incase of a null node , -1 is taken as input
Function to find and print all common ancestors of given two nodes

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

//Utility function to print common of both given vectors
void printCommon(vector<int>a,vector<int>b)
{
    //As ancestors are pushed in revrese order , 
    //we must print common elements of vector from reverse
   int n1=a.size()-1;
   int n2=b.size()-1;
   //Print elements from end , till they we reach least common ancestor
   while(a[n1]==b[n2])
   {
       cout<<a[n1]<<" ";
       n1--;
       n2--;
       //If we complete one vector , break and return
       if(n1<0 || n2<0)
         break;
   }
   return ;
}

//Utility Function to Generate Ancestors of the node
bool GenerateAncestors(struct Node *root, int Node_value , vector<int>& path)
{
  // base cases 
  if (root == NULL)
     return false;
  
  //If the node is found return True to its parent's node
  if (root->key == Node_value)
     return true;
  
  // If target is present in either left or right subtree of this node,
  // then print this node
  if ( GenerateAncestors(root->left, Node_value,path) ||  GenerateAncestors(root->right, Node_value,path) )
  {
     path.push_back(root->key);
     return true;
  }
  
  //If its not in either of the subtrees, return false 
  return false;
}

//Function to get ancestors of both nodes and print common of them
void FindnPrintCommonAncestorNodes(struct Node* root,int Node_1_value,int Node_2_value)
{
   vector<int>AncestorsOfNode1;
   GenerateAncestors(root,Node_1_value,AncestorsOfNode1);
   vector<int>AncestorsOfNode2;
   GenerateAncestors(root,Node_2_value,AncestorsOfNode2);
   printCommon(AncestorsOfNode1,AncestorsOfNode2);
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

    int Node_1_value,Node_2_value;
    cout<<"Enter values of two nodes of tree whose common ancestors are to be found , with space : ";
    cin>>Node_1_value>>Node_2_value;

    //create the tree using input node values  
    struct Node* root=createTree(v); 


    //Call the function and print the result
    cout<<"Hence the values of common ancestor nodes of given nodes are ";
    FindnPrintCommonAncestorNodes(root,Node_1_value,Node_2_value);
    
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
Enter values of two nodes of tree whose common ancestors are to be found , with space : 6 7

Output Format :
Example : ( Output to the above input example ) 
Hence the values of common ancestor nodes of given nodes are 1 2 5

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
Enter values of two nodes of tree whose common ancestors are to be found , with space : 10 18

Output Format :
Example : ( Output to the above input example ) 
Hence the values of common ancestor nodes of given nodes are 12 

Time/Space Complexity
Time Complexity : O(n) 
   Where n is the no.of nodes 
Space Complexity : O(n) 
   Where n is the no.of nodes
*/
