#include <iostream>
using namespace std;

//Recursion+Memoization
int fib(int n,int dp[]){
	//base case
	if(n == 0 || n == 1) return n;
	//Recursive
	//Look Up
	if(dp[n] != 0) return dp[n];

	int ans;
	ans = fib(n-1,dp)+fib(n-2,dp);
	return dp[n] = ans;
}


int main() {
 int n;
 cin>>n;
 int dp[n+1]={0};
 cout<<"output :"<<fib(n,dp)<<endl;

return 0;
}

/*
sample input output
input: 10
output: 55
*/

/*
Space O(n)
Time O(n)
*/
