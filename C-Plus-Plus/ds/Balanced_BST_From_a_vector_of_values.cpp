/*
Introduction 
Given a vector of values , Build a Balanced BST with them

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
 
/* Function to create a node with 'value' as the data stored in it. 
 Both the children of this new Node are initially null. */
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
    /*If the root is NULL , create a node with given element and assign it to root
    else if the root itself is the node with given data , return 
    else recursively insert it in one of the subtrees accordingly */
    if(root==NULL)
        root = newNode(element);
    else if(root->key < element)
        root->right = insert(root->right,element);
    else if(root->key > element)
        root->left = insert(root->left,element);
    
    return root;
}

// Function to print Tree in  level order
void LevelOrderTraversal(struct Node* root)
{
    // If root is NULL , return 
    if (root == NULL)
        return ;

    // Create an queue
    queue<struct Node*> q;
    //Enqueue the root node 
    q.push(root);
 
    while (!q.empty()) 
    {
        cout<<q.front()->key<<" ";
        //Enqueue node's children , if they exist
        if(q.front()->left)
            q.push(q.front()->left);
        if(q.front()->right)
            q.push(q.front()->right);
        q.pop();
    }
    return ;
}

//Utility function to remove duplicates from a vector of sorted values
vector<int> RemoveDuplicates(vector<int>values)
{
   //declare a new vector
   vector<int>newVector;

   for(int i=0;i<values.size();i++)
   {
      //Push the values which are not already pushed
      if(i==0 || i && values[i]!=values[i-1])
          newVector.push_back(values[i]);
   }

   return newVector;
}

//Utility Function to build a balanced BST recursively after sorting the given vector values
struct Node* BuildBalancedBSTUtil(vector<int>v,int start,int end)
{
    //Declare a node and initialise it to NULL
    struct Node* root;

    if(start>end)
    {
        /*If start index is more than end index 
        assign a NULL node to the root */
        root = NULL;
    }
    else if(start==end)
    {
        /*If start index equal to end index 
        assign a new leaf node with the value as v[start] */
        root = newNode(v[start]);
    }
    else
    {
       /*else create a new node with a value of mid element of vector
       care must be taken to get mid index , to avoid overflow */
       int mid = start + (end-start)/2;
       root = newNode(v[mid]);

       //and recursively build subtrees of the root
       root->left = BuildBalancedBSTUtil(v,start,mid-1);
       root->right = BuildBalancedBSTUtil(v,mid+1,end);
    }
    
    return root;
}

//Function to build Balanced BST from given vector values
struct Node* BuildBalancedBST(vector<int>values)
{
    //sort the given vector values
    sort(values.begin(),values.end());
    
    /* To make sure there are no duplicate values ,
    Remove all the duplicates from the sorted vector */
    values = RemoveDuplicates(values);

    //Declare a node pointer and store the return value of the utility function
    struct Node* root = BuildBalancedBSTUtil(values,0,values.size()-1);

    return root;
}

// Driver code
int main()
{
    int n;
    cout<<"Enter total no.of nodes of the input Tree ( including NULL nodes ) : ";
    cin>>n;
    
    //create a vector to take input and store them
    vector<int>values;

    cout<<"Enter value of each node of the Tree , with spaces"<<endl;
    for(int i=0;i<n;i++)
    {
        int value;
        cin>>value; 
        values.push_back(value);
    }   

    //Call the function and print the result
    struct Node* root;
    root=BuildBalancedBST(values);
    cout<<"Hence the level order of Balanced BST built is : ";
    LevelOrderTraversal(root);

    return 0; 
}
    
/*
Input:
0 <= node->key < 1000000000
While entering node values of the tree , 
value of the head of the tree should be enetered first

Sample Test Case 1  
Input Binary Tree 1:                    
             5                                                             
          /     \                                             
         1      20                                      
        / \    /  \                           
    NULL   2  11  25                                

Input Format : 
Example :
Enter total no.of nodes of the input Tree ( including NULL nodes ) : 6
Enter value of each node of the Tree , with spaces
1 5 25 2 20 11

Output Format :
Example : ( Output to the above input example ) 
Hence the level order of Balanced BST built is : 5 1 20 2 11 25

Time/Space Complexity
Time Complexity : O(n) 
   Where n is the no.of nodes ofthe tree
Space Complexity : O(h) 
   Where h is the height of the tree
*/
