/* side views of any binary tree
we can view the tree from two sides , i.e left and right.
*/
// including the header files
#include <bits/stdc++.h>
 using namespace std;
 //creating a class to define the node structure
 class Node{
   public://access specifier since all the the members in a class are by default private
     int val;
     Node* left;
     Node* right;
 };
 Node* create(Node* root)
    {
    int x;
    //firstly the left half of the tree will be constructed and then the right half
    cin>>x;
    if (x== -1)
    {
    return NULL;
    } 
    root=new Node;
    root->val=x;
    cout<<"enter left child"<<endl;
    root->left=create(root->left);
    cout<<"enter right child"<<endl;
    root->right=create(root->right);
    return root;
}

   void inorder(Node* root)
   {
   if(!root)
   {
   return;
    }
   inorder(root->left);
   cout<<root->val<<endl;
   inorder(root->right);
   }

 /* we make a fuction "RightView" to print the right side of the tree.
    to print the right view we need to print all the rightmost elements in the level order traversal.
    therefore we approach the problem by defining a queue to store the elements for our each level and checking to print the rightmost node of the level.
 */

 void RightView(Node* root)
 {
 	if (root==NULL)
 	{  
 	return;
    }
   //declaring the queue 
     queue<Node*>q;
     q.push(root);
     //test conditions
     while(!q.empty())
     {
      int 	nodes = q.size();
      for(int i=0;i<nodes;i++)
      {
      	//storing the nodes of each traversal in the a current variable and thereby popping it until we have an empty queue.
      	Node* current = q.front();
      	q.pop();
      	
      	
      	if(i==(nodes-1))//test condition to print the rightmost node in the presesnt level .
      	{
      		cout<<current->val<<" ";
		  }
		  //checking if the nodes have any successor nodes, if they are presesnt we push them in the queue.
		  
		  if (current->left!=NULL)
		  {
		  	q.push(current->left);
		  }
		  if (current->right!=NULL)
		  {
		  	q.push(current->right);
		  }
	  }
	 }
 }

 /* we make a fuction "LeftView" to print the left side of the tree.
    to print the left view we need to print all the leftmost elements in the level order traversal.
    therefore we approach the problem by defining a queue to store the elements for our each level and checking to print the leftmost node of the level.
 */
void LeftView(Node* root)
{
	if(root==NULL)
	{
		return;
	}
	//declaring the queue 
	queue<Node*>q;
	q.push(root);
	//test condition
	while(!q.empty())
	{
	 int nodes=q.size();
	for(int i=1;i<=nodes;i++)
	{
		//storing the nodes of each traversal in the a current variable and thereby popping it until we have an empty queue.
		Node* current=q.front();
		q.pop();
		
		if(i==1) //test condition to print the leftmost node in the presesnt level
		   {
			cout<<current->val<<" ";
		   }
		    //checking if the nodes have any successor nodes, if they are presesnt we push them in the queue.
		 if (current->left!=NULL)
		  {
		  	q.push(current->left);
		  }
		  if (current->right!=NULL)
		  {
		  	q.push(current->right);
		  }
	}
}
}

// declaring the main fuction and contructing the binary tree.

   int main()
   {
   Node *root=NULL;
   cout<<"enter the node value, enter -1 to assign NULL to the node"<<endl;
  root= create(root);
  //printing the inorder sequqnce to check if the tree is biult correctly.
  cout<<"Inorder Sequence:"<<endl;
  inorder(root);
  //printing the Right Side View of the Tree.
  cout<<"Right Side View of the Tree:"<<endl;
  RightView(root);
  cout<<endl;
  //printing the Left Side View of the Tree.
  cout<<"Left Side View of the Tree:"<<endl;
  LeftView(root);
  cout<<endl;
  cout<<"\n";
   return 0;
}

/*
 Time Complexity:O(n)
 
 Space Compleity:O(1)
 
*/
/*for example given a binary tree as considered in the solution
       
	   
	     1
     /   \
    2    3
   / \  / \
  4  5 6  7
   \     /
   8    9
        \1
        10
        
        here the root node is 1
        Output:
        the right side view of the tree would print : 1 3 7 9 10
        
        the left side view of the tree would print : 1 2 4 8 10*/
   
   
