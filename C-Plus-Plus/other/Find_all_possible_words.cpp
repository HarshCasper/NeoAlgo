/*
Find all possible words of length k that can be formed from given n letters

Suppose we want words of length 2 using letters a,b,c
ten possible words are aa,ab,ac,ba,bb,bc,ca,cb,cc
*/

#include <bits/stdc++.h>
#include <string>
using namespace std;
void possibleStrings(char characters[], int n, int k, string s){
    if (k == 0){
    cout << s << endl;
        return;
    }
    
    for (int i = 0; i < n; i++){
        string s1 = s + characters[i];
        possibleStrings(characters, n, k - 1, s1);
    }
    return;
}

//Driver function
int main(){
    int n;
    cout<<"Enter number of letters:";
    cin >> n;
    char characters[n];
    cout<<"Enter letters:";
    for (int i = 0; i < n; i++){
        cin >> characters[i];
    }
    int k;
    cout<<"Enter the length of word to be formed:";
    cin >> k;
    possibleStrings(characters, n, k, "");
}
/*
Sample Input

Enter number of letters:
4 
Enter letters:
a b c d
Enter the length of word to be formed:
2

Sample Output

aa
ab
ac
ad
ba
bb
bc
bd
ca
cb
cc
cd
da
db
dc
dd

*/