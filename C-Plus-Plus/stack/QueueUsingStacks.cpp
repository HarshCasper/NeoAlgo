/*
This method makes sure that oldest entered element is always at the top of stack 1, so that deQueue operation just pops from stack1.
To put the element at top of stack1, stack2 is used. It makes enqueue operation costly in comparison to dequeue
*/

#include <bits/stdc++.h>
using namespace std;

struct Queue {
    stack<int> s1, s2;

    void enQueue(int x)
    {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push item into s1
        s1.push(x);

        // Push everything back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // Dequeue an item from the queue
    int deQueue()
    {
        // if first stack is empty
        if (s1.empty()) {
            cout << "Queue is Empty Now";
            exit(0);
        }

        // Return top of s1
        int x = s1.top();
        s1.pop();
        return x;
    }
};

// Driver code
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
    Queue q;
    for(int key:keys){
        q.enQueue(key);
    }
    cout << "Elements after Queue Implementation using Stack"<<endl;
    for (int i = 0; i <= keys.size(); i++) {
        cout << q.deQueue() << '\n';
    }

    return 0;
}

/*
Sample Input : n = 5
               Enter Elements
               67
               324
               43
               10
               90
Sample Output : Elements after Queue Implementation using Stack
               67
               324
               43
               10
               90
Time Complexity: O(n) for enqueue operation
                 O(1) for dequeue operation
*/