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
    int n, s, e;
    vector<pair<int, int> > v;
    cout<<"Enter total number of activities: "<<endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter starting and finishing time of each activity: "<<endl;
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

    cout <<"the maximum number of activities you can do are: "<< res << endl;
    return 0;
}
/*Example:
1)Input:
Enter total number of activities:
3
Enter starting and finishing time of each activity:
3 9
Enter starting and finishing time of each activity:
2 8
Enter starting and finishing time of each activity:
6 9
Output:
the maximum number of activities you can do are: 1
Time Complexity: O(nlogn)
Space Complexity: O(n) 
*/

