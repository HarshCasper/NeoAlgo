// MOs ALgorithm is used for Square root decomposition
// Square root decomposition is a method or a data structure, 
// which allows you to perform some typical operations 
// (summation of subarray, range minimum/maximum query, etc.) 
// in O(n ^ 1/2) time complexity, what is significantly better than O(n) when using trivial algorithm.





//**************** First is this Naive Solution *******************
//run a loop from L to R and calculate the sum of elements in given range for every query [L, R]



// Program to compute sum of ranges for different range queries.
#include <bits/stdc++.h>
using namespace std;

// Structure to represent a query range
struct Query
{
	int L, R;
};

// Prints sum of all query ranges. m is number of queries
// n is the size of the array.
void printQuerySums(int a[], int n, Query q[], int m)
{
	// One by one compute sum of all queries
	for (int i=0; i<m; i++)
	{
		// Left and right boundaries of current range
		int L = q[i].L, R = q[i].R;

		// Compute sum of current query range
		int sum = 0;
		for (int j=L; j<=R; j++)
			sum += a[j];

		// Print sum of current query range
		cout << "Sum of [" << L << ", "
			<< R << "] is " << sum << endl;
	}
}

// Driver program
int main()
{
	int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
	int n = sizeof(a)/sizeof(a[0]);
	Query q[] = {{0, 4}, {1, 3}, {2, 4}};
	int m = sizeof(q)/sizeof(q[0]);
	printQuerySums(a, n, q, m);
	return 0;
}


//Example I/P or O/P

// Input:  arr[]   = {1, 1, 2, 1, 3, 4, 5, 2, 8};
//         query[] = [0, 4], [1, 3] [2, 4]

//   Output:       Sum of [0, 4] is 8
//                 Sum of [1, 3] is 4
//                 Sum of [2, 4] is 6

// Time Complexity : O(mn).









//**************************Optimised Solution************************************


// Program to compute sum of ranges for different range
// queries
// #include <bits/stdc++.h>
// using namespace std;

// // Variable to represent block size. This is made global
// // so compare() of sort can use it.
// int block;

// // Structure to represent a query range
// struct Query
// {
// 	int L, R;
// };

// // Function used to sort all queries so that all queries 
// // of the same block are arranged together and within a block,
// // queries are sorted in increasing order of R values.
// bool compare(Query x, Query y)
// {
// 	// Different blocks, sort by block.
// 	if (x.L/block != y.L/block)
// 		return x.L/block < y.L/block;

// 	// Same block, sort by R value
// 	return x.R < y.R;
// }

// // Prints sum of all query ranges. m is number of queries
// // n is size of array a[].
// void queryResults(int a[], int n, Query q[], int m)
// {
// 	// Find block size
// 	block = (int)sqrt(n);

// 	// Sort all queries so that queries of same blocks
// 	// are arranged together.
// 	sort(q, q + m, compare);

// 	// Initialize current L, current R and current sum
// 	int currL = 0, currR = 0;
// 	int currSum = 0;

// 	// Traverse through all queries
// 	for (int i=0; i<m; i++)
// 	{
// 		// L and R values of current range
// 		int L = q[i].L, R = q[i].R;

// 		// Remove extra elements of previous range. For
// 		// example if previous range is [0, 3] and current
// 		// range is [2, 5], then a[0] and a[1] are subtracted
// 		while (currL < L)
// 		{
// 			currSum -= a[currL];
// 			currL++;
// 		}

// 		// Add Elements of current Range
// 		while (currL > L)
// 		{
// 			currSum += a[currL-1];
// 			currL--;
// 		}
// 		while (currR <= R)
// 		{
// 			currSum += a[currR];
// 			currR++;
// 		}

// 		// Remove elements of previous range. For example
// 		// when previous range is [0, 10] and current range
// 		// is [3, 8], then a[9] and a[10] are subtracted
// 		while (currR > R+1)
// 		{
// 			currSum -= a[currR-1];
// 			currR--;
// 		}

// 		// Print sum of current range
// 		cout << "Sum of [" << L << ", " << R
// 			<< "] is " << currSum << endl;
// 	}
// }

// // Driver program
// int main()
// {
// 	int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
// 	int n = sizeof(a)/sizeof(a[0]);
// 	Query q[] = {{0, 4}, {1, 3}, {2, 4}};
// 	int m = sizeof(q)/sizeof(q[0]);
// 	queryResults(a, n, q, m);
// 	return 0;
// }



// Time Complexity : Processing all queries takes O(n * √n) + O(m * √n) = O((m+n) * √n) time.

