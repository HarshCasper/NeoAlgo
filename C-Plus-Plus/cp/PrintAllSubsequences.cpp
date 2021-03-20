// This program prints all the possible subsequences for a given string.
#include <bits/stdc++.h>
using namespace std;

void printSubsequences(string str, string curr="", int idx = 0){
    if(idx == str.size()){ //Base case
        cout << curr << endl;
        return; 
    }
    printSubsequences(str, curr, idx + 1); //Recursive call when character does not get added to curr
    printSubsequences(str, curr + str[idx], idx + 1); //Recursive call when character gets added to curr
}

int main() {
    string s;
    cout << "Enter the string";
    cin >> s;
    printSubsequences(s, "", 0);
    return 0;
}

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
