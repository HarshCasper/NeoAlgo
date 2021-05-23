/*
	Brian Kernighan’s Algorithm: To get the number of set bits
	For eg :- 5 can be represented as 101 number of set bits are 2
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"Enter number \n";
	cin>>n;
	int c=0;
	while (n) {
            n &= (n - 1);
            c++;
        }
        cout<< c;
}

/*
Time Complexity: O(logn)
Space Complexity: O(1)
*/

/*Sample Input:
	Example 1:- 
	Enter number
	5
	Example 2:-
	Enter number
	987

	Sample Output:
	Example 1:- 2
	Example 2:- 8
*/

