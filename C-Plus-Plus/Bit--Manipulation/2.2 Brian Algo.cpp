//Power of 2
//Idea is to use unset the right most bit 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"Enter number \n";
	cin>>n;
	int f =1;
	if(n==0)
	cout<<"No"<<"\n";
	
	if((n & (n-1)) != 0)
	cout<<"No"<<"\n";
	else
	cout<<"Yes"<<"\n";
	
	  
	  
}
