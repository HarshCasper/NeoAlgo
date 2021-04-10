/*
This problem is solved using dp.In this problem we will have array and difference.
We have to divide array into two subsets in such a way that difference of both subsets 
will become equal to given difference.If equal then we will increase count by 1.
and if there is no such subset then will return 0 else will return count.
*/
#include <bits/stdc++.h>
using namespace std;

// This function is for checking whther the subset of array sum is equal to value or not
int minDiff(int arr[], int n, int sum){

     // We will create matrix t of size (n+1)*(sum+1)
    int t[n+1][sum+1];
    /* if j is 0 i.e. sum is 0 and i i.e. arr has whatever values it will always return true
    because if sum is 0 then we don't need to find if subset of array is equal to sum or not */
    for(int i=0;i<n+1;i++){
        t[i][0] = 1;
    }
    /* But if i is 0 i.e array has no value and sum has some value then we can nver make 
    subset of array value equal to sum so it will always give false */
    for(int i=1;i<sum+1;i++){
        t[0][i] = 0;
    }
    for(int i=1;i<n+1;i++){
       for(int j=1;j<sum+1;j++){
          // if subset sum value grater than sum then we will proceed further
          if(arr[i-1] <= j){
            t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
           }
           // if subset sum value less than sum then we will proceed further and we add value to it
           else{
            t[i][j] = t[i-1][j];
           }
        }
    }
    
    // return total count
    return t[n][sum];
}

//driver code
int main() {
    int n,diff;
    cin>>n>>diff;
    int arr[n+1];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int total = 0;
    for(int i=0;i<n;i++){
        total += arr[i];
    }
    int sum = (total + diff)/2;

    cout<<minDiff(arr,n,sum);
    return 0;
}
/*
Input - 
4 1
1 1 2 3
Output - 3
Time Complexity - O(n*sum)
Space Complexity - O(n*sum)
*/
