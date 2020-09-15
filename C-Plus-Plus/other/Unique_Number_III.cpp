/*Unique_Number_III
Given an array that contains all elements occurring 3 times, but one occurs only once. Find that unique element.*/
#include<iostream>
using namespace std;
int main()
{
	int cnt[64]={0};
	int n,no;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>no;
	
	int j=0;
	while(no>0)
	{
		int last_bit=(no&1);
		cnt[j]+=last_bit;
		j++;
		no=no>>1;
	}
}
	int p=1;
	int ans=0;
	for(int i=0;i<64;i++)
	{
		cnt[i]%=3;
		ans+=(cnt[i]*p);
		p=p<<1;
	}
	cout<<ans<<endl;
	return 0;
}
/*
Input : arr[] = {6, 2, 5, 2, 2, 6, 6}
Output : 5	
Time Complexity:O(n)
*/

