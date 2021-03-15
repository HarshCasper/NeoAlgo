//Count No of Set Bits
//Simple Method


#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cout<<"Enter number \n";
	cin>>n;
	int res=0;
     while(n>0)
     {
     	res = res + (n & 1);
     	n=n>>1;
	 }
	  cout<<res;
	  
	  
}
