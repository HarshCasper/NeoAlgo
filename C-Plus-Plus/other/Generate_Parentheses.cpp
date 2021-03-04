// Generate Parantheses 
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

void generate(char *out,int n,int idx,int open,int close){
    if(idx == 2*n){ 
        out[idx]='\0';
        cout<<out<<endl;
        return;
    }
    if(open<n){
        out[idx]='(';
        generate(out,n,idx+1,open+1,close);
    }
    if(close<open){
        out[idx]=')';
        generate(out,n,idx+1,open,close+1);
    }
    return;
}

int main(){
    int n;
    cin>>n;
    char out[1000]; // for output array 
    int idx = 0;
    generate(out,n,idx,0,0);
    return 0;
}
