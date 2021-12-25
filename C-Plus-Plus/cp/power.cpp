/* Program to calculate b^n%m . This program also known as 
    Recursive Modular Exponentiation */
	 
#include<iostream>
#include <cmath>
using namespace std;

int power(int b,int n,int m)  
{
	if(n==0)
	  return 1;
	else if(n%2==0)
	  return power(b,n/2,m)*power(b,n/2,m)%m;
	else
	  return power(b,n/2,m)*power(b,n/2,m)%m*b%m;
}
int main()
{
	int b,n,m;
	cout<<"Enter base \n";
	cin>>b;
	cout<<"Enter Exponent \n";
	cin>>n;
	cout<<"Enter Value to take modulus\n";
	cin>>m;
	cout<<"\nAnswer of b ^ n % m : "<<power(b,n,m);
}
/*
Input:-
2 6 6 
Ouput:-
4
*/

/*
Time Complexity - O(n)
Space Complexity - O(n)
*/


