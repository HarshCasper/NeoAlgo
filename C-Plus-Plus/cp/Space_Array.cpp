/* PROBLEM LINK: https://www.codechef.com/MARCH21C/problems/SPACEARR
*/

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
				c = 1;                    // true, increase value of c  i.e. count
				break;
			}
			sum += abs(arr[i] - (i + 1));    //if not,take the sum of difference of index and array at that index.
		}
		if (c == 1)                             //c is 1 i.e. arrayy is greater than element of array
			cout << "Second" << endl;        //second player wins.
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

/*Time complexity: 0.06 sec using above algo, "MAX time complexity can be 1 sec "
Memory used: 6.5 MB uisng above algo, MAx space complexity for his problem is: 50000 Bytes"
*/


