#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//we are supposed to perform at most n deletions from the
//original string str as well as from the reversed string str to
//make both strings equal.therefore if string is K palindrome
//it will satisfy 2×n <= 2×k .
// Function to check if the given string is k–palindrome or not
int isKPalindrome(string X, int m, string Y, int n)
{
     // if either string is empty
    if (m == 0 || n == 0) {
        return n + m;
    }

    // ignore the last characters of both strings if they are the same
    // and do for the remaining characters
    if (X[m - 1] == Y[n - 1]) {
        return isKPalindrome(X, m - 1, Y, n - 1);
    }
    // if the last character of both strings is different

    // remove the last character from the first string and do
    int x = isKPalindrome(X, m - 1, Y, n);

    // remove the last character from the second string and do
    int y = isKPalindrome(X, m, Y, n - 1);

    // return one more than the minimum of the above two operations
    return 1 + min(x, y);
}
int main()
{
    string str;
    int K;
    cout<<"enter the string: \n";
    cin>>str;
    cout<<"enter K: \n";
    cin>>K;
    // get reverse of str
    string rev = str;
    reverse(rev.begin(), rev.end());

    if (isKPalindrome(str, str.length(), rev, str.length()) <= 2*K) {
        cout << "The string is k palindrome";
    }
    else {
        cout << "The string is not a k palindrome";
    }

    return 0;
}
