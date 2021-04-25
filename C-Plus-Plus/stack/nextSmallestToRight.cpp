/*
Next Smallest Element to the right using stacks in C++ 
ALGORITHM:
* Use stack to find out the next smallest element of each element in the array
*/
#include <bits/stdc++.h>
using namespace std;
void nextSmallestElement(int a[], int n)
{
    stack<int> s;
    s.push(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (s.empty())
        {
            s.push(a[i]);
            continue;
        }
        while (s.empty() != true && s.top() > a[i])
        {
            cout << a[i] << " ";
            s.pop();
        }
        s.push(a[i]);
    }
    while (s.empty() != true)
    {
        cout << -1 << " ";
        s.pop();
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    nextSmallestElement(a, n);
}
/*
Time Complexity:O(n^2)
INPUT:
5
1 3 4 2 1
OUTPUT:
2 2 1 -1 -1
*/
