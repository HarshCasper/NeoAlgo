/*
<<<<<<<<<<<---APPROACH-->>>>>>>>>>>>>>
Main concern is to make mask to copy same number between l to r.
*/
#include<bits/stdc++.h>
using namespace std;

int copy_bits(int x, int y, int l, int r)
{
	int gap = r - l + 1;
	/*
	let gap=4; 00000001
	1<<gap == 00010000 // shift 1 by 4 times
	mask1=(1<<gap)-1 == 00001111	most imp

	YOU CAN ALSO PERFORM ALL OPERATION WITH ONE VARIABLE AS MASK
	*/
	int mask1 = (1 << gap) - 1; //most imp
	int m2 = (mask1 << (l - 1));
	int mask = y & m2;
	x = x | mask;
	return x;
}

int32_t main()
{   
	int x = 10, y = 13, l = 2, r = 3;
    cin>>x>>y>>l>>r;
	/*
	 987654321	//right to left l and r are assigned (it can also start from 0 but make sure while writing ans.)
	y=101010101
	*/
	cout <<" Modified x is : "<< copy_bits(x, y, l, r);
	return 0;
}

/*
Given two numbers x and y, and a range [l, r]
Sample Input : x = 10, y = 13, l = 2, r = 3
sample Output : x = 14

Sample Input : x = 8, y = 7, l = 1, r = 2
sample Output : x = 11

*/