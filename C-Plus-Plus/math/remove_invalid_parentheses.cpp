/*
This problem is solved using backtracking.
In this problem we will be given string of parenthesis which will open and closing parenthesis.
We will have to remove minimum no. of parenthesis to make the string valid and will print all possible valid strings made by min. removal.
*/
#include <bits/stdc++.h>
using namespace std;

// this function is to find no. of parenthesis to be removed from the string
int minRemoval(string str){
    stack<int> s;
    for(int i=0;i<str.length();i++){
        // if it is a open parentheses then we will always push
        if(str[i] == '('){
            s.push(str[i]);
        }
        // if closed parentheses
        else if(str[i] == ')'){
            // if stack is empty then we will push
            if(s.size() == 0){
                s.push(str[i]);
            }
            // if stack top is closed parentheses then we will push
            else if(s.top() == ')'){
                s.push(str[i]);
            }
            // if stack top is open parentheses then we will pop
            else {
                s.pop();
            }
        }
    }
    // size left will me the minimum parentheses to be removed to make the string valid
    return s.size();
}

void validParentheses(string str, int rm, unordered_set<string> &result){
    if(rm == 0){
        int remove = minRemoval(str);
        if(remove == 0){
            result.insert(str);
        }
        return;
    }
    for(int i=0;i<str.length();i++){
        string left = str.substr(0,i);
        string right = str.substr(i+1);
        validParentheses(left + right,rm-1,result);
    }
}

// driver code
int main() {
    // Input the parentheses string
    string str;
    cin>>str;
    unordered_set<string> result;
    // no. of parentheses to be removed
    int remove = minRemoval(str);
    //recursive call
    validParentheses(str,remove,result);
    for(auto i:result){
        cout<<i<<endl;
    }
    return 0;
}

/*
Input - ()())()
Output - 
()()()
()())()
Time Complexity - O(n!)
*/
