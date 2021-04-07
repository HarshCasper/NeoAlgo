/*
This problem is solved using dp.
In this problem we have to find two subsets which will return minimum difference
*/
#include <iostream>
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
            // if subset sum value less than sum then we will proceed further and we add value to it or we will leave it
            if (arr[i - 1] <= j)
                DP[i][j] = DP[i-1][j-arr[i-1]] || DP[i-1][j];
            else // if subset sum value grater than sum then we will proceed further
                DP[i][j] = DP[i-1][j];
        }
    }
    
    //i will check in last row from right where i get first true subset sum....it will give my answer

    int i = sum;

    // till value of matrix of last row do not return true we will decrese value of i by 1
    while(! DP[N][i])
        i--;
    
    // then we will return minimum difference
    return 2*sum - 2*i;
    
}

//Driver code
int main()
{
    int T, N, ans;
    cin >> T;

    while (T--)
    {
        cin >> N;
        int arr[N], sum = 0;
        
        //We will find the total sum of array to find the range of the array
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        
       
       ans = minimumSumPartition(arr, sum/2, N);

       if (sum & 1)
            ans++;

        cout << ans << "\n";
       
    }

    return 0;
}
/*
Input -
4
1 6 5 11
Output - 
1
Time Complexity - O(N*sum)
Space Complexity - O(N*sum)
*/
