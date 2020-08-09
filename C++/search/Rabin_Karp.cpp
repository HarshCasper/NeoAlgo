#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//MODULAR EXPONENTIATION
ll power(ll x,ll y,ll p)
{
	ll res=1;
	x=x%p;
	while(y>0)
	{
		if(y&1)
		res=(res*x)%p;
		y=y>>1;
		x=(x*x)%p;
	}
	return res;
}
void search (string text,string pattern)
{
	ll m=text.size();
	ll n=pattern.size();
	ll t=0;//Hash of pattern
	ll h=0;//Hash of text
	ll q=pow(10,9);
	ll p=power(10,n-1,q);
	for(ll i=0;i<n;i++)
	{
		t=(10*t+pattern[i])%p;
		h=(10*h+text[i])%p;
	}
	for(int i=0;i<=m-n;i++)
	{
		if(h==t)
		{
			ll j;
			for( j=0;j<n;j++)
			{
				if(text[i+j]!=pattern[j])
				break;
			}
			if(j==n)
			cout<<"PATTERN FOUND AT "<<i<<endl;
		}
		if(i<m-n)
		{
			h=((10*(h-text[i]*p))+text[i+n])%p;
			if(h<0)
			h+=p;
		}
	}
}
int main()
{
	string text,pattern;
	getline(cin,text);
	getline(cin,pattern);
	search(text,pattern);
	return 0;
}
