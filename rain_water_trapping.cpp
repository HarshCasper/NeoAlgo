#include<bits/stdc++.h>
using namespace std;
#define li long int
#define lli long long int
void solve(){

    // Question:   3 1 4 3 1 5 2
    // left_arr:   3 3 4 4 4 5 5
    // right_arr:  5 5 5 5 5 5 2
    // water_left: 0 2 0 1 3 0 0

    li n;
    cin>>n;
    li v[n];
    for(li i=0;i<n;i++)cin>>v[i];

    // Making a left and a right array.
    // Computing subsequent max elements from left sidewards and vice-versa

    li left_arr[n],right_arr[n];
    left_arr[0]=v[0];
    right_arr[n-1]=v[n-1];
    for(li i=1;i<n;i++)left_arr[i]=max(v[i],left_arr[i-1]);
    for(li i=n-2;i>=0;i--)right_arr[i]=max(right_arr[i],v[i+1]);
    li sum=0;

    // To find the amount of water getting collected inbetween the Buildings we find min between the right/left array at same indices and subtract the amount of space taken by the building

    for(li i=0;i<n;i++){

        sum+=min(left_arr[i],right_arr[i])-v[i];
    }
    cout<<sum<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    li t;
    cin>>t;
    while(t--){
        
        solve();
    }
    return 0;
}