#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){               //constructor
        data=val;
        next=NULL;
    }
};
void insertAtHead(node* &head, int val){
    node* n =new node(val);            //object
    n->next=head;
    head=n;
}

void inserAtTail(node* &head, int val){
    node* n= new node(val);          //object

    if(head==NULL){
        head=n;
        return ;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;

}

void display(node*head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){


    node* head=NULL;
    inserAtTail(head,1);
    inserAtTail(head,2);
    inserAtTail(head,3);
    display(head);
    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtHead(head,6);
    
    display(head);
   
   
    return 0;
}