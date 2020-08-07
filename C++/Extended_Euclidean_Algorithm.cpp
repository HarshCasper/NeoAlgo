#include <iostream>

using namespace std;

int gcd (int a, int b, int &x, int &y) {
	//base case
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int main()
{
    int x = 0, y = 0, a, b;
    cout<<"Enter the numbers whose GCD is to be found:"<<endl;
    cin>>a>>b;
    cout<<"GCD of "<<a<<" and "<<b<<" is:"<<endl;
    cout<<gcd(a, b, x, y);
    return 0;
}
