/*
Next Greatest Element to the left using stacks in C++ 
ALGORITHM:
 *Declare an array and a stack
 *If the stack is empty, then no element to the left is greater than the present element
 *If the stack is not empty but the element present at the top of the stack is not greater than the current element then-
 *pop the stack till  the stack is not empty or the top element of stack is greater than the current element
 *If the stack is not empty and the element at the top of the stack is greater than the current element then-
  push the topmost element to the stack
*/

#include<bits/stdc++.h>
using namespace std;

void nextGreatestToLeft(int a[],int n)
{
    stack <int> s;
    vector <int> v;
    for(int i = 0; i < n; i++)
    {
        if(s.empty() == true)
        v.push_back(-1);
        else if(s.empty() != true && s.top() > a[i])
        v.push_back(s.top());
        else if(s.empty() != true && s.top() <= a[i])
        {
            while(s.empty() != true && s.top() <= a[i])
            {
                s.pop();
            }
            if(s.empty() == true)
            v.push_back(-1);
            else if(s.top() > a[i])
            v.push_back(s.top());
        }
        s.push(a[i]);
    }
    for(int i = 0; i < n; i++)
    cout << v[i] << " ";
}

//Driver Function
int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++)
    cin >> a[i];
    cout << "The next greatest element to the left of each element: \n";
    nextGreatestToLeft(a,n);
}

/*
INPUT:
Enter the number of elements: 4
Enter the elements: 5 2 4 6

OUTPUT:
The next greatest element to the left of each element: 
-1 5 5 -1 

Time Complexity: O(n^2)
Space complexity: O(n)
*/
