/*
Minimum Sum Partition using dp.
In this problem we have to find minimum difference of two subset.
We have to divide array in two subsets in such a way that difference of both subsets 
will become minimum.
*/
#include <bits/stdc++.h>
using namespace std;

int minimumSumPartition(int arr[], int sum, int N)
{
    bool DP[N + 1][sum + 1];

    /* if j is 0 i.e. sum is 0 and i i.e. arr has whatever values it will always return true
    because if sum is 0 then we don't need to find if subset of array is equal to sum or not */
    for (int i = 0; i <= N; i++) 
        DP[i][0] = true; 
  
    /* But if i is 0 i.e array has no value and sum has some value then we can nver make 
    subset of array value equal to sum so it will always give false */
    for (int i = 1; i <= sum; i++) 
        DP[0][i] = false;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                DP[i][j] = DP[i-1][j-arr[i-1]] || DP[i-1][j];
            else 
                DP[i][j] = DP[i-1][j];
        }
    }
    int i = sum;
    while(! DP[N][i])
        i--;
    
    // then we will return minimum difference
    return 2*sum - 2*i;
    
}

int main()
{
    int N, ans;

    cout << "Enter the value of N: \n";
    cin >> N;
    int arr[N], sum = 0;

    //We will find the total sum of array to find the range of the array
    cout << "Enter the value of array: \n";
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }


   ans = minimumSumPartition(arr, sum/2, N);

   if (sum & 1)
        ans++;

   cout << ans << "\n";

   return 0;
}
/*
Sample Output:

Input:
Enter the value of N:
4
Enter the value of array:
1 6 5 11

Output: 
1

Time Complexity - O(N*sum)
Space Complexity - O(N*sum)

*/
