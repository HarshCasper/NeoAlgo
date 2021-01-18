#include <iostream>
#include <list>
using namespace std;

class Queue
{
    int cs;

    list<int> l;

public:
    Queue() { cs = 0; }

    bool empty() { return cs == 0; }

    void push(int data)
    {
        l.push_back(data); // push back at the tail
        cs++;
    }

    void pop()
    {
        if (!empty())
        {
            cs--;
            l.pop_front(); // remove the element from the head of the queue
        }
    }

    int front()
    {

        return l.front(); // element present at the front of the list
    }
};

int main()
{
    Queue q;

    for (int i = 0; i < 10; i++)
    {
        q.push(i);
    }

    // remove elements while list is not empty
    while (!q.empty())
    {
        cout << q.front() << "  ";
        q.pop();
    }

    return 0;
}