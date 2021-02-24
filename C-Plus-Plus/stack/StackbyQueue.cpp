/*
The idea is to implement queue's enqueue operation such that last entered element always ends up at the queue's front.
To achieve this we need an additional queue.
1. To push item into the stack, first move all elements from first queue to second queue, then enqueue the new item into 
first queue and finally move all elements back into first queue. This ensures that new item lies in front of queue and 
hence would be the first one to removed.
2. To pop an item from stack, return the front item from first queue
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;

// Implement stack using two queues
class Stack
{
    queue<int> q1, q2;

public:
    // Insert an item into the stack
    void push(int data)
    {
        // Move all elements from the first queue to the second queue
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Push the given item into the first queue
        q1.push(data);

        // Move all elements back to the first queue from the second queue
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    // Remove the top item from the stack
    int pop()
    {
        // if the first queue is empty
        if (q1.empty()) {
            cout << "Underflow!!";
            exit(0);
        }

        // return the front item from the first queue
        int front = q1.front();
        q1.pop();

        return front;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> keys(n);
    cout << "Enter Elements" << endl;
    for(vector<int>::iterator itr=keys.begin();itr!=keys.end();++itr)
        {
             cin >> *itr;
        }
    // insert the above keys into the stack
    Stack s;
    for (int key: keys) {
        s.push(key);
    }
    cout << "Elements after Stack Implementation using Queue"<<endl;
    for (int i = 0; i <= keys.size(); i++) {
        cout << s.pop() << '\n';
    }

    return 0;
}

/*
Sample Input: n = 5
              Enter Elements              
              56
              89
              234
              21
              10
Sample Output : Elements after Stack Implementation using Queue
                10
                21
                234
                89
                56
                Underflow !!            
TIme Complexity: for push function it is O(n)
                 for pop function it is O(1)
*/