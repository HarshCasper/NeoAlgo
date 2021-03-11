/*
Author: Mohit Singh

Seive of eratosthenes is an simple algorithm to find all the numbers which are prime numbers within a range 1 to N , given N.
It involves methodically eliminating the numbers that are know not to be prime until only the prime numbers remain.
Begin by crossing out one as it is not a prime number (it does not have two factors, it is a square number). 
Two is a prime number but all of its multiples a not (they are composite numbers) so cross out all of the multiples of two but leave two as the first prime number. 
Next cross out all of the multiples of three except three itself. The number four and all of its multiples have already been crossed out as they are also multiples of two. 
Next cross out all the multiples of five except five itself. Continue this process until you have discovered as many prime numbers as you need.
So in this by crossing out the non-prime numbers within a range 1 to N, we are only left with the prime numbers.

*/
#include <bits/stdc++.h>
using namespace std;


//printing the prime array
void print_array(bool prime_array[] , int n)
{
	for (int i = 2; i <= n; i++)
		if (!prime_array[i])
			cout << i << " ";
}


void SieveOfEratosthenes(bool prime_array[] , int n)
{

	for (int i = 2; i <= sqrt(n); i++)
	{
		// If prime_array[i] is still false, 
		// then it is a prime number
		if (!prime_array[i]) 
		{
			// Then we update all multiples of i 
			// greater than or equal to
			// the square of it
			// numbers which are multiple 
			// of i and are less than i*i 
			// are already been marked.
			for (int j = i * i; j <= n; j += i)
				prime_array[j] = true;
		}
	}
	
	print_array(prime_array , n);

}

// Driver Code
int main()
{
	int n;
	
	cout << "Enter N of range 1 to N : ";
	cin >> n;
	
	bool prime_array[n+1]; //we create an boolean prime_array and initialize the array with all the entries being false.
	memset(prime_array, false, sizeof(prime_array)); //the array is initialized to false for every entries.
	
	cout << "Following are the prime numbers smaller "
		<< " than or equal to " << n << endl;
		
	SieveOfEratosthenes(prime_array , n);
	
	return 0;
}


/*
Time complexity : O(n*log(log(n))) 

Input 
Enter N of range 1 to N : 20

Output
Following are the prime numbers smaller  than or equal to 20
2 3 5 7 11 13 17 19     

Input
Enter N of range 1 to N : 45

Output
Following are the prime numbers smaller  than or equal to 45
2 3 5 7 11 13 17 19 23 29 31 37 41 43

*/

