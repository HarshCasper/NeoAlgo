// Given a string , remove spaces from it and then return new string

/*
By using getline function in C++, we can remove spaces from a string and get a new string.
*/
#include <bits/stdc++.h>
using namespace std;
string new_string(string s)
{

    stringstream s2(s);
    string tem;

    // Making the string empty
    s = "";

    // Running loop till end of stream
    // and getting every word
    while (getline(s2, tem, ' ')) {
       s += tem;
    }
    return s;
}

int main()
{
    string s;
    getline(cin , s);
    cout << new_string(s) << endl;
}
/*

Standard Input and Output

Input : I am a Open Source Contributor in GSSoC'21
Output : IamaOpenSourceContributorinGSSoC'21

Time Complexity : O(N) // String size
Space Complexity : O(N) // an intermediate string

*/
