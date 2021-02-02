//You are provided an array of integers where each element represents the max number of steps you can take to move ahead. You need to check that how many minimum steps required to reach at the end of the array.

//Hint - If N==0 you can never move forward, your return INT_MAX (Infinity).
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
long long int M;
void Find_Min(long long int A[],long long int Min_Steps,long long int i,long long int N)
{
	long long int j;
	if(i>=N)
	{
	M=min(M,Min_Steps);
	return;
    }
	if((M!=INT_MAX  &&  Min_Steps<M)  ||  M==INT_MAX)
	{
	for(j=i+1;j<=i+A[i];j++)
	{
		Find_Min(A,Min_Steps+1,j,N);
	}
	}
}
int main()
{
	long long int T,i,N;
	cin>>T;
	while(T--)
	{
		M=INT_MAX;
		cin>>N;
		long long int A[N];
		for(i=0;i<N;i++)
		cin>>A[i];
		Find_Min(A,0,0,N);
		cout<<M;
	}
}
