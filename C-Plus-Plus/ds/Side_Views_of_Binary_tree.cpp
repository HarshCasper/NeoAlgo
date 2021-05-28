/* side views of any binary tree
we can view the tree from two sides , i.e left and right.
 for example given a binary tree as considered in the solution
       
	   
	   1
     /   \
    2    3
   / \  / \
  4  5 6  7
   \     /
   8    9
        \
        10
        
        here the root node is 1
        the right side view of the tree would print 1 3 7 9 10
        the left side view of the tree would print  1 2 4 8 10
*/
// including the header files
 #include<bits/stdc++.h>
 using namespace std;
   //defining the node structure
   struct Node{
   	int data;
   	Node*left, *right;
   	// constructor
   	Node(int value){
   		data=value;
   		left=NULL;
   		right=NULL;
	   }
   };
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
      		cout<<current->data<<" ";
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
			cout<<current->data<<" ";
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
  	Node*root=new Node(1);
  	root->left=new Node(2);
  	root->right=new Node(3);
  	root->left->left=new Node(4);
  	root->left->right=new Node(5);	
	root->right->left=new Node(6);
  	root->right->right=new Node(7);
  	root->left->left->right=new Node(8);
  	root->right->right->left=new Node(9);
  	root->right->right->left->left=new Node(10);
  	//function calling to print the side views.
  	cout<<"right view:"<<endl;
  	RightView(root);
  	 cout<<endl;
  	 cout<<"left view:"<<endl;
  	LeftView(root);
	cout<<endl; 
  	
  	return 0;
  }
