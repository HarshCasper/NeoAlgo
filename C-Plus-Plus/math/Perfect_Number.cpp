/*
Perfect number is a positive integer which is equal to the sum of its proper positive divisors.
For example: 6 is the first perfect number
Proper divisors of 6 are 1, 2, 3
Sum of its proper divisors = 1 + 2 + 3 = 6.
Hence 6 is a perfect number.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, sum = 0;
    cout<<"Enter a number to check whether it is a perfect number or not: ";
    cin >> n;
    for (i = 1; i < n; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    if (sum == n)
        cout << sum << " is a perfect number." << endl;
    else
        cout << n << " is not a perfect number." << endl;
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)

sample 1:
Input: Enter a number to check whether it is a perfect number or not: 6
Output: 6 is a perfect number.
sample 2:
Input: Enter a number to check whether it is a perfect number or not: 7
output: 7 is not a perfect number.
*/ 