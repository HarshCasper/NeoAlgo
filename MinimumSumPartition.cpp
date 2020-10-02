#include <iostream>
#include <string>
using namespace std;

// Partition the set S into two subsets S1, S2 such that the
// difference between the sum of elements in S1 and the sum
// of elements in S2 is minimized
int minPartition(int S[], int n, int S1, int S2)
{
	// base case: if list becomes empty, return the absolute
	// difference between two sets
	if (n < 0)
		return abs(S1 - S2);

	// Case 1. include current item in the subset S1 and recur
	// for remaining items (n - 1)
	int inc = minPartition(S, n - 1, S1 + S[n], S2);

	// Case 2. exclude current item from subset S1 and recur for
	// remaining items (n - 1)
	int exc = minPartition(S, n - 1, S1, S2 + S[n]);

	return min (inc, exc);
}

int main()
{
	// Input: set of items
	int S[] = { 10, 20, 15, 5, 25};

	// number of items
	int n = sizeof(S) / sizeof(S[0]);

	cout << "The minimum difference is " << minPartition(S, n - 1, 0, 0);

	return 0;
}
