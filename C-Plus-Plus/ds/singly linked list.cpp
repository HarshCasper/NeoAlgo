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
cout<< "\n\n\t All Basic Features of Singly Linked List"<<endl;         //Displaying the Features in a tabular manner         
cout<<"\t **************************************************"<<endl;

do
{
cout<<"\t 1) Insert at Front\t \t 2) Insert at End "<<endl; 
cout<<"\t 3) Insert at position\t \t 4) Delete at Front"<<endl;
cout<<"\t 5) Delete at End\t \t 6) Display"<<endl;
cout<<"\t 7) Length\t \t\t 8) Exit"<<endl;
cout<<"\t ***************************************************\n ENTER YOUR CHOICE: "<<endl;
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
    
    default:
    cout<<"Invalid Input. Please enter the Number between 1 to 8 "<<endl;
    
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
         cout<<"Inserted Successfully."<<endl;
         cout<<"\t **************************************************"<<endl;
 }
 else
 {
    tail->next=ptr;
    tail=ptr;
          cout<<"Inserted Successfully."<<endl;
          cout<<"\t **************************************************"<<endl; 
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
     cout<<"Inserted Successfully."<<endl;
     cout<<"\t **************************************************"<<endl;
 }
else
 {
    ptr->next=head;
    head=ptr;
      cout<<"Inserted Successfully."<<endl;
      cout<<"\t **************************************************"<<endl;

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
      cout<<"Inserted Successfully."<<endl;
      cout<<"\t *************************************************"<<endl;

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
	   cout<<"\t **************************************************"<<endl;
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
    cout<<"\t **************************************************"<<endl;
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
    cout<<"\t ***********************************************"<<endl;
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
    cout<<"\t ***********************************************"<<endl;
}
