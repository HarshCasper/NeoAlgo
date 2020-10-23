Time Complexity : O(n) 
Space Complexity: O(n)
Sample Input:
2                        //no. of testcases 
8                        //size of array
4 -8 9 -4 1 -8 -1 6       
9                        //size of array
-2 1 -3 4 -1 2 1 -5 4
Sample Output:
9                        
6

#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int t,n,i,j;  //t -> no. of testcases, n -> size of array
    cin >> t;
    while(t--){
        cin >> n;
        long long int a[n];
        
        for(i=0;i<n;i++)            //input array
        cin >> a[i];
        
        long long int pre_sum[n];         
        pre_sum[0] = a[0];
        
        for(i=1;i<n;i++)                       //array that stores prefix sum of input array
        pre_sum[i] = pre_sum[i-1] + a[i];
        
        long long int res = INT_MIN, min_pre_sum = 0;
        
        for(i=0;i<n;i++){
            res = max(res, pre_sum[i] - min_pre_sum);               //loop through array while keeping track of minimum prefix sum so far and maximum subarray sum
            min_pre_sum = min(min_pre_sum, pre_sum[i]);
        }
        cout << res << "\n";
    }
    return 0;
}
