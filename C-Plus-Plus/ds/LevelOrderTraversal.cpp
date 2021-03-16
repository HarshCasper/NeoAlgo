/*
    Level Order Traversal
    
	Given a binary tree with unique values,print all the elements in 
    a level Order i.e in a BFS( Breadth First Search) order.
    
	Sample Input:
        Enter the values of nodes of the tree  :  1 2 3 4 5 6 -1 -1 -1 -1 -1 -1 -1  
    
	Sample Output:
        Level Order Traversal for the following Tree will be   :  1 2 3 4 5 6
	        
	@author : hritikgupta92
    @created : 16-03-2021
        
*/

#include <iostream>
#include<queue>
using namespace std;
 
//  Basic Definition of node in a Binary Tree

struct child{
    int data;
    child*LeftPtr;
    child*RightPtr;
 
    child(int value)
	{
        data=value;
        LeftPtr=NULL;
        RightPtr=NULL;
    }
}; 

//  Function to build tree Recursively 

child*buildTree()
{
    int d;
	cin>>d;
	
	//  Base Case
	if(d==-1){
		return NULL;
    }

	//  Recursive Case 
	child*root=new child(d);

	//  Inserting value into left Subtree
	root->LeftPtr=buildTree();

	//  Inserting value into Right Subtree
	root->RightPtr=buildTree();

	return root;
}

//  Function for implementing level order traversal using Queue
 
 void levelOrder(child*root)
 { 
     //  Base Case
	 if(root==NULL)
     return;
    
	 queue<child*>q;
    
	 //  push the root value into the Queue
	 q.push(root);
      
	 //  Recursive Case 
     while(!q.empty())
     {
          child*t=q.front();
          cout<<t->data<<endl;
           
		   if(t->LeftPtr)
           q.push(t->LeftPtr);
           if(t->RightPtr)
           q.push(t->RightPtr);
         
		   q.pop();
     }
      
 }
  
int main()
{ 
    //  Input Values here
    cout<<"Enter the values of nodes of the tree: "<<endl;
     
	child*root=buildTree();
    
	cout<<"Level Order Traversal for the following Tree will be:"<<endl;
     
	levelOrder(root);
     
	return 0;
}
  

  
