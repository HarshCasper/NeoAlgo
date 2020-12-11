#include <bits/stdc++.h>
#define N 1000000
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
// Find the number of binary trees possible given the size of the preorder sequence-n
// Dynamic Programming Approach
// Complexity : Time- O(n^2) ; Space- O(n)
int main()
{
    int n;
    cin>>n;
    lli *dp=(lli *)malloc((n+1)*sizeof(lli));
    dp[0]=1,dp[1]=1;
    //Since number of trees that can be formed for n=0/1 is 1
    for(int i=2;i<=n;i++)
    {
        dp[i]=0;
        for(int j=0;j<i;j++)
        {
            dp[i]+=(dp[j]*dp[i-j-1]);
        }
    }
    //Calculation is same to that of catalan number
    /*for(int i=0;i<=n;i++)
        cout<<dp[i]<<" ";
    cout<<endl;*/
    cout<<dp[n]<<endl;
    free(dp);
    return 0;
}
/* Sample input:-
        n = 5;
        Output = 42;
        */
