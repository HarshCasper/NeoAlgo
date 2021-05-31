/*
Next Smallest Element to the right using stacks in C++ 
ALGORITHM:
* Use stack to find out the next smallest element of each element in the array
*/
#include <bits/stdc++.h>
using namespace std;
void nextSmallestToRight(int a[],int n)
{
    stack<int> s;
    vector<int> v;
    for(int i=n-1;i>=0;i--)
    {
        if(s.empty())
        v.push_back(-1);
        else if(s.empty()!=true && s.top()<a[i])
        v.push_back(s.top());
        else if(s.empty()!=true && s.top()>a[i])
        {
            while(s.empty()!=true && s.top()>a[i])
            s.pop();

            if(s.empty())
            v.push_back(-1);
            else if(s.top()>a[i])
            v.push_back(s.top());
        }
        s.push(a[i]);
    }
    reverse(v.begin(),v.end());

    for(int i=0;i<n;i++)
    cout<<v[i]<<" ";
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    nextSmallestToRight(a, n);
}
/*
Time Complexity:O(n^2)
INPUT:
5
1 3 4 2 1
OUTPUT:
2 2 1 -1 -1
*/
