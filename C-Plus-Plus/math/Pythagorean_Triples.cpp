//C++ Program to generate Pythagorean Triples within a user-given limit
#include <bits/stdc++.h>
using namespace std;

//Function for computing Pythagorean Triples
void GetTriples(int& l)
{
	//Starting values of m=2, n=1 are mapped to a=3, b=4, c=5, which is the smallest Pythagorean triple
	int a = 0, b = 0, c = 0, m = 2, n = 1;

	while (c < l)
	{
		//For every m, evaluate a,b,c for all values of n from 1 to m-1
		n = 1;	
		while (n < m)
		{
			//Evaluating a, b, c using relation between a,b,c and m,n
			a = (int)(pow(m, 2)) - (int)(pow(n, 2));
			b = 2 *m * n;
			c = (int)(pow(m, 2)) + (int)(pow(n, 2));

			//Checking for limit being exceeded
			if (c > l)	
				break;

			//Display computed Triple
			cout << a << " " << b << " " << c << "\n";
			n++;
		}

		m++;
	}
}

//Driver function
int main()
{
	int l;
	//Prompts user for input
	cout << "Enter limit (>4) :";
	cin >> l;
	GetTriples(l);
	return 0;
}

/*
Sample I/O:
Enter limit: 30
3 4 5
8 6 10
5 12 13
15 8 17
12 16 20
7 24 25
24 10 26
21 20 29

Time Complexity - O(k)[k = number of triples generated]
Space Complexity - O(1)

References: https://youtu.be/n6vL2KiWrD4
*/