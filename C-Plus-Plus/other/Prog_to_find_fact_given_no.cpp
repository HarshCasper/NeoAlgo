#include<iostream>
using namespace std;
int main()
{
	int n,fact=1;
	cout<<"Enter no to find its factorial: ";
	cin>>n;
	for(int a=1;a<=n;a++)
	{
		fact=fact*a;
	}
	cout<<"Factorial Of Given No is: "<<fact;
	return 0;
}

