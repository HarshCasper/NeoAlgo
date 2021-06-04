// CPP program to implement Queue using Stacks

//We can implement a queue using stacks :-
//1) Enqueue the elements in stack_1.
//2) We need to pop all the elements from stack_1 and keep adding them in the stack2. So, the bottom element of the stack1 will be the top element of stack_2. Now if we pop an
//   element from the stack_2, we popped the bottom element of stack_1. So, that’s our dequeue operation. After the operation is done, we should put the elements back in the 
//   stack_1 again.

#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> st1, st2;
    public:
    // Enqueue item to the queue
    void enq(int x)
    {
        // Push into the first stack
        st1.push(x);
    }

    // Dequeue an item from the queue
    int deq()
    {
        // if both stacks are empty then exit
        if (st1.empty() && st2.empty())
        {
            cout << "Queue is empty";
            exit(0);
        }
        // if st2 is empty, move elements from st1 to st2
        if (st2.empty())
        {
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        // return the top item from st2
        int x = st2.top();
        st2.pop();
        return x;
    }
};

// main function
int main()
{
    Queue q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        q.enq(num);
    }
    for (int i = 0; i < n; i++)
    {
        cout << q.deq() << " ";
    }
    return 0;
}

/*
Sample Input 1 : 
3
1 2 3

Sample Output : 
1 2 3

Explanation : 
When we input elements 1,2,3 then they will be stored as: 3 2 1 where 3 is top element of stack. and we know that in queue we delete from opposite side. Therefore first 1 is deleted
and displayed then 2 and then 3. therefore these two stacks work together as a single queue.

Time Complexity  : O(n^2) since dequeue take O(n) and its being called under for loop so total complexity will be O(n*n).
Space Complexity : O(2*n)  since we are using two stacks of same size so there is 2*n space required for n elements.
*/
