/*
Given an array find the next smallest element to the right
ALGORITHM:
*Initialise a stack and array
*Traverse the given array from the left
*If the stack is empty, then push -1 to array
*If the stack is not empty and topmost element is smaller than th element then push topmost element to array
*If not then pop elements from the stack till it is empty or topmost element is smaller
*/

#include<bits/stdc++.h>
using namespace std;

void nextSmallestToLeft (int a[],int n)
{
    stack <int> s;
    vector <int> v;

    for(int i = 0 ; i < n ; i++)
    {
        if (s.empty())
        v.push_back(-1);
        else if (s.empty() != true && s.top() < a[i])
        v.push_back(s.top());
        else if (s.empty() != true && s.top() > a[i])
        {
            while (s.empty() != true && s.top() > a[i])
            {
                s.pop();
            }
            if (s.empty())
            v.push_back (-1);
            else if (s.top() < a[i])
            v.push_back(s.top());            
        }
        s.push(a[i]);
    }

    for(int i = 0 ; i < n ; i++)
    cout << v[i] << " ";
}

//Driver function
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements:\n";
    for(int i = 0 ; i < n ; i++)
    cin >> a[i];
    nextSmallestToLeft(a,n);
}

/*
Time Complexity: O(n^2)

Space Complexity: O(n)

Input:

Enter number of elements: 4
Enter the elements:
1 2 4 5 

Output:

-1 1 2 4
*/
