#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int t,n,i,j;
    cin >> t;
    while(t--){
        cin >> n;
        long long int a[n];
        
        for(i=0;i<n;i++)
        cin >> a[i];
        
        long long int pre_sum[n];
        pre_sum[0] = a[0];
        
        for(i=1;i<n;i++)
        pre_sum[i] = pre_sum[i-1] + a[i];
        
        long long int res = INT_MIN, min_pre_sum = 0;
        
        for(i=0;i<n;i++){
            res = max(res, pre_sum[i] - min_pre_sum);
            min_pre_sum = min(min_pre_sum, pre_sum[i]);
        }
        cout << res << "\n";
    }
    return 0;
}
