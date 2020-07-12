#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, half,a;
    cin >> n;
    half = n/2;
    vector<string> str(1000000,"");
    string s;
    for(int i = 0; i < n; i++){
        cin >> a >> s;
        if(i < half) str[a] += "- ";
        else str[a] += s + " ";
    }
    for(int i = 0; i < n; i++)cout << str[i];
    return 0;
}