#include <iostream>
#include<queue>
using namespace std;
 
//Creating strucuture for child
struct child
{
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

//Function to build tree Recursively 
child*buildTree()
{
	int d;
	cin>>d;
	if(d==-1)
  {
		return NULL;
	}
	//Inserting value into root
	child*root=new child(d);
	//Inserting value into left Subtree
	root->LeftPtr=buildTree();
	//Inserting value into Right Subtree
	root->RightPtr=buildTree();
	return root;
}

//Function for implementing level order traversal using Queue
 void levelOrder(child*root)
 { 
     if(root==NULL)
     return;
     //If the root is NULL,simply return
     queue<child*>q;
     //push the root value into the Queue
	 q.push(root);
     /*Create a t pointer and initially point it to the front of queue
       If there is any value on left or Right push it on Queue and simply 
	    pop it out on every iteration untill queue becomes empty*/
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
 { //Input Values here
    cout<<"Input the values of nodes of the tree"<<endl;
    child*root=buildTree();
    cout<<"Level Order Traversal for the following Tree will be:"<<endl;
    levelOrder(root);
    return 0;
}
  

 /*
    
   Time Complexity: O(n)
   
                1
               /
              2
             /
            3
           /
          4 
         /
       5
   
   Output:
   1
   2
   3
   4
   5
   
   */
