/*Implementation of Quotient-Remainder Sorting algorithm (non-negative numbers only) C++*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Function for QR-Sort Algorithm implementation.
vector<ll> func(vector<ll> a, ll n){
    vector<ll> ans;
    /*Making a vector (v) of list of pair of type { Quotient , arr[i]} where Quotient=arr[i] / n. The index of vector represents remainder.*/
    vector<list<pair<ll,ll>>> v(n);
    for(ll i=0;i<n;i++){
        ll r=a[i]%n;
        v[r].push_back(make_pair(a[i]/n,a[i]));
    }
    /*To know when each pass is finished add delimiter {-1,-1} for each index in the vector*/
    for(ll i=0;i<n;i++)v[i].push_back(make_pair(-1,-1));
    /* Iterate over each row of the vector and pop out the element.
    If the first element of the popped-out pair is 0 then insert the second element of the popped out pair.
    into the output array and if not then insert the quotient obtained by dividing the first element of pair into the corresponding remainder position.
    While doing this if delimiter i.e. {-1,-1} is found then break the loop.
    After doing the same procedure for all v[i] again add the delimiter as one passed is finished.
    Run the whole procedure until the size of output array is not equal to input array. */
    while(ans.size()!=n){
        for(ll i=0;i<n;i++){
            while(!v[i].empty()){
               pair<ll,ll> p=v[i].front();
               v[i].pop_front();
               if(p.first==-1){
                   break;
               }
               else{
                   if(p.first==0)ans.push_back(p.second);
                   else v[p.first%n].push_back(make_pair(p.first/n,p.second));
               }
            }
        }
        for(ll i=0;i<n;i++){
            v[i].push_back(make_pair(-1,-1));
        }
    }
    // Returning the sorted array.
    return ans;
}

int main() {
    ll n;
    cout<<"Enter input size"<<endl;
    cin>>n;
    vector<ll> a(n);
    vector<ll> ans;
    cout<<"Enter input array:"<<endl;
    for(ll i=0;i<n;i++){
           cin>>a[i];
    }
    cout<<endl;
    if(n!=1){
        ans=func(a,n);
    }
    else{
        ans.push_back(a[0]);
    }
    cout<<"Output array:"<<endl;
    for(ll i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/* Sample example:
   Enter input size:
   5
   Enter input array:
   15 2 89 0 3
   Output array:
   0 2 3 15 89

   Time Complexity:-
         T(n)= { O(1) if n=1,
                 O(n*log(m base n) +n) otherwise
               }
   Space Complexity = Auxiliary space + Space used by input values
                                   = O(1)+O(1)=O(1) if n=1
                                   = O(n)+O(n)=O(2*n) if n>1 in Worst case. */