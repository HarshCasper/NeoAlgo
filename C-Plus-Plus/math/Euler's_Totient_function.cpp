#include <bits/stdc++.h>
using namespace std;
int F(int n){
    int arr[n+1],i,j; 
    for(i=0;i<=n;i++){
        arr[i]=i;
    }
    for(i=2;i<=n;i++){
        if(arr[i]==i){             // checking if arr[i] has been untouched or not
            for(j=i;j<=n;j+=i){
                arr[j]-=arr[j]/i;  // here we are removing no. of coprime of j integer
            }
        }
    }
    // till now arr[i] shows no. of coprimes of n from 1 to n
    for(i=2;i<=n;i++){
        arr[i]+=arr[i-1]; // applying dp to calculate no. of coprime 
    }                     // between 1 and n (both 1 and n inclusive)
    return arr[n];
}
int main(){
    int n;
    cin>>n;
    cout<<F(n)<<endl; // always remember 0 is only coprime with 1
    return 0;        
}
