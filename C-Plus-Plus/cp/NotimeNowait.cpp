/* 
Only x hours are left for the March Long Challenge and Chef is only left with the last problem unsolved. However, he is sure that he cannot solve the problem in the remaining time. From experience, he figures out that he needs exactly H hours to solve the problem.

Now Chef finally decides to use his special power which he has gained through years of intense yoga. He can travel back in time when he concentrates. Specifically, his power allows him to travel to N different time zones, which are T1,T2,…,TN hours respectively behind his current time.

Find out whether Chef can use one of the available time zones to solve the problem and submit it before the contest ends.

Input
The first line of the input contains three space-separated integers N, H and x.
The second line contains N space-separated integers T1,T2,…,TN.
Output
Print a single line containing the string "YES" if Chef can solve the problem on time or "NO" if he cannot.

You may print each character of each string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤N≤100
1≤x<H≤100
1≤Ti≤100 for each valid i
*/

/* 
sample input
2 5 3
1 2
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{

    int N, H, X, T, count = 0;

    cin >> N >> H >> X;
    for (int i = 0; i < N; i++)
    {
        cin >> T;
        if (X + T == H)
        {
            cout << "YES";
            count++;
            break;
        }
    }
    if (count == 0)
    {
        cout << "NO";
    }

    return 0;
}

/* 
sample output
YES


***** time complexity of this program is O(n)
*/