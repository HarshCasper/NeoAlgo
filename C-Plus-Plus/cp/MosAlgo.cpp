#include <bits/stdc++.h>
using namespace std;

int block;

struct Query
{
	int L, R;
};
bool compare(Query x, Query y)
{
	
	if (x.L/block != y.L/block)
		return x.L/block < y.L/block;

	
	return x.R < y.R;
}

void queryResults(int a[], int n, Query q[], int m)
{
	
	block = (int)sqrt(n);

	
	sort(q, q + m, compare);

	int currL = 0, currR = 0;
	int currSum = 0;

	
	for (int i=0; i<m; i++)
	{
		
		int L = q[i].L, R = q[i].R;
		while (currL < L)
		{
			currSum -= a[currL];
			currL++;
		}
		while (currL > L)
		{
			currSum += a[currL-1];
			currL--;
		}
		while (currR <= R)
		{
			currSum += a[currR];
			currR++;
		}

		while (currR > R+1)
		{
			currSum -= a[currR-1];
			currR--;
		}

		cout << "Sum of [" << L << ", " << R
			<< "] is " << currSum << endl;
	}
}

int main()
{
	int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
	int n = sizeof(a)/sizeof(a[0]);
	Query q[] = {{0, 4}, {1, 3}, {2, 4}};
	int m = sizeof(q)/sizeof(q[0]);
	queryResults(a, n, q, m);
	return 0;
}

// O(m * √n)

// O/P : Sum of [1, 3] is 4
// Sum of [0, 4] is 8
// Sum of [2, 4] is 6



// Some other examples:
// I/P:
// Arr = [0, 1, 1, 0, 2, 3, 4, 1, 3, 5, 1, 5, 3, 5, 4, 0, 2, 2] of 18 elements
// Queries (0-indexed): [0, 8], [2, 5], [2, 11], [16, 17], [13, 14], [1, 17], [17, 17]

// O/P:
// 27
// 6
// 47
// 8
// 9
// 122
// 2
