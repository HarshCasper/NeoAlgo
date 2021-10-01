/*
Find total number of Squares in a N*N cheesboard.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long squaresInChessBoard(long long n)
    {
        return (n * (n + 1) * (2 * n + 1)) / 6;
    }
};

int main()
{
    long long num;
    cout << "Enter the number : " << endl;
    cin >> num;

    Solution obj;
    cout << "The square is : " << endl;
    cout << obj.squaresInChessBoard(num) << endl;
}

/*
Time complexity : O(N)
Space complexity : O(1)
*/

/*
Input :
Enter the number :  1
Output :
The square is : 1
*/

