/*Problem Statement :
Find the only non repeating element in array where every element repeats twice.*/
/*We use the property of XOR that two same elements when xored gives  0 i.e.
a^a =0*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	int res = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		res = (res ^ a[i]);
	}
	cout << res << '\n';
	return 0;
}
/*Input :
No of integers in array : n
Array of integers : a[n]

Example :
7
5 4 1 4 3 5 1

Output :
3
Time Complexity : O(n)
Space Complexity : O (n)*/
