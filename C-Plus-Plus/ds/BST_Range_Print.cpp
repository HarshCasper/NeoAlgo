/*
Introduction 
Given a Binary Search Tree ,Print all the node values
which lies in the range of given low and high values inclusive


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

//Function to print all the node values of the BST within the given branch
void RangePrinter(struct Node* root,int low,int high)
{
    //if root is a NULL node , return
    if(root==NULL)
      return;
    
    //Traverse all required parts of the Tree , in Inorder Fashion
    //And Print the nodes if they satisfy the condition
    
    //If root key is greater than lower limit
    //recursively call the function for left subtree
    if(root->key > low)
      RangePrinter(root->left,low,high);
    
    //If root lies in the given range
    //Print its value
    if(root->key >= low && root->key <= high)
      cout<<root->key<<" ";

    //If root key is lesser than higher limit
    //recursively call the function for right subtree
    if(root->key < high)
      RangePrinter(root->right,low,high);
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

    cout<<"Enter two numbers for range , with space : ";
    int low,high;
    cin>>low>>high;

    //Call the function and print the result
    cout<<"Hence the node values within the given range is : ";
    RangePrinter(root,low,high);

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
Enter two numbers for range , with space : 5 30

Output Format :
Example : ( Output to the above input example ) 
Hence the node values within the given range is : 5 11 20 25

Time/Space Complexity
Time Complexity : O(n) 
   Where n is the no.of nodes ofthe tree
Space Complexity : O(h) 
   Where h is the height of the tree
*/
