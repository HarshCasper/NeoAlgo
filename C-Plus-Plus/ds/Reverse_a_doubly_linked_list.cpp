// C++ Program to implement doubly linked list with varoius operation

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

// Node declaration

struct Node {
   int data;
   struct Node *prev;  // pointer to previous node
   struct Node *next;  // pointer to next node
};
struct Node* head,*tail;

// Create a node

void create()
 {
   struct Node* newnode;
   newnode=new(struct Node);
   cout<<"\nenter the data :";
   cin>>newnode->data;
   newnode->prev = NULL;
   newnode->next = NULL;
   if(head == NULL)
   head=tail=newnode ;
   else
   {
     tail->next=newnode;
     newnode->prev=tail;
     tail=newnode;
   }
}

// Insert a node at beginning of the list
void insert_at_beg()
{
  struct Node* newnode;
  newnode=new(struct Node);
  cout<<"\ninset a data at begining :";
  cin>>newnode->data;
  newnode->prev=NULL;
  
  head->prev=newnode;
  newnode->next=head;
  head=newnode;
}

// Insert a node at end of the list
void insert_at_end()
{
  struct Node* newnode;
  newnode=new(struct Node);
  cout<<"\nenter a data at end :";
  cin>>newnode->data;
  newnode->next=NULL;
  newnode->prev=NULL;
  
  if(head==NULL)
  head=tail=newnode;
  else
  {
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
  }
}

// Count total numbers of node in a list
int count(struct Node* ptr = head)
{
  int cnt = 0;
  while(ptr!= NULL)
  {
    ptr=ptr->next;
    cnt++;
 }
  cout<<"\n total numbers of nodes : "<<cnt;
  return cnt;
}

// Insert a node at a particular position in a list
void insert_at_specific_postion()
{
  int pos,i=1,count1;
  cout<<"\n enter the position to insert a data :";
  cin>>pos;
  count1=count();
  if(pos<1 || pos>count1)
  {
    cout<<"invalid position \n";
  }
  else if(pos==1)  // If user want to enter a node at beginning only then simply call insert_at_beg function
  {
    insert_at_beg();
  }
  else
  {
    struct Node *newnode,*temp;
    temp=head;
    newnode=new(struct Node);
    cout<<"\nenter a data :";
    cin>>newnode->data;
    while(i < pos-1)
    {
      temp=temp->next;
      i++;
    }
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->next->prev=newnode;
  }
}

// Insert a node after a given position in a list
void insert_after_position()
{
  int pos,i=1,count1;
  cout<<"\nenter the position after which the elements is to inserted :";
  cin>>pos;
  count1=count();
  if(pos<0 || pos>count1)
  {
    cout<<"\ninvalid position ";
  }
  else
  {
    struct Node* newnode,*temp;
    temp=head;
    newnode=new(struct Node);
    cout<<"\nenter a data :";
    cin>>newnode->data;
    while(i<pos)
    {
      temp=temp->next;
      i++;
    }
    newnode->prev=temp;
    newnode->next=temp->next;
    temp->next=newnode;
    newnode->next->prev=newnode;
  }
}

// Delete a node of present at beginning 
void detele_from_beg()
{
  struct Node *temp;
  if(head==NULL)
  {
    cout<<"\n doubly linked list is empty ";
  }
  else
  {
    temp=head;
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
    cout<<"deleted data is :"<<temp;
    free(temp);
  }
}

// Delete a node which is present at the end of list
void delete_from_end()
{
  struct Node* temp;
  if(tail == NULL)
  {
    cout<<"\n empty";
  }
  else
  {
    temp=tail;
    tail->prev->next=NULL;
    tail=tail->prev;
    cout<<"\ndeleted data is :"<<temp->data;
    free(temp);
  }
}

// Delete a node
void delete_from_pos()
{
  int pos,i = 1,count1;
  struct Node* temp;
  temp=head;
  count1=count();
  cout<<"\n enter the position to be deleted :";
  cin>>pos;
  if(pos < 0 || pos > count1)
  {
    cout<<"\n invalid position...";
  }
  else
  {
    while(i < pos)
    {
      temp=temp->next;
      i++;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    cout<<"deleted data ia :"<<temp->data;
    free(temp);
  }
  
}

// Display all nodes of list
void display() {
   struct Node* ptr;
   ptr = head;
   if(ptr==NULL)
   cout<<"doubly linked list is empty";
   ptr=head;
   while(ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}

// Reverse a list
void reverse()
{
    struct Node *ptr1, *ptr2;
    ptr1 = head;
    if(ptr1 == NULL)
    {
          cout<<"doubly linked list is empty";
    }
    else
    {
    ptr1 = head;
    ptr2 = ptr1->next;
    ptr1->next = NULL;
    ptr1->prev = ptr2;
    while (ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    }
    
    head = ptr1;
    cout<<"list reveser : "<<" ";
    while (ptr1 != NULL)
    {
      cout<<ptr1->data<<" ";
      ptr1 = ptr1->next;
    }
    
    
}
// main function 
int main() {
   int choice;
   do
   {
     cout<<"\n 1. Create a node \n 2. Insert at beg \n 3. Insert at end  \n 4. Insert after postion \n" ;
     cout<<" \n 5. Insert before position \n 6. Display \n 7. delete from beginning \n";
     cout<<" \n 8. Delete a node from end \n 9. Delete node from any position \n 10. Reverse \n 11. count \n 12. Exit";
     cout<<"\n enter you choice :";
     cin>>choice;
     switch(choice)
     {
       case 1 : create(); break;
       case 2 : insert_at_beg(); break;
       case 3 : insert_at_end(); break;
       case 4 : insert_after_position(); break;
       case 5 : insert_at_specific_postion(); break;
       case 6 : display(); break;
       case 7 : detele_from_beg(); break;
       case 8 : delete_from_end(); break;
       case 9 : delete_from_pos(); break;
       case 10 : reverse(); break;
       case 11 : count(); break;
       case 12 : exit(0); 
       default : cout<<"enter correct choice :";
         
     }
   }
   while(choice!=12);
   return 0;

}
    