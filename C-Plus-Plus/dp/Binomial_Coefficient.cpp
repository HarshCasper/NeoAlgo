
/* Definition: 
A binomial coefficient C(n, k) can be defined as the coefficient of x^k 
in the expansion of (1 + x)^n.
Input:
Enter the value of n and k :
4 2
Output:
6
Explanation:
4C2=4!/(2!*(4-2)!)
=>(4*3*2*1)/(2*1*2*1)
=>6
*/ 
//Time Complexity: O(n*k)
//Space Complexity: O(n*k)
#include <bits/stdc++.h>
using namespace std;
 
int binomialCoeffMemorization(int n,int k,vector<vector<int>>&dp){
    if(n==k||k==0)//if n is equal to k or if k is equal to 0 then it is return 1 as nCn and nC0 is 1
        return 1;
    if(dp[n][k]!=-1)//Checks whether dp[n][k] is already present
        return dp[n][k];//Returns dp[n][k] if present
    else{//Storing dp[n-1][k-1]+dp[n-1][k] to dp[n][k]
        return dp[n][k]=binomialCoeffMemorization(n-1,k-1,dp)+binomialCoeffMemorization(n-1,k,dp);
    }
}
void binomialCoefTabulation(int n,int k){
    vector<vector<int>>dp2(n+1,vector<int>(k+1,-1));
    for(int row=0;row<=n;row++){
        for(int col=0;col<=k;col++){
            if(col<=row){
            if(col==0||row==col)
            dp2[row][col]=1;
            else{
                dp2[row][col]=dp2[row-1][col-1]+dp2[row-1][col];
            }
            }
        }
    }
     cout << "Tabulation: Value of C(" << n << ", " << k << ") is "
         <<dp2[n][k]<< endl;  
} 
int main()
{
    int n,k;
    cout<<"Enter the value of n and k (n must be greater than or equal to k): ";
    cin>>n>>k;
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    cout << "Memorization: Value of C(" << n << ", " << k << ") is "<< binomialCoeffMemorization(n, k,dp) << endl;
    binomialCoefTabulation(n,k);
    return 0;
}
