//Check if the kth bit is set or not

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cout<<"Enter number \n";
	cin>>n;
	cout<<"Enter bit no \n";
	cin>>k;
	//Using left shift operator
	 cout<<"Using Left Shift operator ";
	if((n & (1<<(k-1))) != 0)
	 cout<<"Yes"<<"\n";
	 else
	  cout<<"No"<<"\n";
	  // using right shift operator
	  cout<<"Using Right Shift operator ";
	  if((n>>(k-1)) & 1)
	   cout<<"Yes"<<"\n";
	 else
	  cout<<"No"<<"\n";
	  
}

/*
Time Complexity: O(1) 
Space Complexity: O(1)
*/

/*
Test cases:

Example 1:- 
Enter number
8
Enter bit no
4

Example 2:-
Enter number
50
Enter bit no
4

Sample Output:
Example 1:- 
Using Left Shift operator Yes
Using Right Shift operator Yes

Example 2:- 
Using Left Shift operator No
Using Right Shift operator No
*/

