#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T>0)
	{
	
	int n;
	//cout<<"Enter size of array of 0's and 1's: ";
	cin>>n;
	int i,a[n];
	//cout<<"\nEnter array elements: ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int c0=0,c1=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			c0++;
		}
		else
		{
			c1++;
		}
	}
	while(c0>0)
	{
		cout<<0<<" ";
		c0--;
	}
	while(c1>0)
	{
		cout<<1<<" ";
		c1--;
	}
	cout<<endl;
	T--;
}
	
	
}
