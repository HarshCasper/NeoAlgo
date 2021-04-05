/*Problem Statement:
Given n Circles present in x-y plane such that all the circles have their centre aligned on the x-axis.
The task is to remove some of them, such that no two circles are intersecting. 
Find the minimum number of circles that need to be removed. */ 

#include <bits/stdc++.h>
using namespace std;

/* this function will help in sorting the circles on the 
basis of their radius */
bool compare(pair<int, int> a, pair<int, int> b)
{
    if ((a.first + a.second) == (b.first + b.second))
    {
        return (a.first - a.second) < (b.first - b.second);
    }
    else
    {
        return (a.first + a.second) < (b.first + b.second);
    }
}

int main()
{
    int ans = 1;
    int n, c, r;
    cin >> n;
    vector<pair<int, int> > v;

    for (int i = 0; i < n; i++)
    {
        cin >> c >> r;
        v.push_back(make_pair(c, r));
    }

    sort(v.begin(), v.end(), compare);

    int val = v[0].first + v[0].second;

    for (int i = 0; i < n - 1; i++)
    {
        if (val <= v[i + 1].first - v[i + 1].second)
        {
            ans++;
            val = v[i + 1].first + v[i + 1].second;
        }
    }

    cout << (n - ans) <<endl;
    return 0;
}
/*Example:
1)Input:
4
1 1
2 1
3 1
4 1
Output:
2
2)Input:
4
1 1 
4 1
5 2
7 1
Output:
1 
Time Complexity: O(nlogn)
Space Complexity: O(nlogn) */
