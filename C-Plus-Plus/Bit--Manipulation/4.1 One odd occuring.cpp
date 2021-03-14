// Only one odd ocurring number

#include<bits/stdc++.h>
using namespace std;
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
//to find missing number xor the array elements
// xor all elements from 1 to N
// Xor both the above two steps
