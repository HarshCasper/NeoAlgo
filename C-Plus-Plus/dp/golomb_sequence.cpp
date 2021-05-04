/* C++ program to print the n'th term in the Golomb sequence
Golomb sequence is a non-decreasing integer sequence where n'th
term is  equal to the number of times n appears in the sequence */

#include <bits/stdc++.h>
using namespace std;

int golomb_sequence(int n)
{
    // Create a dp array, with value initialized as 0.
    int dp[n + 1];

    dp[1] = 1;

    // Identify the previous term 'prev' and go prev terms behind and find a number.
    // Now assign the current element with an incremented value of that element.
    for (int i = 2; i <= n; i++)
    {
        int prev = dp[i - 1];
        int back_index = i - dp[prev];
        dp[i] = 1 + dp[back_index];
    }
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter the value of n?, where you need the n'th number in the golomb sequence.";
    cin >> n;
    if (n <= 0)
    {
        cout << "The given value of n is invalid.";
        return 0;
    }
    int res = golomb_sequence(n);
    cout << "The " << n << "'th term in the golomb sequence is " << res;
    return 0;
}

/*
Time Complexity: O(n), where 'n' is the given number
Space Complexity: O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

Enter the value of n?, where you need the n'th number in the golomb sequence. 5
The 5'th term in the golomb sequence is 3.

SAMPLE 2

Enter the value of n?, where you need the n'th number in the golomb sequence. 867
The 867'th term in the golomb sequence is 79.
*/
