/* This program implements Doubly Linked List for creation,insertion and Reversing the Linked List

A Doubly Linked List (DLL) contains an extra pointer, typically called previous pointer, together with next pointer and data which are there in singly linked list.

@author: GudlaArunKumar
@created: 30/06/2020
*/



#include <iostream>
using namespace std;

struct Node{          // Created structure Node which contains Data, previous and Next pointer 
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;         //Declared struct object as First globally

void create(int arr[],int n){   //Creation of Doubly Linked List
struct Node *tmp,*last;
first=new Node;
first->data=arr[0];
first->prev=first->next=NULL;
last=first;
for(int i=1;i<n;i++)
{
 tmp = new Node;
 tmp->data = arr[i];
 tmp->next=last->next;
 tmp->prev=last;
 last->next=tmp;
 last=tmp;
}
 }
 
void display(struct Node *p)   //Displaying the elements in Doubly Linked List while travsersing through Next pointer only
{
     cout <<"Elements in doubly Linked list are:" << endl;
    while(p!=NULL)
    {
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
}

int Length(struct Node *p)   //Calculates Length of DLL
{
    int count =0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

void Insert(int pos,int x)   //Insertion operation takes place with repect to position given by User
{
    struct Node *tmp,*p=first;
    if(pos==0)
    {
     tmp = new Node;
     tmp->data=x;
     tmp->next=first;
     tmp->prev=NULL;
     first->prev=tmp;
     first=tmp;
    }
else
{
    tmp = new Node;
    tmp->data=x;
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    tmp->next=p->next;
    tmp->prev=p;
    if(p->next)
    {
        p->next->prev=tmp;
    }
    p->next=tmp;
}
}

void ReverseList(struct Node *p)   //Reversing the DLL by swapping Prev and Next Pointer of each Node
{
    p=first;
    struct Node *temp;
    while(p!=NULL)
    {
        temp=p->prev;
        p->prev=p->next;
        p->next=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
        {
            first=p;
        }
    }
}

int main(){
    int arr[7]={10,20,30,40,50,60,70};
    int pos,element;
    create(arr,7);
    display(first);   // Displaying DLL
    cout << "Length of List is: " << Length(first) << endl;
    cout << "Enter position and element to insert in the Linked List" << endl;  //Data will be inserted at "Position+1" in Doubly Linked List
    cin >> pos;
    cin >> element;
    Insert(pos,element);
    display(first);
    cout << "After Reversing the Linked List, ";
    ReverseList(first);
    display(first);
    return 0;
}
