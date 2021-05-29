/*
Description : 
            Given a number. Find and its reverse that number raised to the power of its own reverse.
            As answers can be very large, print the result modulo 1000000007.
 
*/

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

class Solution
{
public:
    //function to find the power with respect to mod
    long long modular_func(long long n, long long R)
    {
        if (n == 0)
        {
            return 0;
        }
        if (R == 0)
        {
            return 1;
        }

        long long y;
        // If we find R is even
        if (R % 2 == 0)
        {
            y = modular_func(n, R / 2);
            y = (y * y) % mod;
        }

        // If we find R is odd
        else
        {
            y = n % mod;
            y = (y * modular_func(n, R - 1) % mod) % mod;
        }
        // finally return the answer
        return ((y + mod) % mod);
    }

    long long power(int N, int R)
    {
        //using recursion
        return modular_func(N, R) % mod;
    }
};

//fucntion is used to reverse the number
long long rev(long long n)
{
    long long rev_num = 0;
    while (n > 0)
    {
        rev_num = rev_num * 10 + n % 10;
        n = n / 10;
    }
    return rev_num;
}

int main()
{
    // user input number
    //using long long variables and function to avoid integer overflow
    long long num;
    cout << "Enter the number : " << endl;
    cin >> num;
    // R is used to hold reverse of the original number
    long long R = 0;
    R = rev(num);

    Solution obj;
    // calling function
    long long ans = obj.power(num, R);
    cout << "Number raised to the power of its own reverse is : " << endl;
    cout << ans << endl;
}

/*
Time complexity : O(log N)
Space complexity : O(log N)
*/

/*
Test Case :
 Input ;
 Enter the number : 
 12

 Output ;
 Number raised to the power of its own reverse is : 
 864354781

*/

