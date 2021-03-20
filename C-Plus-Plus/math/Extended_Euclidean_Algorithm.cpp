#include <iostream>
#include <tuple>

using namespace std;

int gcd (int a, int b, int &x, int &y) 
{
	//base case
	if (a == 0) 
  {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

// Iterative version of Extended Euclidean algorithm

int gcd_iterative(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int main()
{
    int x = 0, y = 0, a, b;
    cout<<"Enter the numbers whose GCD is to be found:"<<endl;
    cin>>a>>b;
	
    cout<<"GCD of "<<a<<" and "<<b<<" is:"<<endl;
    cout<<gcd(a, b, x, y)<<endl;
    cout<<"GCD (iterative method) is : "<<endl;
    cout<<gcd_iterative(a,b,x,y)<<endl;
    return 0;
}

/*
Input:
Enter the numbers whose GCD is to be found:
36
60

Output:
GCD of 36 and 60 is:
12
GCD (iterative method) is : 
12

Time Complexity: O(Log min(a, b))
Space Complexity: O(1)
*/
