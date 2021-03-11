// C++ Program to reverse a doubly linked list.

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
   cout<<"\n enter the data :";
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
     cout<<"\n 1. Create a node \n 2. Count \n 3. Display \n 4 Reverse \n 5. Exit" ;
     cout<<"\n enter you choice :";
     cin>>choice;
     switch(choice)
     {
       case 1 : create(); break;
       case 2 : count(); break;
       case 3 : display(); break;
       case 4 : reverse(); break;
       case 5 : exit(0); break;
       default : cout<<"enter correct choice :";
         
     }
   }
   while(choice != 5);
   return 0;
}

/* 
 1. Create a node 
 2. Count 
 3. Display 
 4 Reverse 
 5. Exit
 enter you choice :1

enter the data :11

 1. Create a node 
 2. Count
 3. Display       
 4 Reverse
 5. Exit
 enter you choice :1

enter the data :22

 1. Create a node
 2. Count
 3. Display
 4 Reverse
 5. Exit
 enter you choice :2

 total numbers of nodes : 2
 1. Create a node
 2. Count
 3. Display
 4 Reverse
 5. Exit
 enter you choice :3
11 22
 1. Create a node
 2. Count
 3. Display
 4 Reverse
 5. Exit
 enter you choice :4
list reveser :  22 11
 1. Create a node
 2. Count
 3. Display
 4 Reverse
 5. Exit
 enter you choice :5
 */