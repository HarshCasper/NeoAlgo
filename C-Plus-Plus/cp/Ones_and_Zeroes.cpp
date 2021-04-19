/*
You are given an array of
binary strings S and two 
integers M and N.Print the
size of the largest subset
of S such that there are
at most M 0's and N 1's in
the subset.
*/

#include<bits/stdc++.h>
using namespace std;

int findMaxForm(vector<string>& S, int M, int N) {
    int size=S.size();
    int i,j,k;
    int DP[size+1][M+1][N+1];
    for(i=0;i<=size;i++)
    {
        for(j=0;j<=M;j++)
        {
            for(k=0;k<=N;k++)
            {
                DP[i][j][k]=0;
            }
        }
    }
    int ans=0;
    for(i=1;i<=size;i++)
    {
        int O=count(S[i-1].begin(),S[i-1].end(),'1');
        int Z=S[i-1].size()-O;
        for(j=0;j<=M;j++)
        {
            for(k=0;k<=N;k++)
            {
                DP[i][j][k]=DP[i-1][j][k];
                if((j>=Z)&&(k>=O))
                DP[i][j][k]=max(DP[i][j][k],DP[i-1][j-Z][k-O]+1);
                ans=max(ans,DP[i][j][k]);
            }
        }
    }
    return ans;
}
int main()
{
	vector<string> S;
	string temp;
	int size,i,N,M;
	cout<<"Enter the size of Array"<<endl;
	cin>>size;
	for(i=0;i<size;i++)
	{
		cin>>temp;
		S.push_back(temp);
	}
	cout<<"Enter the value of N and M"<<endl;
	cin>>N>>M;
	cout<<findMaxForm(S,M,N)<<endl;
	return 0;
}

/*
Time Complexity:O(S*N*M)
Space Complexity:O(S*N*M)
where S is the size of Array,
N is the no of '1' and M is
the no of '0'.

Sample Input/Output: 
Input:
Enter the size of Array
4
S=["10","0001","111001","1","0"]
Enter the value of N and M
3 5
Output: 
4
*/

