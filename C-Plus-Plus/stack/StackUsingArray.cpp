#include<iostream>
using namespace std;

#define size 20
typedef struct stack
{
int arr[size];
int top;
}st;
st s;

int stackempty()
{
if(s.top==-1)
return 1;
else
return 0;
}

int stackfull()
{
if(s.top==size-1)
return 1;
else
return 0;
}
void push()
{
int a;
if(stackfull()==1)
{cout<<"Stack is full! Sorry Cannot add element";}
else
{
cout<<"Enter a number to push into the stack";
cin>>a;
s.top++;
s.arr[s.top]=a;
}
}
void pop()
{
if(stackempty()==1)
{
cout<<"Stack is empty! We cannot delete";
}
else
{
cout<<"The deleted element is "<<s.arr[s.top]<<"\n";
s.top--;
}
}
void display()
{
if(stackempty()==1)
{
cout<<"Cannot display as the stack is empty";
   }
   else
   {
    for(int i=s.top;i>=0;i--)
    cout<<s.arr[i]<<"\n";
   }
}
int main()
{
int ch;
char ans;
s.top=-1;
do
{
cout<<"Select one of the below:"<<endl;
cout<<"1.Push"<<endl;
cout<<"2.Pop"<<endl;
cout<<"3.Display"<<endl;
cout<<"Enter your choice:"<<endl;
cin>>ch;
switch(ch)
{
case 1:push();
   break;
case 2:pop();
   break;
case 3:display();
   break;
}
cout<<"Do you want to continue?(y/n)"<<endl;
cin>>ans;

}while(ans=='y');
}