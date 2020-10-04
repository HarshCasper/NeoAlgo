'''
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. 
The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. 
By convention, 1 is included. Write a program to find Nth Ugly Number.

Example 1:
Input:
N = 10
Output: 12
Explanation: 10th ugly number is 12.

Example 2:
Input:
N = 4
Output: 4
Explanation: 4th ugly number is 4.
'''

#include<bits/stdc++.h>
using namespace std;

int main()
{
	//code
	int t;
	cin>>t;
	
	long long arr[10000];
	int c2 = 0, c3 = 0, c5 = 0;
	arr[0] = 1;
	
	for(int i=1; i<10000; i++)
	{
	    arr[i] = min(arr[c2]*2, min(arr[c3]*3, arr[c5]*5));
	    
	    if(arr[i] % 2 == 0)
	        c2++;
	    if(arr[i] % 3 == 0)
	        c3++;
	    if(arr[i] % 5 == 0)
	        c5++;
	}
	
	while(t>0)
	{
	    int n;
	    cin>>n;
	    cout<<arr[n-1]<<endl;
	    t--;
	}
	return 0;
}