// Checks whether a given number is Mersenne prime or not
/*
* A Mersenne prime is a prime that's also just 1 short of a power of 2
* i.e. of the form 2^k-1, k>=2
*/
#include <iostream>
using namespace std;

bool allBitsSet(int n)
{
	// edge case
	if (n == 0)
		return false;
	
	while (n > 0) {
		// if last bit isn't set
		if ((n & 1) == 0)
			return false;
		// truncate LSB
		n = n >> 1;
	}
	// all bits set (confirmed)
	return true;
}

bool isPrime(int n)
{
    // edge case
    if (n <= 1)
        return false;
        
    // general case (works for n>=4)
    for (int i = 2; i*i<=n; i++)
        if (n%i==0)
            return false;
    
    // prime confirmed        
    return true;
}
// Driver function
int main(void)
{
    // input
	int n;
	cin>>n;
	// n = mersenne iff n==prime and n==2^k-1, k>=2
  // logic : numbers of the form 2^k-1 have all bits set(==1) in binary
	if(isPrime(n) && allBitsSet(n))
	    cout<<n<<" is a Mersenne Prime";
	else
	    cout<<n<<" isn't a Mersenne Prime";
	return 0;
}
