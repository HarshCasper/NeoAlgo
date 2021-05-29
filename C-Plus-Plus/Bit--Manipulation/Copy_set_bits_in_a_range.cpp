//Copy set bits in a range

/*
Given two numbers x and y, and a range [l, r]
Sample Input : x = 10, y = 13, l = 2, r = 3
sample Output : x = 14

Sample Input : x = 8, y = 7, l = 1, r = 2
sample Output : x = 11

*/
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
	cout<<"Enter number"<<endl;
    cin>>x>>y>>l>>r;
	cout <<" Modified x is : "<< copy_bits(x, y, l, r);
	return 0;
}

/*
Time Complexity: O(log(gap))
Space Complexity: O(1)
*/

/*
Sample Input:
Example 1:- 
Enter number
x = 10, y = 13, l = 2, r = 3

Example 2:-
Enter number
 x = 8, y = 7, l = 1, r = 2

Sample Output:
Example 1:- Modified x is : 14
Example 2:- Modified x is : 11
*/