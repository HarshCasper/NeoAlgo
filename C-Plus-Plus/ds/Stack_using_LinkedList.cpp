/*This program implements Stack Data stucture using Linked List representation
//by @GudlaArunKumar
 Stack using Vector
*/

#include <bits/stdc++.h>
using namespace std;                        // Stack class and its functions
template<typename T>
class Stack{

    vector<T> v;
public:
    void push(T d){
        v.push_back(d);
    }
    void pop()
    {
        if(v.size()==0){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            v.pop_back();
        }
    }   
    T top(){
        return v[v.size()-1];
    }
    bool empty(){
        return v.size()==0;
    }
    int size(){
        return v.size();
    }
};

#include <iostream>
using namespace std;
class Node{                  //Class Node to store Data and next pointer to next Node
public:
    int data;
    Node *Next;
};
class StackLinkedList{
private:
    Node *top;   // Top pointer is declared here
public:
    StackLinkedList(){
        top=NULL;
    }
    void push(int x)
    {
        Node *t=new Node;  //If heap is full, then Stack Overflow occurs
        if(t==NULL)
        {
            cout <<"Stack overflow" << endl;
        }
        else{
            t->data=x;     // Top pointer points to Last Inserted Node
            t->Next=top;
            top=t;
        }
    }
    int pop()    // Returns the elements at the Top 
    {
        int x=-1;
        if(top==NULL)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            Node *p=top;
            x=p->data;
            top=top->Next;
            delete p;
        }
    return x;
    }
    void display()
    {
        cout << "Elements in the stack: "<< endl;
        Node *q=top;
        while(q!=NULL)
        {
            cout << q->data << " ";
            q=q->Next;
        }
        cout << endl;
    }
};
int main() 
{
    Stack<int> s;
    // Inserting elements in stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<<"Size of stack :   "<<s.size()<<endl;
    cout<<"Stack elements"<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    cout<<"Tring to pop element when stack is empty"<<endl;
    s.pop();
}
