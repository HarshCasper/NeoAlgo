/*
Implement the basic functionality of stack using Linked List Data structure

@author: Rishikeshrajrxl
@created: 17/08/2020
*/

#include <iostream>
using namespace std;

struct node
{                          //declaration of node
int data;
struct node*next;
}*head=NULL,*temp,*ptr;

void Push();             //Function declaration
void Peek();           
void Pop();
void Is_Empty();
void Display();
void count();
int ele;

int main()              //Main() starts
{
int ch;
cout<< "\n\n\t Implement the basic functionality of stack"<<endl;         //Displaying the Features in a tabular manner         
cout<<"\t **************************************************"<<endl;
do{
cout<<"\t 1) Push\t \t 2) Pop "<<endl; 
cout<<"\t 3) Peek\t \t 4) Is_Empty"<<endl;
cout<<"\t 5) Display\t \t 6) count"<<endl;
cout<<"\t 7) Exit"<<endl;
cout<<"\t ***************************************************\nENTER YOUR CHOICE : ";
cin >>ch;
  switch(ch)
  {
    case 1:
    Push();
    break;

    case 2:
    Pop();
    break;

    case 3:
    Peek();
    break;

    case 4:
    Is_Empty();
    break;

    case 5:
    Display();
    break;

    case 6:
    count();
    break;
    
    case 7:
    exit(0);
    break;
    
    default:
    cout<<"Invalid Input. Please enter the Number between 1 to 7 \n"<<endl;
  }
}while(ch!=0);
    return 0;
}                       // Main() Ends
//--------------------------------------------------------------------------
void Push()             //Insertion at the top 
{
    ptr=(struct node*)malloc(sizeof(struct node));
    cout<<"ENTER THE ELEMENT : ";
    cin>>ele;
    ptr->data=ele;
    ptr->next=head;
    head=ptr;
    cout<<"Pushed Successfully"<<endl;
}
//---------------------------------------------------------------------------
void Pop()                //deletion from the top
{
    if(head==NULL){
        cout<<"Stack is Empty"<<endl;
    }
    else{
        temp=head;
        head=head->next;
        cout<<"Poped Successfully"<<endl;
        free(temp);
    }
}
//---------------------------------------------------------------------------
void Peek()             //returns the value of the top
{
    cout<<"Peek Value is : "<< head->data<<endl;
}
//-----------------------------------------------------------------------------
void Is_Empty()           //returns Yes if Empty, else No
{
   if(head==NULL)
     cout<<"Yes"<<endl;
   else
     cout<<"No"<<endl;
}
//------------------------------------------------------------------------------
void Display()           //returns all the value inside the Stack
{
    if(head==NULL){
        cout<<"Stack is Empty "<<endl;
    } else{
        temp=head;
        cout<<"Data In Stack : ";
        while(temp!=NULL){
             cout<<temp->data<<" ";
             temp=temp->next;
        }cout<<""<<endl;
    }
}
//-------------------------------------------------------------------------------
void count()        //returns total no of nodes in stack
{
   int count=0;
   temp=head;
   while(temp!=NULL){
       count+=1;
       temp=temp->next;
   } cout<<"Total No is : "<<count<<endl;
}
