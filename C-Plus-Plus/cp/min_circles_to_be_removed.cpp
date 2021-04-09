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
    int n, center, radius;
    cout<<"Enter total number of circles: "<<endl;
    cin >> n;
    vector<pair<int, int> > v;

    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the center and the radius respectively: "<<endl;
        cin >> center >> radius;
        v.push_back(make_pair(center, radius));
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

    cout <<"Minimum circles that are to be removed: "<< (n - ans) <<endl;
    return 0;
}
/*Example:
1)Input:
Enter total number of circles:
4
Enter the center and the radius respectively:
1 1
Enter the center and the radius respectively:
2 1
Enter the center and the radius respectively:
3 1
Enter the center and the radius respectively:
4 1
Output:
Minimum circles that are to be removed: 2
Time Complexity: O(nlogn)
Space Complexity: O(nlogn) 
*/

