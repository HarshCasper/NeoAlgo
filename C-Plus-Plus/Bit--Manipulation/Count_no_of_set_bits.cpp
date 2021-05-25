//Count No of Set Bits

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cout<<"Enter number \n";
	cin>>n;
	int res=0;
     while(n>0)
     {
     	res = res + (n & 1);
     	n=n>>1;
	 }
	  cout<<res; 
}

/*
Time Complexity: O(logn)
Space Complexity: O(1)
*/

/*
Sample Input:
Example 1:- 
Enter number
5
Example 2:-
Enter number
987

Sample Output:
Example 1:- 2
Example 2:- 8
*/