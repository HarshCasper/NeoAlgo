//Count No of bits
//check if the kth bit is set or not

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
