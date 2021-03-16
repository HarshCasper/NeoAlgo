#include <iostream>
#include<queue>
 using namespace std;
//Now first I need to create the structure of node in a binary tree
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

child*buildTree()
{
	int d;
	cin>>d;
	if(d==-1)
  {
		return NULL;
	}
	child*root=new child(d);
	root->LeftPtr=buildTree();
	root->RightPtr=buildTree();
	return root;
}
//Function for implementing level order traversal using Queue
 void levelOrder(child*root)
 { 
     if(root==NULL)
     return;
     queue<child*>q;
     q.push(root);
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

//Main Function starts
 int main()
 {
    cout<<"Input the values of nodes of the tree"<<endl;
    child*root=buildTree();
    cout<<"Level Order Traversal for the following Tree will be:"<<endl;
    levelOrder(root);
 
    return 0;

 }
 //Main Function ends

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
