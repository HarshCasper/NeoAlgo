#include<bits/stdc++.h>
using namespace std;


int Ackerman_function(int m, int n)
{
	if(m==0)
		return n+1;
		
	else if(m>0&&n==0)
	
		return Ackerman_function(m-1,1);
		
	else if(m>0&&n>0)
		return Ackerman_function(m-1,Ackerman_function(m,n-1));
}

int main()
{
	int m,n;
	cin>>m>>n;
	
	cout<<Ackerman_function(m,n);
	cout<<m;

	return 0;
}