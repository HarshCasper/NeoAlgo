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
#include<algorithm>
#include<map>
using namespace std;
string shiftLeft(string s,int c) // performing left shift operation
{
   return s.substr(c) + s.substr(0,c);
}
string shiftRight(string s,int c) // performing right shift operation
{
    return s.substr(c+1) + s.substr(0,c+1);
}

// DRIVER FUNCTION
int main() {
    char str[200],direction;
    int queries,amount;
    string firstchar=""; // first characters after performing each query is concatenated
    cin>>str; // getting the input string
    cin>>queries;
    for(int query_num=0;query_num<queries;query_num++)
    {
        cin>>direction>>amount; // getting the direction and amount 
        if(direction=='L') // if direction is left, perform left shift
        {
                firstchar+=shiftLeft(str, amount)[0];
        }
        else if(direction=='R') // if direction is right, perform right shift
        {
                firstchar+=shiftRight(str, amount)[0];
        }
    }
    map<char,int> mp1,mp2;
    for(auto &i:firstchar) mp1[i]++;  // storing occurrence of characters in firstchar in map
    unsigned i=0,d=firstchar.size();
    if(d>(int)strlen(str)) // check if the size id greater than that of original string
    {
        cout<<"NO";
        return 0;
    }
    for(i=0;i<d;i++) mp2[str[i]]++; // storing occurrence of characters in str in map
    for(;i<(int)strlen(str);i++)
    {
        mp2[str[i]]++;
        if(mp2[str[i-d]]==1)
        {
            mp2.erase(mp2.find(str[i-d]));
        }
        else mp2[str[i-d]]--;
        if(mp1==mp2) // condition to check whether firstchar is an anagram of str
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO"; // if firstchar is not an anagram of str, print NO
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