#include <bits/stdc++.h>
using namespace std;

int max_sum_subarray(int a[], int n){

    int max_ending=a[0];

    int ans=a[0];

    for(int i=1;i<n;i++)
    {
        max_ending=max(max_ending+a[i], a[i]);
        ans=max(ans,max_ending);
    }

    return ans;

}

int main() {
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<max_sum_subarray(a,n);
    
}
