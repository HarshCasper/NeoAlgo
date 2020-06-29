//This program implements Stack Data stucture using Linked List representation

#include <iostream>
using namespace std;
class Node{       //Class Node to store Data and next pointer to next Node
public:
    int data;
    Node *Next;
};

class Stack{
private:
    Node *top;   // Top pointer is declared here
public:
    Stack(){
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
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    st.display();  // Displays all the elements in the Stack
    cout <<"Remove top element " << st.pop() << endl; // Removes Element on top and decrements Top pointer
    st.display();
    return 0;
}
