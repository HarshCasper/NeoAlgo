#include <bits/stdc++.h>
using namespace std;
int F(int n){
    int arr[n+1],i,j;
    arr[0]=0,arr[1]=1;     // as 1 is the only integer coprime with 0
    for(i=2;i<=n;i++) arr[i]=i; // initialising arr[i] with i
    for(i=2;i<=n;i++){
        if(arr[i]==i){
        for(j=i;j<=n;j+=i) arr[j]-=(arr[j]/i); // just like sieve of eratosthenes we are decreasing values of multiple of primes
        }
    }
    return arr[n];  //  here each arr[i] is giving number of coprimes of i from 0 to i
}
int main(){
    int n;
    cin>>n;
    cout<<F(n); // printing Euler's Totient Function for int n
return 0;
}
// time complexity O(nloglogn) same as sieve of eratosthenes