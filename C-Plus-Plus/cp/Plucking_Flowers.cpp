/* 
Jay's neighbour has a garden in which there are N flowers and each flower has a beauty associated with it i.e. ith flower
 has B[i] beauty. Jay wants to pluck exactly K flowers from his neighbour's garden such that the sum of beauties of all flowers
 he plucked is maximum but to not get caught he can't pluck more than one flower in a row, more formally he can't pluck two 
flowers if they are adjacent. Your task is to find maximum sum of beauty of all flowers Jay can get.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

long long maxBeauty(int n, int k, vector<int> &B){
        ll i,j,dp[k+1][n+1];
        memset(dp,0,sizeof(dp));
        for(i=1;i<=k;i++)
        {
            for(j=2*i-1;j<=n;j++)
            {
                dp[i][j]=B[j-1];
                if(j-2>=0)
                {
                    dp[i][j]+=dp[i-1][j-2];
                }
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
        return dp[k][n];
    }


int main(){
    
        int N, K;
        cin >> N >> K;              // size of array and max sum required
        vector<int> B(N);
        for(int i = 0; i < N; i++){
            cin >> B[i];                 // input array
        }
        long long ans =maxBeauty(N, K, B);
        cout << ans << endl;
    
}    
    
/*

Input:
N = 3
K = 2
B[] = {1, 1000000, 1}

Output: 2

Time Complexity: O(N*K)
Auxiliary Space: O(N*K)

*/
