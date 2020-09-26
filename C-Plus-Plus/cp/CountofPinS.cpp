#include <iostream>
using namespace std;

// Problem Statement:
// Given a string, write a recursive function, to print the occurrences of string p in the string s(Overlap is allowed)
// Example :
// 1. Input: p = "aaa", s = "aaaaaa"
//   Output: 4
// 2. Input: p = "hi", s = "hihihithi"
//   Output: 4

void check_p_in_s(string p, string s, int stri, int count){ 
    if(stri == s.size()){ //When all the characters in string s are checked, print the count
        cout << count;
        return;
    }
    if(p == s.substr(stri, p.size())){ //When we find string p in string s, we increase the count and increment string index by 1
        return check_p_in_s(p, s, stri + 1, count + 1);
    }
    else{ //When string p does not match the substring in s, we just move to the next character without increasing the count
        return check_p_in_s(p, s, stri + 1, count); 
    }
}

int main(){
    string p, s;
    cin >> p;
    cin >> s;
    check_p_in_s(p, s, 0, 0);
    return 0;
}
