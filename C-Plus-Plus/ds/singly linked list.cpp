/*
All Basics Features of singly Linked List

@author: Rishikeshrajrxl
@created: 16/08/2020
*/


#include <iostream>
using namespace std;

struct node
{                                //declaration of node
int data;
struct node*next;
}*ptr,*head,*tail,*temp;         //pointer to node

void Insert_At_Front();
void Insert_At_End();
void Insert_At_Pos();            //function declaration
void Delete_At_Front();
void Delete_At_End();
void Display();
void Length();
int ele;			//ele is the input data from the user


int main()              //Main Function Begins Here
{
int ch;

do{
cout<<"1) Insert at Front"<<endl;
cout<<"2) Insert at End"<<endl;
cout<<"3) Insert at position"<<endl;
cout<<"4) Delete at Front"<<endl;
cout<<"5) Delete at End"<<endl;
cout<<"6) Display"<<endl;
cout<<"7) Length"<<endl;
cout<<"8) Exit"<<endl;
cout<<"**************************************\n ENTER YOUR CHOICE: "<<endl;
cin >>ch;
  switch(ch)
  {
    case 1:
    Insert_At_Front();
    break;

    case 2:
    Insert_At_End();
    break;

    case 3:
    Insert_At_Pos();
    break;

    case 4:
    Delete_At_Front();
    break;

    case 5:
    Delete_At_End();
    break;

    case 6:
    Display();
    break;

    case 7:
    Length();
    break;

    case 8:
    exit(0);
    break;
  }
}while(ch!=0);
    return 0;
}
//-------------------------------------------------------------
void Insert_At_End()
{
    ptr=(struct node*)malloc(sizeof(struct node));
    cout<<"ENTER THE ELEMENT"<<endl;
    cin>>ele;
    ptr->data=ele;
    ptr->next=NULL;
if(head==NULL)
 {
    head=ptr;
    tail=ptr;
 }
 else
 {
    tail->next=ptr;
    tail=ptr;
 }
}
//--------------------------------------------------------------
void Insert_At_Front()
{
    ptr=(struct node*)malloc(sizeof(struct node));
    cout<<"ENTER THE ELEMENT"<<endl;
    cin>>ele;
    ptr->data=ele;
if(head==NULL)
 {
    head=ptr;
    tail=ptr;
    ptr->next=NULL;
 }
else
 {
    ptr->next=head;
    head=ptr;
 }
}

//-------------------------------------------------------------
void Insert_At_Pos()
{

    int loc;
    struct node*pos;
    ptr=(struct node*)malloc(sizeof(struct node));
    cout<<"ENTER THE ELEMENT"<<endl;
    cin>>ele;
    ptr->data=ele;
    cout<<"ENTER THE LOCATION"<<endl;
    cin>>loc;
    pos=head;

  for(int i=1;i<loc-1;i++)
  {
    pos=pos->next;
  }
  ptr->next=pos->next;
  pos->next=ptr;
}

//-------------------------------------------------------------
void Delete_At_Front()
{
    if(head==NULL)
    cout<<"List is Empty"<<endl;
    else
    {
        ptr=head;
        head=ptr->next;
	   cout<<"Deleted Successfully"<<endl;
        free(ptr);
    }
}

//-------------------------------------------------------------
void Delete_At_End()
{
    if(head==NULL)
    cout<<"List is Empty"<<endl;
    else
    {
        temp=head;
        while(temp->next==NULL)
        {
            ptr=temp;
            temp=ptr->next;
        }
    ptr->next=NULL;
    cout<<"Deleted Successfully"<<endl;
    free(temp);
    }
}
//----------------------------------------------------------------------------------
void Display()                         //Traversing throughout the Linked LIst
{
    int i=1;
    temp=head;
    cout<<"S.No\t Data\t Pointer"<<endl;
    while(temp!=NULL)
    {
        cout<<i<<"\t"<<temp->data<<"\t"<<temp->next<<endl;
        temp=temp->next;
        i++;
    }
    cout<<"****************************************************" <<endl;
}
//------------------------------------------------------------------------------------

void Length()
{

    int i,Count=0;
    temp=head;
    while(temp!=NULL)
    {
        Count+=1;
        temp=temp->next;
        i++;
    }
    cout<<"Total no. of Nodes : "<<Count<<endl;
}
