 /*
Coin Change Problem Minimum number of coins
This problem is solved using dp.
Given a value amount, and array of coins we have to find minimum no. of coins required 
to make it equal to amount given and we have infinite supply of each of coins,
*/
#include<bits/stdc++.h>
using namespace std;

// This function is for calculating minimum no. of coins we require
int coinChange(int coins[100],int n, int amount) {
        int t[n+1][amount+1];
        // if value of amount is zero then total coins required will be zero
        for(int i=0;i<n+1;i++){
            t[i][0] = 0;
        }
        // if coins available are zero 
        for(int i=1;i<amount+1;i++){
            t[0][i] = INT_MAX-1;
        }
        
       for(int i=1;i<amount+1;i++){
            if(i%coins[0] == 0){
                t[1][i] = i/coins[0];
            }
            else{
                t[1][i] = INT_MAX - 1;
            }
        }
        // for finding the minimum no. of required for making it equal to amount
        for(int i=2;i<n+1;i++){
           for(int j=1;j<amount+1;j++){
             if(coins[i-1] <= j){
                 t[i][j] = min(1+t[i][j-coins[i-1]], t[i-1][j]);
             }
             else{
                 t[i][j] = t[i-1][j];
             }
           }
        }
        
        return t[n][amount] == INT_MAX-1?-1:t[n][amount];
    }

// Driver Code 
int main()
{ 
    int amount=11,n=3;
    cout << "Enter the value of amount: \n";
    cin>>amount;
    int arr[100];
    cout << "Enter the value of array: \n";
    for(int i=0;i<m;i++){
     cin>>arr[i];
    }
   
    // count by recalling function
    cout<<coinChange(arr,n,amount)<<endl;
    return 0;
}  
/*
Input -
Enter the value of n andd m:
11 3
1 2 5
Enter the value of array:
Output - 3
Time Complexity - O(n*m)
Space Complexity - O(n*m)
*/
