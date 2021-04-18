/* Reversing the first K elements of a Queue */

#include<bits/stdc++.h>
using namespace std;

/* Function for Reversing the first K elements of a Queue */
void solve()
{
    /* Input n = size of array */
    int n;
    cin >> n;

    int a[n];
    
    /* Declear the empty queue */
    queue<int> q;

    /* Input values in an array and
       push array element into the queue */
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        q.push(a[i]);
    }

    /* Input k*/
    int k;
    cin >> k;

    /* Declear a empty Stack */
    stack<int> s;

    /* Push k element in the Stack
       from queue */
    for (int i = 0; i < k; ++i)
    {
         s.push(q.front());
         q.pop();
    } 

    /* Enqueue the contents of stack
       at the back of the queue */
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
 
    /* Remove the remaining elements and
       enqueue them at the end of the queue */
    for (int i = 0; i < q.size() - k; i++)
    {
        q.push(q.front());
        q.pop();
    }

    /* Print the queue */
    cout << "After Reversing : ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }    
}

int main()
{
    solve();
    return 0;
}

/*
Test cases :
    
    Input 1 :
        
        10
        10 20 30 40 50 60 70 80 90 100
        5

    Output 1 :

        After Reversing : 50 40 30 20 10 60 70 80 90 100 

    Input 2 :

        6
        1 2 3 4 5 6
        4
    
    Output 2 :
    
        After Reversing : 4 3 2 1 5 6 
    
    Time complexity: O(n)
    Space Complexity: O(n)
*/
