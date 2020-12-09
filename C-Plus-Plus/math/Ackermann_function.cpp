#include<bits/stdc++.h>
using namespace std;
int Ackermann_Function(int m, int n) {
	if (m == 0)
		return n + 1;

	else if (m > 0 && n == 0)
		return Ackermann_Function(m - 1, 1);

	else if (m > 0 && n > 0)
		return Ackermann_Function(m - 1, Ackermann_Function(m, n - 1));
}

int main() {
	int m, n;
	cin >> m >> n;
	cout << Ackermann_Function(m, n);
	return 0;
}

/*
time complexity:-O(mA(m, n)) to compute A(m, n)
space complexity:- O(m) to compute A(m, n)
Examples:-
m=1,n=2
output=4
m=3,n=3
output=61
*/
