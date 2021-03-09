/*Next greatest element to the right of each element in the array
  ALGORITHM
 *Using a stack to find out the next greatest element to the right
 *Start the scanning of the array from the right 
 *Declare an array and a stack
 *If the stack is empty, then no element to the right is greater than the present element
 *If the stack is not empty but the element present at the top of the stack is not greater than the current element then-
 * pop the stack till  the stack is not empty or the top element of stack is greater than the current element
 *If the stack is not empty and the element at the top of the stack is greater than the current element then push the topmost element to the stack
*/
#include <bits/stdc++.h>
using namespace std;
void nextLargest(int a[], int n)
{
    vector<int> v;
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty() == true)
            v.push_back(-1);
        else if (s.empty() != true && s.top() > a[i])
            v.push_back(s.top());
        else if (s.empty() != true && s.top() <= a[i])
        {
            while (s.top() <= a[i] && s.empty() != true)
            {
                s.pop();
            }

            if (s.empty() == true)
                v.push_back(-1);
            if (s.top() > a[i] && s.empty() != true)
                v.push_back(s.top());
        }

        s.push(a[i]);
    }
    //reversing the array containing the next greatest element to the right
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    nextLargest(a, n);
}
/*
INPUT:
n=4
a[n]=1 3 2 4
OUTPUT:
3 4 4 -1
Code Complexity: O(n^2)
*/
