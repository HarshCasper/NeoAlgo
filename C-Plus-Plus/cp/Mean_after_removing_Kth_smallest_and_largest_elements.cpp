/* Program Statement: Given an array, and a percent K, we need to find out the mean of the remaining elements in the array after removing
                     K-th percent smallest and greatest numbers from it.
Approach used: After sorting the given array, find the K-th percent of the size of the array, then add the elements with the index numbers K% to(n-1)-K%.
               Ultimately we find the mean of those elements added.
Time Complexity: O(n log n)
Space Complexity: O(n) */

#include <bits/stdc++.h>
using namespace std;

/* Function to find out the K-th percent and then eventually the mean */
void solve(int a[], int n, int k)
{
	/* Sorting the array */
	sort(a, a + n);

	/* Finding the K-th percent */
	int kth_percent = (n * k) / 100;
	float s = 0;

	/* Storing the remaining elements in the array
	after removing the largest and smallest K-th percent number in the array */
	for (int i = 0; i < n; i++)
		if (i >= kth_percent && i < (n - kth_percent))
			s = s + a[i];

	/* Calculating the mean */
	float m = s / (n - 2 * kth_percent);

	/* The mean would be printed upto 3 decimal places  */
	cout << fixed << setprecision(3) << m << endl;
}

/* Main Function */
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*Taking the number of test cases as input*/
    int tc;
    cin >> tc;
    while(tc--)
    {
    /* The size of the array and the K-th percent is being taken as input */
    int n,k;
    cout << "Enter the size of the array " << endl;
	cin >> n;
	cout << "Enter the K-th percent " << endl;
	cin >> k;

    /* Taking the array values as input */
    int a[n];
    cout << "Enter the array values " << endl;
	for(int i = 0; i < n; i++)
        cin >> a[i];

    /*Calling the function solve() to calculate the mean */
	solve(a, n, k);

    }

	return 0;
}

/* A Sample test case for the above problem

Input:
1
Enter the size of the array
5
Enter the K-th percent
20
Enter the array values
1
2
3
4
5

Output:
3.000
*/
