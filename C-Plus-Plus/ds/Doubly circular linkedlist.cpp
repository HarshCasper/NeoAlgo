// doubly circular linkedlist is a cpmplex type of data structure in which a node contains pointers to its
//previous node as well as next node. the first node of the list also contains address of the
//last node in its previous pointer.

#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node * next;
    Node * pre;

} *head,*temp,*newnode,*tail;
void insert_beg(int);
void insert_end(int);
void insert_pos(int);
void display(Node*);
void del_beg();
void del_end();
void del_pos();
void EXIT();
int main()
{
    int a,b,c;
    head=NULL;
    int ch=1;
    while(ch<8)
    {
        cout<<"PRINT MENU"<<endl;
        cout<<"1. Insert from Beginning"<<endl;
        cout<<"2. Insert from End"<<endl;
        cout<<"3. Insert at any Position"<<endl;
        cout<<"4. Delete from Beginning"<<endl;
        cout<<"5. Delete from End"<<endl;
        cout<<"6. Delete at any Position"<<endl;
        cout<<"7. Display"<<endl;
        cout<<"8. EXIT"<<endl;
        cout<<"Accept your choice";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"accept the value of a"<<endl;
            cin>>a;
            insert_beg(a);
            break;
            case 2:
            cout<<"accept the value of b"<<endl;
            cin>>b;
            insert_end(b);
            break;
            case 3:
            cout<<"accept the value of c"<<endl;
            cin>>c;
            insert_pos(c);
            break;
            case 4:
            del_beg();
            break;
            case 5:
            del_end();
            break;
            case 6:
            del_pos();
            break;
            case 7:
            display(head);
            break;
            case 8:
            EXIT();
            break;
            default:
            cout<<"wrong choice";
        }

    }
    return 0;
}
// to display the linked list
void display(Node * p)
 {
     temp=p;
     if(p==NULL)
     {
         cout<<"Nothing to display";
     }
     else
     {
        
        while(temp!=tail)
        {
            cout<<temp->data;
            temp=temp->next;
        }
        cout<<temp->data;
     }
 }
 
 // to insert a newnode at the beginning
 void insert_beg(int r)
 {
     newnode= new Node();
     newnode->data=r;
     if(head==NULL)
     {
         head=tail=newnode;
         newnode->pre=tail;
         newnode->next=head;
     }
     else
     {
         newnode->next=head;
         head->pre=newnode;
         newnode->pre=tail;
         tail->next=newnode;
         head=newnode;
     }
 }
 // to insert a newnode at end
 void insert_end(int r)
 {
     newnode= new Node();
     newnode->data=r;
     if(head==NULL)
     {
         head=tail=newnode;
         newnode->pre=tail;
         newnode->next=head;
     }
     else
     {
         newnode->pre=tail;
         tail->next=newnode;
         newnode->next=head;
         head->pre=newnode;
         tail=newnode;
     }  
 }
 // to insert a newnode at any position
 void insert_pos(int r)
 {  
    int pos,i=1;
     cout<<"enter the position"<<endl;
     cin>>pos;
     newnode= new Node();
     newnode->data=r;
     if(head==NULL)
     {
         head=tail=newnode;
         newnode->pre=tail;
         newnode->next=head;
     }
     else
     {   head=temp;
     while(i<pos-1)
     {
         temp=temp->next;
         i++;
     }
         newnode->pre=temp;
         newnode->next=temp->next;
         newnode->next=head;
         temp->next->pre=newnode;
         temp->next=newnode;
     }    
 }
 // to delete a node from beginning
 void del_beg()
 {
     if(head==NULL)
     {
         cout<<"NOTHING TO DELETE";
     }
     else
     {
        temp=head;
        head=head->next;
        head->pre=NULL;
        delete temp;
     }
 }
 // to delete a node from end
 void del_end()
 {
     if(tail==NULL)
     {
         cout<<"NOTHING TO DELETE";
     }
     else
     {
        temp=tail;
        tail->pre->next=NULL;
        tail=tail->pre;
        delete temp;
     }
 }
 // to delete a node from any position
 void del_pos()
 {  
    int pos,i=1;
     cout<<"enter the position"<<endl;
     cin>>pos;
     if(head==NULL)
     {
         cout<<"nothing to delete";
     }
     else
     {   temp=head;
     while(i<pos)
     {
         temp=temp->next;
         i++;
     }
         temp->pre->next=temp->next;
         temp->next->pre=temp->pre;
         delete temp;
     }    
 }
 void EXIT()
 {
     exit(0);
 }


 /* OUTPUT
 Accept your choice:2
 Accept the valueof a:4
 Accept your choice:1
 Accept the valueof a:5
 Accept your choice:2
 Accept the valueof a:7
 Accept your choice:7
 5 4 7

 Accept your choice:4
 Accept your choice:7
 4 7
 Accept your choice:6
 enter the position:2
 Accept your choice:7
 4
 */
 