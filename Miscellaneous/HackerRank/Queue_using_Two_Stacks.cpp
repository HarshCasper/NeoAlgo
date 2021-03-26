/*
Desciption : 
   In this challenge, you must first implement a queue using two stacks.
   Then process 3 queries, where each query is one of the following types:

    1 x: Enqueue element  into the end of the queue.
    2: Dequeue the element at the front of the queue.
   3: Print the element at the front of the queue.
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

void shift(stack<int> &stack_1, stack<int> &stack_2) //for shifting the element from one stack to another
{
    while(!stack_1.empty())
    {
        stack_2.push(stack_1.top());
        stack_1.pop();
    }
}


int main() {
    
    stack<int> stack_1 , stack_2;
    int query,choice,element;
    cin>>query;

    while(query--)
    {
        cin>>choice;
        if(choice == 1) //we have to enqueue
        {
            cin>>element;
            stack_1.push(element);
        }
        if(choice == 2)
        {
            if(stack_2.empty())
            {
                shift(stack_1,stack_2);
            }
            stack_2.pop();
        }
        if(choice == 3)
        {
            if(stack_2.empty())
            {
                shift(stack_1,stack_2);
            }
            cout<<stack_2.top()<<endl;
        }
    }
    return 0;
}

/* 
 Time complexity : O(n2)
 Space complexity : O(n2)
*/

/*
  Test Case: 
    Input :
          10
          1 42
          2
          1 14
          3
          1 28
          3
          1 60
          1 78
          2
          2

    Output :
         14
         14
*/

