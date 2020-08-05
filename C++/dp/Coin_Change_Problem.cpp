#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,coin[100],tot,i,j;
	cin>>n;
	for(i=0;i<n;i++)
	cin>>coin[i];
	cin>>tot;
	int dp[tot+1]={0};
	for(i=1;i<=tot;i++)
	{
		int num=INT_MAX;
		for(j=0;j<n;j++)
		{
			if(coin[j]<=i)
			num=min(num,dp[i-coin[j]]+1);    /*bottom-down approach*/
		}
		dp[i]=num;
	}
	cout<<dp[tot];
	return 0;
}
