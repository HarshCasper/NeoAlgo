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
    
        int totalFlowers, k;
        cout << "Enter total number of flowers and maximum flowers to be plucked ";
        cin >> totalFlowers >> k;                          // size of array and max flowers required
        vector<int> Beauty(totalFlowers);
        cout<< " Enter beauty of each flower : " ;
        for(int i = 0; i < totalFlowers; i++){
            cin >> Beauty[i];                                    // input array
        }
        long long answer =maxBeauty(totalFlowers , k , Beauty);
        cout << " maximum sum of beauty by k flowers : " << answer << endl;
    
}    
    
/*

Input:
Enter total number of flowers and maximum flowers to be plucked : 3  2
Enter beauty of each flower : 1  1000000  1

Output: 
maximum sum of beauty by k flowers : 2

Time Complexity: O(totalFlowers*K)
Auxiliary Space: O(totalFlowers*K)

*/
