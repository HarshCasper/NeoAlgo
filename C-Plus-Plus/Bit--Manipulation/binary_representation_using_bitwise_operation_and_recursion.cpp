#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>

using namespace std;

void bin(int);

int main()
{
	cout<<"\nEnter the number whose binary representation you want to see = ";
	int n;
	cin>>n;
	bin(n);
	cout<<endl;
	return 0;
}

void bin(int n)
{
	if(n>1)
		{bin(n>>1);}
	cout<<(n & 1);
}


