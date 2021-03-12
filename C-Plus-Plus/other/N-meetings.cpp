#include <bits/stdc++.h>
using namespace std;

/*
We are given n meetings which consists of start and end time.
Select the maximum number of meetings that can be carried out in a single room, 
assuming that the room can be used only for one meeting at a time.

Input Format
The first line consists of an integer n, the number of meetings. 
Then the first next n lines contains start times and then the next n lines contains the end times

Output Format
For each test case find the maximum number of meetings that we can do.

Sample Input
6
1 3 0 5 8 5
2 4 6 7 9 9

Sample Output
4

*/

struct meeting
{
    int start;
    int end;
    int pos;
}; // structure to access the start, end time and position

static bool comparator(struct meeting m1, struct meeting m2)
{ // Compare function for sorting
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.pos < m2.pos)
        return true;
    return false;
}

int maxMeetings(int start[], int end[], int n)
{
    struct meeting meet[n];
    for (int i = 0; i < n; i++)
    {
        meet[i].start = start[i];
        meet[i].end = end[i];
        meet[i].pos = i + 1;
    }
    sort(meet, meet + n, comparator);
    vector<int> answer;

    int limit = meet[0].end;
    answer.push_back(meet[0].pos);

    for (int i = 1; i < n; i++)
    {
        if (meet[i].start > limit)
        { // We take the immediate next greater meeting
            answer.push_back(meet[i].pos);
        }
    }
    return answer.size();
}

int main()
{
    int n;
    cin >> n;
    int start[n], end[n];
    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> end[i];
    }
    int ans = maxMeetings(start, end, n);
    cout << ans;
    cout << endl;
    return 0;
}