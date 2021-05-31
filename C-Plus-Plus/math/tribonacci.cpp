/*
CPP program to find the n'th number in the tribonacci series
Tribonacci series is a generalization of the Fibonacci sequence, in which the current term
is the sum of the previous three terms
*/

#include<bits/stdc++.h>
using namespace std;

long int find_tribonacci(int n)
{
    long int dp[n];
    memset(dp, 0, sizeof(dp));
    dp[2] = 1;

    for(int i = 3;i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    return dp[n-1];
}


int main()
{
    int n, ans;
    cout<<"Enter the value of n?, where you need the n'th number in the tribonacci sequence. ";
    cin >> n;
    ans = find_tribonacci(n);
    cout<<"The "<<n<<"'th term in the tribonacci series is "<<ans;
}


/*
Time Complexity - O(n)
Space Complexity - O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE I

Enter the value of n?, where you need the n'th number in the tribonacci sequence. 12
The 12'th term in the tribonacci series is 149.

SAMPLE II

Enter the value of n?, where you need the n'th number in the tribonacci sequence. 23
The 23'th term in the tribonacci series is 121415
*/
