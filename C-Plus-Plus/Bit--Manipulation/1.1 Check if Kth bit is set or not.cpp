//check if the kth bit is set or not

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cout<<"Enter number \n";
	cin>>n;
	cout<<"Enter bit no \n";
	cin>>k;
	//Using left shift operator
	if((n & (1<<(k-1))) != 0)
	 cout<<"Yes"<<"\n";
	 else
	  cout<<"No"<<"\n";
	  // using right shift operator
	  if((n>>(k-1)) & 1)
	   cout<<"Yes"<<"\n";
	 else
	  cout<<"No"<<"\n";
	  
	  
	  
}
