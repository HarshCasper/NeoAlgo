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
