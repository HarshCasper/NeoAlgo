/*A program in c++ to count the no of ways to reach the nth stair.
A classic dynamic programming problem asked by Google, Amazon, Oyo, Goldman Sachs and many more
Author: Kaviraj Singh Bhati
Date: 16-12-2020
Tags: Winter of Code
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
	cin >> n;
	int ways[n+1];    //array to store the no of ways. In general, we can climb 1 or 2 steps.
	ways[0] = 1;      //you cannot climb 0 steps, so 1
	ways[1] = 1;      //only 1 way
	for(int i = 2; i <= n; i++)
	    {
	        ways[i] = ( ways[i-1] + ways[i-2] );      //we can only come from previous step or the one before the previous
	    }
	cout << ways[n] << endl;

    return 0;
}


//time complexity: O(n)
//space complexity : O(n)
//example: 
// input: 3
//output: 3
//explanation: 3 ways to reach the top [ 1+1+1, 1+2, 2+1]