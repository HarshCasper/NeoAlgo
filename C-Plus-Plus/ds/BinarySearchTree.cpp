#include <iostream>
using namespace std;

/* A Binary Search Tree (BST) is a tree in which all the nodes follow the below-mentioned properties

The value of the key of the left sub-tree is less than the value of its parent (root) node's key.

The value of the key of the right sub-tree is greater than or equal to the value of its parent (root) node's key.*/

// This program implements insetion,Deletion and Searching in Binary Search Tree(BST)

struct Node{               //Structure is declared which holds Node data and address of left and right child
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;      // root object is declared globally for struct Node

void insert(int element)    //Insertion happens here
{
    struct Node *p=root;   // using 2 pointers for keeping track of Nodes
    struct Node *q,*tmp;
    tmp= new Node;
    tmp->data=element;
    tmp->lchild=tmp->rchild=NULL;
    if(root==NULL)
    {
        root=tmp;
    }
    else
    {
        while(p!=NULL)
        {
            q=p;
            if(p->data==element)
            {
                return;
            }
            else if(element < p->data)  //if Inserted data is less than current Node data, move to left child
            {
                p=p->lchild;
            }
            else{
                p=p->rchild;    //if Inserted data is greater than or equal to current Node data, move to right child
            }
        }
        if(element > q->data) 
        {
            q->rchild=tmp;
        }
        else
            q->lchild=tmp;
    }
}

void Search(Node *p,int key)  //Seraching operation takes key as input and search for key in BST
{
    if(p==NULL)
    {
        cout << " BST is empty" << endl;
    }
    else{
        while(p!=NULL)
        {
            if(p->data==key)
            {
                cout << "Element is found" << endl;
                return;
            }
            else if(key < p->data)
            {
                p=p->lchild;
            }
            else{
                p=p->rchild;
            }
        }
    }
    cout << "Element not found "<<endl;
        
}

void InOrder(Node *p)   //Inorder travesal is used because inorder of BST gives Sorted output
{
    if(p)
    {
        InOrder(p->lchild);
        cout << p->data << " ";
        InOrder(p->rchild);
    }

}

int Height(Node *p)  //To find height of corresponding Node
{
int x,y;
if(p==NULL)return 0;
x=Height(p->lchild);
y=Height(p->rchild);
return x>y?x+1:y+1;
}

/*For deleting any Node on BST, Deleted Node has to be replaced with Appropiate Node without affecting the property of BST
If we are deleting any node, corresponding Node should be replaced by either InOrder predecessor or Inorder Successor based on height condition*/

struct Node * InOrderpredecssor(Node *p)  //If height of left child is greater than right child,it will enter this loop
{
    while(p && p->rchild!=NULL)
    {
        p=p->rchild;
    }
    return p;
}

struct Node * InOrderSuccessor(Node *p)  //If height of left child is less than right child,it will enter this loop
{
    while(p && p->lchild!=NULL)
    {
        p=p->lchild;
    }
    return p;
}

struct Node * Delete(Node *p,int key)
{
    struct Node *q;
    if(p==NULL)
    {
        return NULL;
    }
    if(p->lchild==NULL && p->rchild==NULL)
    {
        delete p;
        return NULL;
    }
    if(key < p->data)
    {
        p->lchild=Delete(p->lchild,key);
    }
    else if(key > p->data)
    {
        p->rchild=Delete(p->rchild,key);
    }
    else
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            q=InOrderpredecssor(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InOrderSuccessor(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
            
        }
    }
return p;
}

int main()
{
    int Num,data,searchdata;
    cout << "Enter Number of data to be instered in BST: "<<endl;
    cin >> Num;
    cout <<"Enter the node values: " << endl;  //Enter the Node values to be inserted into BST
    for(int i=0;i<Num;i++)
    {
        cin >> data;
        insert(data);
    }
    cout <<"Elements in BST are: "<< endl;
    InOrder(root);
    cout << endl;
    cout << "Enter any node value to search in BST:" << endl;
    cin >> searchdata;
    Search(root,searchdata);
    cout <<"Enter the value to be deleted in BST: " << endl;
    cin >> data;
    Delete(root,data);
    cout << "After deleting Node: " << endl;
    InOrder(root);
    cout << endl;
    return 0;
}
