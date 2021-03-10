#include <iostream>
using namespace std;
#define MAX 5
 
//Declaration of Stack
class Stack
{
    private:
        int top;
        int ele[MAX];
    public:
        Stack();
        int     isFull();
        int     isEmpty();
        void    push(int item);
        int     pop(int *item);
}; 
 
//Initialization of stack
Stack:: Stack()
{
    top = -1;
}
 
//Check stack is full or not
int Stack:: isFull()
{
    int full = 0;
 
    if( top == MAX-1 )
        full = 1;
 
    return full; 
}
 
//Check stack is empty or not
int Stack:: isEmpty()
{
    int empty = 0;
 
    if( top == -1 )
        empty = 1;
 
    return empty;
}
 
//Insert item into stack
void Stack:: push( int item )
{
    if( isFull() )
    {
        cout<<"\nStack Overflow";
        return;
    }
 
    top++;
    ele[top] = item;
 
    cout<<"\nInserted item : "<< item;  
}
 
//Delete item from stack
int Stack:: pop( int *item )
{
    if( isEmpty() )
    {
        cout<<"\nStack Underflow";
        return -1;
    }
 
    *item = ele[top--];
    return 0;
}
 
int main()
{ 
    int item = 0;
 
    Stack s = Stack();
 
    s.push( 10 );
    s.push( 20 );
    s.push( 30 );
    s.push( 40 );
    s.push( 50 );
    s.push( 60 );
 
 
    if( s.pop(&item) == 0 )
        cout<<"\nDeleted item : "<< item;
    if( s.pop(&item) == 0 )
        cout<<"\nDeleted item : "<< item;
    if( s.pop(&item) == 0 )
        cout<<"\nDeleted item : "<< item;
    if( s.pop(&item) == 0 )
        cout<<"\nDeleted item : "<< item;
    if( s.pop(&item) == 0 )
        cout<<"\nDeleted item : "<< item;
    if( s.pop(&item) == 0 )
        cout<<"\nDeleted item : "<< item;
 
    cout<< endl;
 
    return 0;
}
