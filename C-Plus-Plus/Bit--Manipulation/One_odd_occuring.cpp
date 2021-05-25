/*
	Only one odd ocurring number
	Using Xor Operation as Xor of two numbers gives zero
*/

#include<bits/stdc++.h>
using namespace std;
//to find missing number xor the array elements
// xor all elements from 1 to N
// Xor both the above two steps
int main()
{
	int n;
	cout<<"Enter number of elements \n";
	cin>>n;
    vector<int>arr;
    int a;
    for(int i=0;i<n;i++)
    {
    	cin>>a;
    	arr.push_back(a);
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		res= res ^ arr[i];
	}
	cout<<res<<endl;  
	  
}


/*
Time Complexity: O(n) 
Space Complexity: O(1)
*/

/*
Sample Input:
Example 1:- 
Enter number of elements
5
1 1 2 3 3
Example 2:-
Enter number of elements
7
71 4 9 71 9 7 7
Sample Output:
Example 1:- 2
Example 2:- 4
*/

