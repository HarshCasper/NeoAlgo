/*Problem Statement:
You are actually very busy man. You have a big schedule of activities. 
Your aim is to do as much as activities as possible.
It is given that, if you go to date with crush, 
you cannot participate in the coding contest and you can’t watch the movie. 
Also if you play DotA, you can’t study for the exam. 
If you study for the exam you can’t sleep peacefully. 
The maximum number of activities that you can do for this schedule is 3. */

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
    int t, n, s, e;
    cin >> t;
    vector<pair<int, int> > v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        v.push_back(make_pair(s, e));
    }

    sort(v.begin(), v.end(), compare);
    int res = 1;
    int fin = v[0].second;
    for (int i = 1; i < n; i++)
    {
        /*If the start time ig greater or equal to the finsh time 
        of the previous activity time */
        if (v[i].first >= fin)
        {
            fin += v[i].second;
            res++;
        }
    }

    cout << res << endl;
    v.clear();
    return 0;
}
/*Example:
1)Input:
3
3 9
2 8
6 9
Output:
1
2)Input:
4
1 7
5 8
7 8
1 8
Output:
2
Time Complexity: O(nlogn)
Space Complexity: O(n) */
