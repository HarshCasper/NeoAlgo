/*
Introduction 
Given a Binary Search Tree ,Find the Floor value of the given number in the BST
Floor value of a given number is the element existing in BST with value less than or equal to the given number

Argument/Return Type
Input of total no.of nodes is taken
Input of key values of nodes of tree are taken
*/

#include <bits/stdc++.h> 
using namespace std;
//Define a Global variable and keep updating it
int Floor;

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

//Function to update Floor value of the given number
void UpdateFloor(struct Node* root,int value)
{
   //If root is a NULL node , return
   if(root==NULL)
     return ;
 
   if(root->key > value)
    {
      //if root key > given value , 
      // recursively search for a floor value in left subtree
       UpdateFloor(root->left,value);
    }
   else if(root->key < value)
   {
       //if root key < given value , 
       //update the floor value and 
       //search for a greater value in right subtree recursively
       Floor=max(Floor,root->key);
       UpdateFloor(root->right,value);
   }
   else
   {
      // if root key = given value , 
      // update the Floor
      Floor = value;
   }
    
   return;
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

    cout<<"Enter a number : ";
    int value;
    cin>>value;

    //Initialise floor variable as -1
    Floor=-1;

    //Call the function and print the result
    UpdateFloor(root,value);
    if(Floor!=-1)
      cout<<"Hence the Floor of given value in the BST is : "<<Floor;
    else
     cout<<"There is no node with the value less than given value in the given Tree";
    
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
Enter a number : 8

Output Format :
Example : ( Output to the above input example ) 
Hence the Floor of given value in the BST is : 5

Time/Space Complexity
Time Complexity : O(n) 
   Where n is the no.of nodes ofthe tree
Space Complexity : O(1) 
*/
