//Power Set Using Bitwise

#include <bits/stdc++.h>
using namespace std;

void printPowerSet(string str)
{
	int n = str.length();

	int powSize = pow(2, n);

	for(int counter = 0; counter < powSize; counter++)
	{
		for(int j = 0; j < n; j++)
		{
			if((counter & (1 << j)) != 0)
                cout<<str[j];
		}
		
		cout<<endl;
	}
}

int main() {
	
	string s ;
	cin>>s;

    printPowerSet(s);     
}

/*
Time Complexity: O(n2^n)
Space Complexity: O(1)
*/
/*Sample Input:
Example 1:- abc
Example 2:- pqrst

Sample Output:
Example 1:-
a
b
ab
c
ac
bc
abc 
Example 2:-
p
q
pq
r
pr
qr
pqr
s
ps
qs
pqs
rs
prs
qrs
pqrs
t
pt
qt
pqt
rt
prt
qrt
pqrt
st
pst
qst
pqst
rst
prst
qrst
pqrst
*/

