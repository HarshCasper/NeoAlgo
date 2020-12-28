/*
  Implementing Stack using Queue in Cpp
  ===================================
  For implementing stack using queue we create two queues,
  named q1 and q2 then we make sure that newly entered element is always
  at the front of q1, so that pop operation just dequeues
  from q1 and q2 is used to put every new element at front of q1.
*/

#include<bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q1,q2;
    //To maintain count of elements in stack
    int curr_size;

public:
    Stack()
    {
        curr_size=0;
    }

    void push(int val)
    {
        curr_size++;
        //put val in q2
        q2.push(val);

        //put all the remaining elements in q1 to q2
        while(!q1.empty())
        {
            int x=q1.front();
            q2.push(x);
            q1.pop();
        }
        //swap the names of two queues
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }

    void pop()
    {
        //if no elements are there in q1 to pop
        if(q1.empty())
            return;
        q1.pop();
        curr_size--;
    }

    int top()
    {
        //if stack is empty
        if(q1.empty())
            return -1;

        return q1.front();
    }
    int size()
    {
        return curr_size;
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(100);
    s.push(200);
    s.push(250);
    cout<<"current size of stack: "<<s.size()<<endl;
    cout<<"top element of stack: "<<s.top()<<endl;
    s.pop();
    cout<<"top element of stack: "<<s.top()<<endl;
    cout<<"current size of stack: "<<s.size()<<endl;

    return 0;
}
