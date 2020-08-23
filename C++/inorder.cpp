#include<iostream>
using namespace std;
#include<stack>

class treenode{       //class treenode 
    int data;
    treenode *left;
    treenode *right;
    friend class tree;
};

class tree{
    treenode *root;
    public:
    tree(){
        root = NULL;
    }
    void create(){               //create function accepting root and recusively calling other function
        char ch;
        root = new treenode();
        cout<<"Enter the data for root node"<<endl;
        cin>>root->data;
        root->left=root->right=NULL;
        do{
            create(root);
            cout<<"Do u want to enter more data ?"<<endl;
            cin>>ch;
        }
        while(ch=='Y' || ch=='y');
    }
    void create(treenode *root){
        treenode *curr;
        char ch;
        cout<<"Enter the postion l / r where u want to insert the element"<<endl;
        cin>>ch;
        if(ch=='l' || ch=='L'){        //checking if pos is l
            if(root->left==NULL){
                curr = new treenode();
                cin>>curr->data;
                curr->left=curr->right=NULL;
                root->left=curr;
            }
            else{
                create(root->left);
            }
        }
        else if(ch=='r' || ch=='R'){       //checking if pos is r
            if(root->right==NULL){
                curr= new treenode();
                cin>>curr->data;
                curr->left=curr->right=NULL;
                root->right=curr;
            }
            else{
                create(root->right);
            }
        } 
    }
    void inorder_rec(){                  
        inorder_rec(root);
    }
    void inorder_rec(treenode *temp){       //recursive inorder   
        if(temp!=NULL){
            inorder_rec(temp->left);
            cout<<temp->data<<" ";
            inorder_rec(temp->right);
        }
    }
    void inorder_nonrec(){          //non recursive using stack
        treenode *temp;
        stack<treenode *> s;
        temp = root;
        while(1){
            while(temp!=NULL){                //firstly travesing left of tree
                s.push(temp);
                temp=temp->left;
            }
            if(s.empty()){
                break;
            }
            temp = s.top();
            s.pop();
            cout<<temp->data<<" ";
            temp=temp->right; 
        }
        cout<<endl;
    }
};

int main(){
    tree t;
    t.create();
    t.inorder_rec();
    cout<<endl;
    t.inorder_nonrec();
}


/*
OUTPUT:-
Enter the data for root node
3
Enter the postion l / r where u want to insert the element
l
2
Do u want to enter more data ?
y
Enter the postion l / r where u want to insert the element
l
Enter the postion l / r where u want to insert the element
l
1
Do u want to enter more data ?
y
Enter the postion l / r where u want to insert the element
r
4
Do u want to enter more data ?
y
Enter the postion l / r where u want to insert the element
r
Enter the postion l / r where u want to insert the element
r
5
Do u want to enter more data ?
n
1 2 3 4 5
1 2 3 4 5
*/
