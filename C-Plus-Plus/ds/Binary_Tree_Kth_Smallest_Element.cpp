/*
Introduction 
Given a Binary Tree , Find its k th smallest element

Argument/Return Type
Input of total no.of nodes is taken
Input of key values of nodes of tree are taken in level order form 
Incase of a null node , -1 is taken as input
Function to find and return kth smallest element
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

//Traverse all nodes of a tree in level order fashion 
// and maintain k smallest elements
int kthSmallest(struct Node* root,int k)
{
    // If root is NULL , return -1
    if (root == NULL)
        return -1;
    //Store and maintain k smallest elements of tree
    priority_queue<int>heap;

    // Create an queue
    queue<struct Node*> q;
    //Enqueue the root node and a null node to indicate a level is completed
    q.push(root);
 
    while (!q.empty()) 
    {
        //Traverse each node 
        //If it is a null node , pop it and continue
        if(q.front()==NULL)
        {
            q.pop();
            continue;
        }
        //else update heap
        heap.push(q.front()->key);
        //if heap's size exceed k , 
        //pop the top element
        if(heap.size()>k)
           heap.pop();
        //Enqueue node's children , if they exist
        if(q.front()->left)
            q.push(q.front()->left);
        if(q.front()->right)
            q.push(q.front()->right);
        q.pop();
    }
    //If no.of nodes of tree is less than k , return -1
    //else return kth smallest element
    if(heap.size()<k)
      return -1;
    else
      return heap.top();
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

    int k;
    cout<<"Enter the value of k : ";
    cin>>k;

    //Call the function and print the result
    int answer=kthSmallest(root,k);
    if (answer==-1)
      cout<<"Given Tree has less than k nodes for given value of k";
    else
      cout<<"Hence the kth smallest value of Tree for given value of k is "<<answer;
    
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
Enter the value of k : 2

Output Format :
Example : ( Output to the above input example ) 
Hence the kth smallest value of Tree for given value of k is 2

Time/Space Complexity
Time Complexity : O(n) 
   Where n is the no.of nodes 
Space Complexity : O(n) 
   Where n is the no.of nodes
*/
