#include <iostream>
#include <string.h>
#include <ctype.h>

using namespace std;

int count1s0s(int);

int main()
{
	int n;
	cout<<"\nEnter the no. = ";
	cin>>n;
	count1s0s(n);
	return 0;
}

int count1s0s(int n)
{
	int count1=0;
	int count0=0;
	while(n>0)
		{
			if(n&1){count1++;}
			else {count0++;}
			n = n>>1;
		}
	cout<<"\nNo. of 1s = "<<count1<<" No. of 0s = "<<count0<<endl;
	return 0;
}
