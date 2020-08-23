/*
Implement the basic functionality of stack using Array Data structure
@author: Rishikeshrajrxl
@created: 17/08/2020
*/

#include <iostream>
using namespace std;

void Push();             //Function declaration
void Peek();           
void Pop();
void Is_Empty();
void Is_Full();
void Display();
void count();
int stack_size,top=0,stack[100];         

int main()              //Main() starts
{
int ch;
cout<<"ENTER THE STACK SIZE : ";     //taking stack size initally from the user.
cin>>stack_size;
cout<< "\n\n\t Implement the basic functionality of stack"<<endl;         //Displaying the Features in a tabular manner         
cout<<"\t **************************************************"<<endl;
do
{
cout<<"\t 1) Push\t \t 2) Pop "<<endl; 
cout<<"\t 3) Peek\t \t 4) Is_Empty"<<endl;
cout<<"\t 5) Is_Full\t \t 6) Display"<<endl;
cout<<"\t 7) count\t \t 8) Exit"<<endl;
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
    Is_Full();
    break;

    case 6:
    Display();
    break;

    case 7:
    count();
    break;
    
    case 8:
    exit(0);
    break;
    
    default:
    cout<<"Invalid Input. Please enter the Number between 1 to 8 \n"<<endl;
  }
}while(ch!=0);
    return 0;
}                       // Main() Ends
//--------------------------------------------------------------------------
void Push()             //Insertion at the top 
{
    int ele;
    if(top==stack_size){
        cout<<"Stack is Full."<<endl;
    }
    else{
        cout<<"ENTER THE ELEMENT :";
        cin>>ele;
        top+=1;
        stack[top]=ele;
        cout<<"Pushed Successfully"<<endl;
    }
}
//---------------------------------------------------------------------------
void Pop()                //deletion from the top
{
    if(top==0){
        cout<<"Stack is Empty"<<endl;
    }
    else{
        top=top-1;
        cout<<"Poped Successfully"<<endl;
    }
}
//---------------------------------------------------------------------------
void Peek()             //returns the value of the top
{
    if(top==0){
        cout<<"Stack is Empty"<<endl;
    }
    else{
        cout<<"Peek value is : "<<stack[top]<<endl;
    }
}
//-----------------------------------------------------------------------------
void Is_Full()          //returns Yes if Full, else No
{
    if(top==stack_size){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
//-----------------------------------------------------------------------------
void Is_Empty()           //returns Yes if Empty, else No
{
    if(top==0){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
//------------------------------------------------------------------------------

void Display()           //returns all the value inside the Stack
{
    cout<<"ELEMENT IN THE STACK : ";
    for(int i=top;i>0;i--)
    {
        cout<<stack[i]<<" ";
    }
    cout<<"\n";
}
//-------------------------------------------------------------------------------
void count()        //returns the length of stack 
{
    cout<<"Length of Stack : "<<top<<endl;
}
