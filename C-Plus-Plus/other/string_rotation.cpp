/*
String Rotation
---------------

Problem Statement:
Rotate a given string in specified direction by specified magnitude.
After each rotation make a note of the first character of the rotated String, After all rotation are performed the 
accumulated first character as noted previously will form another string, say FIRSTCHARSTRING.
Check If FIRSTCHARSTRING is an Anagram of any substring of the Original string.
If yes print "YES" otherwise "NO".
Input
The first line contains the original string s. The second line contains a single integer q. The ith of the next q 
lines contains character d[i] denoting direction and integer r[i] denoting the magnitude.
*/

#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// performing left shift operation
string shiftLeft(string s, int c) 
{
    return s.substr(c) + s.substr(0, c);
}

// performing right shift operation
string shiftRight(string s, int c) 
{
    return s.substr(c + 1) + s.substr(0, c + 1);
}

// DRIVER FUNCTION
int main()
{
    char str[200], direction;
    int queries, amount;
    // first characters after performing each query is concatenated
    string firstchar = ""; 
    // getting the input string
    cin >> str;            
    cin >> queries;
    for (int query_num = 0; query_num < queries; query_num++)
    {
        // getting the direction and amount
        cin >> direction >> amount; 
        // if direction is left, perform left shift
        if (direction == 'L')       
        {
            firstchar += shiftLeft(str, amount)[0];
        }
        // if direction is right, perform right shift
        else if (direction == 'R') 
        {
            firstchar += shiftRight(str, amount)[0];
        }
    }
    map<char, int> mp1, mp2;
    for (auto &i : firstchar)
        // storing occurrence of characters in firstchar in map
        mp1[i]++; 
    unsigned i = 0, d = firstchar.size();
    // check if the size id greater than that of original string
    if (d > (int)strlen(str)) 
    {
        cout << "NO";
        return 0;
    }
    for (i = 0; i < d; i++)
        // storing occurrence of characters in str in map
        mp2[str[i]]++; 
    for (; i < (int)strlen(str); i++)
    {
        mp2[str[i]]++;
        if (mp2[str[i - d]] == 1)
        {
            mp2.erase(mp2.find(str[i - d]));
        }
        else
            mp2[str[i - d]]--;
        // condition to check whether firstchar is an anagram of str
        if (mp1 == mp2) 
        {
            cout << "YES";
            return 0;
        }
    }
    // if firstchar is not an anagram of str, print NO
    cout << "NO"; 
    return 0;
}
/*
For ex:
Example1:
Input:
career
3
L 2
R 3
L 2

Output:
NO

Example 2:
Input:
carrace
2
L 3
R 3
YES
*/