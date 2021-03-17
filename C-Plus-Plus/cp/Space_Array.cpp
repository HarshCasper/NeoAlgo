/*
The rules of the game are as follows:

1-Initially, a sequence a1,a2,…,aN is given.
2-The players alternate turns.
3-In each turn, the current player must choose
an index i and increment ai, i.e. change ai to ai+1.
4-Afterwards, if there is no permutation p1,p2,…,pN of the
integers 1 through N such that ai=pi holds for each valid
 i, the current player loses.
5-Otherwise, the game continues with the next turn.
*/

/*
Input:
The first line of the input contains a single integer T denoting the number of test cases.
The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers a1,a2,…,aN.
Output:
For each test case, print a single line containing the string "First"
if the first player wins or "Second"
if the second player wins (without quotes).*/

/*
Constraints
1=T=2·104
1=N=2·105
The sum of N over all test cases doesn't exceed 2·105
1=ai=N for each valid i
*/

// Code
#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;  //No of test Cases.
	cin >> t;
	while (t--) {
		int n;      // No of elements in array
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)            // i as Index of Array
			cin >> arr[i];

		sort(arr, arr + n);                   //Sorting the Array
		int sum = 0, c = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] > (i + 1)) {           //Cheking if index is graeter or less than element of array  at that position
				c = 1;
				break;
			}
			sum += abs(arr[i] - (i + 1));
		}
		if (c == 1)
			cout << "Second" << endl;
		else {
			if (sum % 2 == 0)                  // if sum is even.
				cout << "Second" << endl;      // second is winner.
			else
				cout << "First" << endl;       // otherwise first will win.
		}
	}
	return 0;
}

/*
Example Input
4
4
1 2 3 3
4
1 1 3 3
5
1 2 2 1 5
3
2 2 3
Example Output
First
Second
Second
Second
*/

/*
Explanation:
if array at that index is greater than the array then Second Player will be the winner.
if not the we will take the sum of difference of index and array at that index.
sum will be odd then first will win otherwise second will win
*/
