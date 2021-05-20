/*

Introduction 
Given a Binary Tree , Print the level with maximum sum , and its corresponding sum.

Argument/Return Type
Input of total no.of nodes is taken
Input of key values of nodes of tree are taken in level order form 
Incase of a null node , -1 is taken as input
A function which returns the level with maximum sum and its corresponding sum.

*/

//  Code / Solution

#include <bits/stdc++.h> 
using namespace std;
// Declare global variables
long max_level;
long max_sum;

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

//Function to update level with maximum sum and its corresponding sum
void FindMaxSum(struct Node* root)
{
    //Initialise current and maximum sums and corrresponding levels with 0 value
    long curr_sum=0,curr_level=0;
    max_sum=0;
    max_level=0;
    // If root is NULL , return current levels
    if (root == NULL)
        return ;

    // Create an queue
    queue<struct Node*> q;
    //Enqueue the root node and a null node to indicate a level is completed
    q.push(root);
    q.push(NULL);
 
    while (!q.empty()) 
    {
        //If we encounter a NULL node , it means a level is complete
        //Hence update max_sum and max_level 
        // Re initialise curr_sum to 0 , and increase curr_level by 1
        if(q.front()==NULL)
        {
            curr_level++;
            if(max_sum<curr_sum)
            {
                 max_sum=curr_sum;
                 max_level=curr_level;
            }
            curr_sum=0;
            q.pop();
            if(!q.empty())
            {
                //If there are more nodes in q , push a NULL node
                q.push(NULL);
            }
        }
        else
        {
            //Add the node's value to curr_sum
            curr_sum=curr_sum+q.front()->key;
            //Enqueue node's children , if they exist
            if(q.front()->left)
               q.push(q.front()->left);
            if(q.front()->right)
               q.push(q.front()->right);
            q.pop();
        }
    }
    return ;
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
    FindMaxSum(root);
    cout<<"Hence the level with max sum is level "<<max_level<<" with sum "<<max_sum;
    
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
         11              12                    
     /       \        /   \               
    5       NULL     6     13             
   / \      /  \    / \   /  \            
  4 NULL  NULL NULL 8  9 10  NULL         


Input Format : 
Example :
Enter total no.of nodes of the input Tree ( including NULL nodes ) : 15
Enter value of each node of the tree in level order ( if a node is NULL , enter -1 ) with spaces
10 11 12 5 -1 6 13 4 -1 -1 -1 8 9 10 -1

Output Format :
Example : ( Output to the above input example ) 
Hence the level with max sum is level 4 with sum 31

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
Hence the level with max sum is level 4 with sum 57

Time/Space Complexity
Time Complexity : O(n) 
   Where n is the no.of nodes 
Space Complexity : O(n) 
   Where n is the no.of nodes
*/
