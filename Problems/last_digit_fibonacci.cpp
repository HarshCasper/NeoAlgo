/* Find the last digit of the n-th Fibonacci number */

#include <iostream>
using namespace std;
typedef long long ll;
int fibo(ll n)
{
	if(n<=1)
	    return n;
	int fr=0;
	int sr=1;

	int tr=1;
	for(int i=2;i<=n;i++) 
	{
		tr=(fr+sr)%10;
		fr=sr%10;
		sr=tr%10;
	}
	return tr;
}
int main()
{
	ll n; # ll is for long long int
	cin>>n;

	cout<<fibo(n)<<endl;

}
