/*Code for maximum number formed from the given array of two digit numbers
Given: An array of two digit numbers
Objective: Form the maximum number
 */

#include <bits/stdc++.h>
using namespace std;
int myCompare(string X, string Y)
{
    string XY = X.append(Y);
    string YX = Y.append(X);
    return XY.compare(YX) > 0 ? 1 : 0;
}
int printLargest(vector<string> str)
{
    sort(str.begin(), str.end(), myCompare);
    for (int i = 0; i < str.size(); i++)
        cout << str[i];
}
int main()
{
    vector<string> str;
    long long int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        str.push_back(s);
    }
    printLargest(str);
}
/* 
Time Complexity:O(n)
Example:
Input:
5
12 34 22 45 20
Output:
4534222012
*/
