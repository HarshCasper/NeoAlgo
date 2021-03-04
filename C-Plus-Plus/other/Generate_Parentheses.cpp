// generate paranthesis II
/*  For a given N, Program to generate every possible balanced paranthesis. 
	
	input: 3
	output: 
	((()))
	(()())
	(())()
	()(())
	()()()
	
	This program is recursive based. 
*/
#include<bits/stdc++.h>
using namespace std;

void generateParenthesis(int n, int o, int c, string str) {
    if(c == n) {
        cout<<str<<endl;
        return;
    }
    if(o > c) {
        generateParenthesis(n, o, c+1, str+')');
    }
    if(o < n) {
        generateParenthesis(n, o+1, c, str+'(');
    }
}

int main(){
    int n;
    cin>>n;
    generateParenthesis(n, 0, 0, "");
    return 0;
}