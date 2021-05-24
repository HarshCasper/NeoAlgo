/*
Toggle kth bit from the right.
i.e. For a given number n, if k-th bit from right is 0, then toggle it to 1
and if it is 1 then, toggle it to 0.
*/

#include <iostream>
using namespace std;

int main() {
	int n, k;
	//n=integer
	cin >> n >> k;
	int ans = (n ^ (1 << (k - 1)));
	cout << ans;
	return 0;
}


/*
  input:
  6 2
  ouput:
  4
  constraint:
  n is positive
*/

/*
  time-complexity: O(1)
*/
