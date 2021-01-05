#include <iostream>
#include<algorithm>
#include<cstdlib>
#include <math.h>
#define COUNT 10
using namespace std;

typedef struct  Node
{
  int data;
  int leftflag,rightflag; // 1 for address of child, 0 address of parent
  struct Node *left,*right;

}Node;
void add(Node **p, int v)
{
    Node * newnode=(Node*)malloc(sizeof(Node));
    newnode->data=v;
    newnode->leftflag =0; // by default both the flags will be 0
    newnode->rightflag=0; 
    if(*p==NULL) // if its the root node it will have no inorder predecessor or successor
    {
        newnode->left=NULL;
        newnode->right=NULL;
        *p=newnode;
    }
    else
    {
        Node* temp=*p;
        while(1){ // This loop will find the inorder predecessor or successor
            if(temp->data > v && temp->leftflag == 1)
                temp = temp->left;
            else if(temp->data < v && temp->rightflag == 1)
                temp = temp->right;
            else
                break;
        }
        // temp is now the inorder predecessor or successor
        if(temp->data < v){ // This will update the new node that is created with the links to its inorder predecessor or successor
            newnode->right = temp->right;
            temp->right = newnode; // points at the child
            temp->rightflag=1;
            newnode->left = temp; // points at the parent
        }else{
            newnode->left = temp->left;
            temp->left = newnode; // points at the child
            temp->leftflag=1;
            newnode->right = temp; // points at the parent
        }
    }
}
void inorder(Node *p){
    while(1){
        while(p->leftflag) // goes to left most
            p=p->left;
        cout<<p->data<<" ";
        while(!p->rightflag){ // right flag must be 0 so that it goes to the parent and not the child
            p=p->right;
            if(p== NULL)
                return;
            cout<<p->data<<" ";
        }
        p=p->right;
    }
}

int TBTsearch(Node*p,int value){ // returns 1 if present else 0
    while(1){
        if(p->data>value && p->leftflag){ // left flag must be 1 to make sure it goes to the child and not the parent
            p=p->left;
        }
        else if(p->data<value && p->rightflag){ // right flag must be 1 to make sure it goes to the child and not the parent
            p=p->right;
        }
        else{
            break; // the element has been found or reached the end and value is not found so does not exist in the tree 
        }
    }
    if(p->data==value){
        return 1; 
    }
    return 0;
}


int main()
{
    /*
    This is how the tree will look like
    - means the flag values for that node is 1
        
    
                        -50-
                       /   \
                     40    -70-
                          /    \
                         60    80
    
    
    */
    Node *root=NULL;
    add(&root,50); 
    add(&root,70);
    add(&root,80);
    add(&root,40);
    add(&root,60);
    inorder(root);
    cout<<endl;
    cout<<TBTsearch(root,10)<<endl;
    cout<<TBTsearch(root,80)<<endl;
    return 0;
}
// Contributed by Vaishnavi Shah