/*Problem Statement:
Given an integer, the task is to convert it to a roman numeral.
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol Value
I 1
V 5
X 10
L 50
C 100
D 500
M 1000 */

#include <bits/stdc++.h>
using namespace std;

string IntegerToRoman(int num) {
    string ans = "";
    vector<pair<int, string>> values = {{1000, "M"}, {900, "CM"}, {500, "D"}, 
                                       {400, "CD"}, {100, "C"}, {90, "XC"}, 
                                       {50, "L"}, {40, "XL"}, {10, "X"}, 
                                       {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    vector<pair<int, string>>::iterator it; 
    it = values.begin(); //to iterate over the values
    while(num > 0 && it != values.end()) { 
        if(it -> first <= num){
            ans += it -> second;
            num -= it -> first;
        }
        else{
            it++;
        }
    }
    return ans;
}

int main() {
    int num;
    cin >> num;
    cout << IntegerToRoman(num);
    return 0;
}

/* Examples:
1. Input: num = 3
   Output: "III"
2. Input: num = 1994
   Output: "MCMXCIV" */

