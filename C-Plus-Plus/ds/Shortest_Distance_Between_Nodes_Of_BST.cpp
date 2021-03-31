/*
Introduction 
Given a Binary Search Tree ,Find the shortest distance between given two nodes , which exist in the tree

Argument/Return Type
Input of total no.of nodes is taken
Input of key values of nodes of tree are taken
*/

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

// Function to insert a node with given value to the root
struct Node* insert(struct Node* root,int element) 
{
    //If the root is NULL , create a node with given element and assign it to root
    //else if the root itself is the node with given data , return 
    //else recursively insert it in one of the subtrees accordingly
    if(root==NULL)
        root = newNode(element);
    else if(root->key < element)
        root->right = insert(root->right,element);
    else if(root->key > element)
        root->left = insert(root->left,element);
    
    return root;
}

//Function to find least common ancestor
struct Node* leastCommonAncestor(struct Node* root,int node_1_value,int node_2_value)
{
   //If both the given value nodes lie in left subtree of the root
   //Find LCA in left subtree recursively 
   if(node_1_value<root->key && node_2_value<root->key)
      return leastCommonAncestor(root->left,node_1_value,node_2_value);

  //Else If both the given value nodes lie in right subtree of the root
  //Find LCA in right subtree recursively 
   if(node_1_value>root->key && node_2_value>root->key)
      return leastCommonAncestor(root->right,node_1_value,node_2_value);

  //Else it means that one node is in left subtree and one node is in right sub tree
  //return root
   return root;
} 

//Utility function to find distance between a node and its ancestor
int ShortestDistanceUtill(struct Node* root,int value)
{
    //If root itself is the node with given value return 0
    //else recursively calculate distance between corresponding subtree by adding a edge (+1)
    if (root->key == value)
        return 0;
    else if (root->key > value)
        return 1 + ShortestDistanceUtill(root->left, value);
    return 1 + ShortestDistanceUtill(root->right, value);
}

//Function to find shortest distance of nodes with given values in the given tree
int ShortestDistance(struct Node* root,int node_1_value,int node_2_value)
{
  //Finf out the least common ancestor of given two nodes
   struct Node* LCA;
   LCA = leastCommonAncestor(root,node_1_value,node_2_value);

  //If least common ancestor is not found , return -1
   if(LCA==NULL)
     return -1;

   //Now calculate distance between given nodes by the formula below
   return ShortestDistanceUtill(LCA,node_1_value)+ShortestDistanceUtill(LCA,node_2_value);
} 

// Driver code
int main()
{
    int n;
    cout<<"Enter total no.of nodes of the input Tree ( including NULL nodes ) : ";
    cin>>n;

    //create a null node  and initialise it as a NULL node
    struct Node* root;
    root=NULL;
    
    cout<<"Enter value of each node of the Tree , with head as the first value ( if a node is NULL , enter -1 ) with spaces"<<endl;
    for(int i=0;i<n;i++)
    {
        int data;
        cin>>data; 
        //take input of data of each node and insert it in the root
        root = insert(root,data);
    }

    cout<<"Enter two node values of the given Tree : ";
    int node_1_value,node_2_value;
    cin>>node_1_value>>node_2_value;

    //Call the function and print the result
    cout<<"Hence the shortest distance between given two nodes is : "<<ShortestDistance(root,node_1_value,node_2_value);
    
    return 0; 
}
    
/*
Input:
0 <= node->key < 1000000000
While entering node values of the tree , 
value of the head of the tree should be enetered first

Sample Test Case 1  
Input Binary Tree 1:                    
            11                                                             
          /     \                                             
         2      20                                      
        / \    /  \                           
       1   5 NULL 25                                

Input Format : 
Example :
Enter total no.of nodes of the input Tree ( including NULL nodes ) : 6
Enter value of each node of the Tree , with head as the first value ( if a node is NULL , enter -1 ) with spaces
11 2 20 1 5 25
Enter two node values of the given Tree : 5 25

Output Format :
Example : ( Output to the above input example ) 
Hence the shortest distance between given two nodes is : 4

Time/Space Complexity
Time Complexity : O(n) 
   Where n is the no.of nodes ofthe tree
Space Complexity : O(h) 
   Where h is the height of the tree
*/
