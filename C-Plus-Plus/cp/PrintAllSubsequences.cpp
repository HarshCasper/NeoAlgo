// This program prints all the possible subsequences for a given string.
#include <bits/stdc++.h>
using namespace std;

void printSubsequences(string str, string curr="", int idx = 0){
    //Base case
    if(idx == str.size()){ 
        cout << curr << endl;
        return; 
    }
    //Recursive call when character does not get added to curr
    printSubsequences(str, curr, idx + 1); 
    //Recursive call when character gets added to curr
    printSubsequences(str, curr + str[idx], idx + 1); 
}

int main() {
    string s;
    cout << "Enter the string";
    cin >> s;
    printSubsequences(s, "", 0);
    return 0;
}

/*
Time complexity : O(n)
Space complexity : O(1)
*/

/*Example:
Input : s = "abcd"
Output :

d
c
cd
b
bd
bc
bcd
a
ad
ac
acd
ab
abd
abc
abcd */
