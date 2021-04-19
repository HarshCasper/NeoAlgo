/*
Given a non-empty string containing
an out-of-order English representa-
tion of digits 0-9,output the digits
in ascending order.
Note:
Input contains only lowercase English
letters.
Input is guaranteed to be valid and 
can be transformed to its original 
digits.That means invalid inputs such
as "abc" or "zeroe" are not permitted.
*/

#include <bits/stdc++.h>
using namespace std;

string EnglishToDigit(string English)
{
    long long int L, i, Z, Max;
    string Temp, Digit;
    vector<pair<string, int> > M;
    L = English.length();
    int count[26] = { 0 };
    for (i = 0; i < L; i++) {
        count[English[i] - 'a']++;
    }
    M.push_back({ "six", 6 });
    M.push_back({ "zero", 0 });
    M.push_back({ "seven", 7 });
    M.push_back({ "eight", 8 });
    M.push_back({ "five", 5 });
    M.push_back({ "four", 4 });
    M.push_back({ "three", 3 });
    M.push_back({ "two", 2 });
    M.push_back({ "one", 1 });
    M.push_back({ "nine", 9 });
    for (auto it = M.begin(); it != M.end(); it++) {
        Max = INT_MAX;
        Temp = it->first;
        Z = Temp.length();
        for (i = 0; i < Z; i++) {
            if (count[Temp[i] - 'a'] < Max) {
                Max = count[Temp[i] - 'a'];
            }
        }
        for (i = 0; i < Max; i++) {
            Digit += ('0' + it->second);
        }
        for (i = 0; i < Z; i++) {
            count[Temp[i] - 'a'] -= Max;
        }
    }
    sort(Digit.begin(), Digit.end());
    return Digit;
}

int main()
{
    string English, Digit;
    cout << "Enter the String" << endl;
    cin >> English;
    Digit = EnglishToDigit(English);
    cout << "Coverted String" << endl;
    cout << Digit << endl;
    return 0;
}

/*
Time Complexity:O(N)
Space Complexity:O(1)
Where N is the length
of the string.

Sample I/O
Input:
Enter the String
owoztneoer
Output:
Coverted String
012
*/
