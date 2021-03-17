#include <iostream>
#include <string.h>
#include <ctype.h>
#include <math.h>

using namespace std;

int onescomplement(int);

int main()
{
	int n;
	cout<<"\nEnter the no. = ";
	cin>>n;
	n = onescomplement(n);
	cout<<"\nOne's Complement of the given no. is = "<<n<<endl;
	return 0;
}

int onescomplement(int n)
{
	int n_bits = floor(log2(n))+1;
	return ((1<<n_bits)-1)^n;
}
