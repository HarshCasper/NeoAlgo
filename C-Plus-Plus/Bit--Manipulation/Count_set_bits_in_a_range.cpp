//Copy set bits in a range
//Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. The task is consider set bits of y in range [l, r] and set these bits in x also.

#include<bits/stdc++.h>
using namespace std;
int copy_bits(int x, int y, int l, int r)
{
	int gap = r - l + 1;
	int mask1 = (1 << gap) - 1; //most imp
	int m2 = (mask1 << (l - 1));
	int mask = y & m2;
	x = x | mask;
	return x;
}
int32_t main()
{   
	int x ,y,l,r;
    cout<<"Enter the reqnumber"<<endl;
    cin>>x>>y>>l>>r;
	cout <<" Modified x is : "<< copy_bits(x, y, l, r);
	return 0;
}
/*
Time Complexity: O(gap) 
Space Complexity: O(1)
*/

/*
Given two numbers x and y, and a range [l, r]
Test cases:

Example 1:- 
Enter number
x = 10, y = 13, l = 2, r = 3


Example 2:-
Enter number
x = 8, y = 7, l = 1, r = 2


Sample Output:
Example 1:- 
Modified x is : 14

Example 2:- 
Modified x is : 11
*/
