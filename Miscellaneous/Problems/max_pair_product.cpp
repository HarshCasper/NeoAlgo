/* Suppose there is a vector having numbers >=0, you have to find the maximum product of the pair.

Example : { 2,9,1,5 }
Output : 45

*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
	ll n;
	cin>>n;
	vector <ll> pro;
	for(ll i=0;i<n;i++)
	{
		ll k;
		cin>>k;
		pro.push_back(k);
	}
	sort(pro.begin(),pro.end());
	ll ans=pro[n-1]*pro[n-2];
	
	cout<<ans<<endl;
	
	return 0;
}
