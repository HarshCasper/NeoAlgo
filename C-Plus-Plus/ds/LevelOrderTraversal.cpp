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

//Simple recursive function for implementing inorder traversal,why inorder here,inorder to compare with levelorder
 void inorder(child*root)
 {
     if(root!=NULL)
     {
       inorder(root->LeftPtr);
       cout<<root->data<<" "<<endl;
       inorder(root->RightPtr);
     }
 }

//Main Function starts
 int main()
 {
     child* root = new child(1);
     root->LeftPtr = new child(2);
     root->RightPtr = new child(3);
     
     root->LeftPtr->LeftPtr = new child(4);
     
     cout<<"Elements after In Order Traversal:"<<endl;
     inorder(root);
     cout<<"Elements after Level Order Traversal:"<<endl;
     levelOrder(root);
 
    return 0;

 }
 //Main Function ends

 /*Examples:
     1
    /  \
   2    3
  /   /   \
 4   NULL NULL
  Output:
   Inorder: 4 2 1 3
   Levelorder: 1 2 3 4