/*
Problem Statement:
Given 2 large numbers, represented as strings.
Find the sum of those strings and print the answer in string format.
*/

#include <bits/stdc++.h>
using namespace std;

// trim function is used to remove the zero's at the front.
string trim(string x)
{
    if (x == "0")
        return x;
    while (x[0] == '0')
    {
        x.erase(0, 1);
    }
    return x;
}

// Sum function returns a string which is sum of two input strings
string Sum(string x, string y)
{
    int n = x.size(), m = y.size();
    // string res stores the result
    string res;
    // carry variable is used to take care of carry while adding two numbers.
    // variable i is pointing to the end of string x and j is pointing to the end of string y.
    int i = n - 1, j = m - 1, carry = 0, k = max(n, m) - 1;
    while (i >= 0 and j >= 0)
    {
        int value = x[i] + y[j] - 96;
        value += carry;
        char temp = 48 + (value % 10);
        res += temp;
        carry = value / 10;
        i--;
        j--;
        k--;
    }
    while (i >= 0)
    {
        int value = x[i] - 48 + carry;
        char temp = 48 + (value % 10);
        res += temp;
        carry = value / 10;
        i--;
        k--;
    }
    while (j >= 0)
    {
        int value = y[j] - 48 + carry;
        char temp = 48 + (value % 10);
        res += temp;
        carry = value / 10;
        j--;
        k--;
    }
    res = carry == 0 ? res : res + to_string(carry);
    reverse(res.begin(), res.end());
    return trim(res);
}

int main()
{
    string input1, input2;
    cout << "Enter the strings : \n";
    cin >> input1 >> input2;
    string answer = Sum(input1, input2);
    cout << "Sum of the given strings : " << answer << endl;
}

/*
Input:
Enter the strings : 
329549237582345455325
329857327582358923593245
Output:
Sum of the given strings : 330186876819941269048570

Time Complexity  : O(max(n,m))
Space Complexity : O(max(n,m))

*/

