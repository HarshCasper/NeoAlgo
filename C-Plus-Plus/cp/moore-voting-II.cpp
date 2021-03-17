#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define pb push_back

#define loop(x,n) for(ll x = 0; x < n; ++x)

 
ll majority(vl v,ll n){
  ll cnt1=0,cnt2=0;
  ll first=INT_MAX,second=INT_MAX;

  loop(i,n){
      if(first==v[i]) cnt1++;

      else if(second==v[i]) cnt2++;

      else if(cnt1==0) {
          cnt1++;
          first=v[i];
      }

      else if(cnt2==0) {
          cnt2++;
          second=v[i];
      }

      else{
          cnt1--;
          cnt2--;
      }
  }

cnt1=0;
cnt2=0;

loop(i,n){
    if(v[i]==first) cnt1++;
    else if(v[i]==second) cnt2++;  
}
if(cnt1 > n/3) return first;
if(cnt2 > n/3) return second;

return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    //size of vector
    ll n;
	cin>>n;
    ll i,z;

    //vector 
    vl v;
    
    loop(i,n){
        cin>>z;
        v.pb(z);
    }

    ll x=majority(v,n);
    if(x==-1) cout<<"No such element exists\n";
     else cout<<"Element whose frequency is more than n/3 is: "<<x<<"\n";

	return 0;
}

/*
Input:
First line contains size of vector(n)
Then 2nd line contains elements of vector


TEST CASE
5
1 2 3 1 1

OUTPUT
Element whose frequency is more than n/3 is: 1

Time- complexity: O(n)

Space Complexity: O(1)
*/
