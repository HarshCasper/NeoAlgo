/*
You've heard of 0-1 knapsack. Below is the problem statement for the same.

Given weights and values of n items, put these items in a knapsack of capacity cap to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer cap which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to cap. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
There is a little twist for 0-N knapsack. You can pick an element more than once. Now you have to find maximum value multi subset of val[] such that sum of the weights of this subset is smaller than or equal to cap.

Note: Maximum value subset means the sunset with maximum sum of all the values in subset.

Sample Input
5 11
3 2 4 5 1
4 3 5 6 1
Sample Output
16

*/

#include<iostream>
#include<map>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
long long int U=0;
long long int B[2][1005];
void KnapSack(long long int T,long long int Cap,long long int S,long long int i,long long int V)
{
	if(i>=T || Cap>S)
	return;
	if(Cap<=S)
	U=max(U,V);
	KnapSack(T,Cap+B[0][i],S,i+1,V+B[1][i]);
	KnapSack(T,Cap,S,i+1,V);
}
long long int dp[1000]={0};
long long int KnapSack_2(long long int C,long long int S[],long long int V[],long long int T)
{
	for(long long int i=0;i<=C;i++)
	{
		for(long long int j=0;j<T;j++)
		{
			if(S[j]<=i)
			{
				dp[i]=max(dp[i],dp[i-S[j]]+V[j]);
			}
		}
	}
	return dp[C];
}

int main()
{
	long long int N,C,i,j;
	cin>>N>>C;
	long long int S[N];
	for(i=0;i<N;i++)
	cin>>S[i];
	long long int V[N];
	for(i=0;i<N;i++)
	cin>>V[i];
	std::map<long long int,long long int> A;
	for(i=0;i<N;i++)
	{
		map<long long int,long long int>::iterator M=A.find(S[i]);
		if(M!=A.end())
		{
			if(M->second<V[i])
			M->second=V[i];
		}
		else
		{
			A.insert(make_pair(S[i],V[i]));
		}
	}
    long long int T=A.size();
    i=0;
	cout<<KnapSack_2(C,S,V,N);
	return 0;
}
