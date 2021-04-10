/*
Coin Change Problem Maximum Number of ways
This problem is solved using dp.
Given a value n which is total sum and m is size of coins array, 
and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
In this problem we have to count whether the values of subset of array is equal to sum or not.
if equal then we will increase count by 1 else we will return 0.
*/
#include<bits/stdc++.h>
using namespace std;

// This function is for checking whther the subset of array sum is equal to value or not
long long int count( int S[], int m, int n )
    {
      // We will create matrix t of size (n+1)*(sum+1)
       long long int t[m+1][n+1];

    /* if j is 0 i.e. sum is 0 and i i.e. arr has whatever values it will always return true
    because if sum is 0 then we don't need to find if subset of array is equal to sum or not */
       for(int i=0;i<m+1;i++){
           t[i][0] = 1;
       }

    /* But if i is 0 i.e array has no value and sum has some value then we can nver make 
    subset of array value equal to sum so it will always give false */
       for(int i=1;i<n+1;i++){
           t[0][i] = 0;
       }
       
       for(int i=1;i<m+1;i++){
           for(int j=1;j<n+1;j++){
               // if subset sum value less than sum then we will proceed further and we add value to it
               if(S[i-1] <= j){
                   t[i][j] = t[i-1][j] + t[i][j-S[i-1]];
               }
               // if subset sum value grater than sum then we will proceed further
               else{
                   t[i][j] = t[i-1][j];
               }
           }
       }
       
       return t[m][n];
}


// Driver Code 
int main()
{
    /* n is sum to which we have to make arr sum equal
    m is size of array */
    int n,m;
    cout << "Enter the value of n and m: \n";
    cin>>n>>m;
    int arr[m];
    cout << "Enter the value of array: \n";
    for(int i=0;i<m;i++){
	cin>>arr[i];
    }
   
    // count by recalling function
    cout<<count(arr,m,n)<<endl;
    return 0;
}  
/*
Input -
Enter the value of n andd m:
10 4
2 5 3 6
 Enter the value of array:
Output - 5
Time Complexity - O(n*m)
Space Complexity - O(n*m)
*/
