/*
C++ program to find the n-th element from Stern's Diatomic Series
Stern's diatomic series is the sequence which generates the integer sequence that arises
in the Calkin-Wilf tree. This sequence can be computed by the fusc function.
*/
#include <bits/stdc++.h>
using namespace std;

int sterns_diatomic_num(int n)
{
    if (n == 0)
        return 0;

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
            dp[i] = dp[i / 2];
        else
            dp[i] = dp[(i - 1) / 2] + dp[(i + 1) / 2];
    }

    return dp[n];
}

int main()
{
    int n;
    cout << "Enter the value of n(where you need the nth Stern's Diatomic number): ";
    cin >> n;
    if (n < 0)
    {
        cout << "Invalid Value of n !!!";
        return 0;
    }
    int res = sterns_diatomic_num(n);
    cout << "The " << n << "'th Stern's Diatomic is " << res;
    return 0;
}

/*
Time Complexity: O(n), where 'n' is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
Enter the value of n(where you need the nth Stern's Diatomic number): 258
The 258'th Stern's Diatomic is 8.

SAMPLE 2
Enter the value of n(where you need the nth Stern's Diatomic number): -98
Invalid Value of n !!!
*/
