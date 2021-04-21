/*
Introduction 
Given a N ary Tree ,
Generate a equivalent child sibling Tree , 
and  Print the sum of elements of this equivalent Tree.
It is guaranteed that all node's have unique key values.

Argument/Return Type
Input of total no.of nodes is taken
Input of key values of nodes of tree are taken in level order form 
Incase of a null node , -1 is taken as input
*/

#include <bits/stdc++.h> 
using namespace std;

//Define Node as structure
struct Node 
{
    int key;
    Node* firstChild;
    Node* nextSibling;
};
 
// Function to create a node with 'value' as the data stored in it. 
// Both the children of this new Node are initially null.
struct Node* newNode(int value)
{
    Node* n = new Node;
    n->key = value;
    n->firstChild = NULL;
    n->nextSibling = NULL;
    return n;
}

//Function to add Sibling and return it
struct Node* addSibling(struct Node* root, int data)
{
    //If root is a null node , return the null node
    if (root == NULL || data==-1)
        return NULL;
    
    //else move to the last sibling and then add the new node as sibling
    while (root->nextSibling)
        root = root->nextSibling;
 
    return (root->nextSibling = newNode(data));
}

//Function to add Child and return it
struct Node* addChild(struct Node* root, int data)
{
    //If root is a null node , return the null node
    if (root == NULL || data==-1)
        return NULL;
 
    //if the first child exists
    //add the new node as a sibling to the first child
    //else add the new node as first child
    if (root->firstChild)
        return addSibling(root->firstChild, data);
    else
        return (root->firstChild = newNode(data));
}

//Function to find sum of all elements of a given Tree
long SumOfNaryTree(struct Node* root)
{
    //If root is a NULL node , return 0
    if(root==NULL)
      return 0;
    
    //else return the sum of tree 
    //by recursively calculating sum of First Child Tree and next sibling
    //To make sure sum doesn't overflow , add it step by step
    long answer=root->key;
    answer=answer + SumOfNaryTree(root->firstChild) + SumOfNaryTree(root->nextSibling) ;

    return answer;
}
                
// Driver code
int main()
{
    //Input the head of N ary Tree
    struct Node* root;
    cout<<"Enter the key value of the head of the N ary Tree (incase of a NULL node , enter -1) : ";
    int data;
    cin>>data;
    if(data!=-1)
      root=newNode(data);
    else 
      root=NULL;

    // To take input of whole N ary Tree
    //create a queue and push all newly created nodes into it
    queue<struct Node*>q;
    q.push(root);

    struct Node* curr;

    //keep traversing the queue , till its empty
    while(!q.empty())
    {
      //If the root node is NULL break the loop
      if(q.front()==NULL)
        break;
      else
      {
         //During each visit of  a node , 
         //Collect its children nodes and build a child sibling Tree equivalent to N ary Tree
         struct Node* temp=q.front();
         q.pop();
         int n;
         //Input no.of child nodes of the current node
         cout<<"Enter total no.of child nodes of node with data value "<<temp->key<<" : ";
         cin>>n;
         //If there are no child nodes , continue
         if(n==0) 
           continue;
         cout<<"Enter values of children from left right , with space : ";
         //Input each node and add it as the child node for the current node
         for(int i=1;i<=n;i++)
         {
            cin>>data;
            //Push all the newly created nodes , i.e children nodes
            q.push(addChild(temp,data));
         }
      }    
    }

    //Call the function and print the result
    cout<<"Hence the sum of the given N ary Tree is : "<<SumOfNaryTree(root);

    return 0; 
}
    
/*
Input:
0 <= node->key < 1000000000
Each Node should have unique key value
if node is NULL , -1 is entered as it's key

Sample Test Case 1  
Input N ary Tree :                   

                          1                                 
           /           /       \    \                    
         2            13       16   18         
     /   |    \       / \       |       
    3    4     5     14  15     17      
  / | \  |    / | \                 
 6  7  8 9   10 11 12         

Input Format : 
Example :
Enter the key value of the head of the N ary Tree (incase of a NULL node , enter -1) : 1
Enter total no.of child nodes of node with data value 1 : 4
Enter values of children from left right , with space : 2 13 16 18
Enter total no.of child nodes of node with data value 2 : 3
Enter values of children from left right , with space : 3 4 5
Enter total no.of child nodes of node with data value 13 : 2
Enter values of children from left right , with space : 14 15
Enter total no.of child nodes of node with data value 16 : 1
Enter values of children from left right , with space : 17
Enter total no.of child nodes of node with data value 18 : 0
Enter total no.of child nodes of node with data value 3 : 3
Enter values of children from left right , with space : 6 7 8
Enter total no.of child nodes of node with data value 4 : 1
Enter values of children from left right , with space : 9
Enter total no.of child nodes of node with data value 5 : 3
Enter values of children from left right , with space : 10 11 12
Enter total no.of child nodes of node with data value 14 : 0
Enter total no.of child nodes of node with data value 15 : 0
Enter total no.of child nodes of node with data value 17 : 0
Enter total no.of child nodes of node with data value 6 : 0
Enter total no.of child nodes of node with data value 7 : 0
Enter total no.of child nodes of node with data value 8 : 0
Enter total no.of child nodes of node with data value 9 : 0
Enter total no.of child nodes of node with data value 10 : 0
Enter total no.of child nodes of node with data value 11 : 0
Enter total no.of child nodes of node with data value 12 : 0

Output Format :
Example : ( Output to the above input example ) 
Hence the sum of the given N ary Tree is : 171

Time/Space Complexity
Time Complexity : O(n) 
   Where n is the no.of nodes 
Space Complexity : O(n) 
   Where n is the no.of nodes
*/
