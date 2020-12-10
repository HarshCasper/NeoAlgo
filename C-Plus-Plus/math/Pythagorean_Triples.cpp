//C++ program to generate all Pythagorean Triples for a given limit 
#include <bits/stdc++.h>
using namespace std;

//Function for generating Pythagorean triples
void GetTriples(int limit)
{
	int a = 0, b = 0, c = 0;	// A triple: a^2 + b^2 = c^2
	int m = 2;

	//Limiting condition for c autonomatically limits a, b and c
	while (c < limit)
	{
		n = 1;

		//Looping over values of n
		while (n < m)
		{
			a = (m * m) - (n * n);	//Evaluating triples using the relation between a,b,c and m,n
			b = 2 * m * n;
			c = (m * m) + (n * n);

			if (c > limit)
				break;

			cout << a << " " << b << " " << c << "\n";	//Printing Triples
			n++;
		}

		m++;
	}
}

//DRIVER FUNCTION
int main()
{
	int limit;
	cout << "Enter a limit: ";	//Promt user to enter limit
	cin >> limit;
	GetTriples(limit);
	return 0;
}

/*
SAMPLE I/O:
Enter a limit: 20
3 4 5
8 6 10
5 12 13
15 8 17
12 16 20

TIME COMPLEXITY: O(k), where k = number of Triples printed
SPACE COMPLEXITY: O(1)
*/