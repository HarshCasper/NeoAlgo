/* Problem Statement: 
Given a string of '(' , ')' and lowercase english characters.
The task is to remove the minimum number of parentheses so that the resulting parentheses string is valid.
A parentheses string is valid if and only if:
1.It is the empty string, contains only lowercase characters, or
2.It can be written as AB (A concatenated with B), where A and B are valid strings, or
3.It can be written as (A), where A is a valid string. */

#include <bits/stdc++.h>
using namespace std;

bool matching(char a, char b){ //checks if character a and b together make () or not
    if(a == '(' && b == ')'){
        return true;
    }
    return false;
}

string removeMin(string s){
    int n = s.size();
    //to store character and its index together
    stack<pair<char, int> > st;  
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            st.push({s[i], i});
        }
        else if(s[i] == ')'){
            if(st.empty() || !matching(st.top().first, s[i])){
                st.push({s[i], i});
            }
            else{
                st.pop();
            }
        }
    }
    while(!st.empty()){
        int idx = st.top().second;
        //remove all the elements from the string that were making the string invalid
        s.erase(s.begin() + idx); 
        st.pop();
    }
    return s;
}

int main() {
    string s;
    cin >> s;
    cout << removeMin(s);
    return 0;
}

/* Examples: 
1.  Input: "he((l)l)o)"
    Output: "he((l)l)o"
2.  Input: ")))((("
    Output: "" */
