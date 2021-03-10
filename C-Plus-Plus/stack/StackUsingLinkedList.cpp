#include<iostream>


using namespace std;

typedef struct Stll {

int data;

struct Stll* next;

}node;

node* top=NULL;

void push()

{



node* temp;

temp = new node();

cout<<" Enter data";

cin>>temp->data;



temp->next = top;



top = temp;

}

void pop()

{

node* temp;



if (top == NULL) {

cout << "\nStack is Underflow" << endl;

}

else {



temp = top;



top = top->next;



temp->next = NULL;


delete(temp);

}

}

void display()

{

node* temp;



if (top == NULL) {

cout << "\nStack is Underflow";

}

else {

temp = top;

while (temp != NULL) {



cout << temp->data << " ";



temp = temp->next;

}

}

}

int main()

{

int ch;

char ans;

do

{

cout<<"1: Push 2: Pop 3: display"<<endl;

cout<<" Enter your desired choice";

cin>>ch;

switch(ch)

{

case 1: push();

break;

case 2:pop();

break;

case 3:display();

}

cout<<"Do you want to continue(y/n)";

cin>>ans;

}while(ans=='y');

return 0;

}