/* 
 Chinese Remainder Theorem-
 	We are given n numbers which are pairwise coprime and given remainders of
	these numbers when an unknown number x is divided by them. We need to find
        the minimum possible value of x that produces given remainders.
	
	n is size of num[] and rem[]. Returns the smallest
	number x such that:
	x % num[0] = rem[0],
	x % num[1] = rem[1],
	..................
	x % num[k-2] = rem[k-1]
*/

#include<iostream>
using namespace std;

// Using extended Euclid Algorithm to return modulo inverse 
int inverse(int x, int y)
{
	int m0 = y, t, q;
	int x0 = 0, x1 = 1;

	if (y == 1)
		return 0;

	// Apply extended Euclid Algorithm
	while (x > 1) {
		q = x / y;
		t = y;

		// y is remainder now, process same as
		// euclid's algo
		y = x % y, x = t;
		t = x0;
		x0 = x1 - q * x0;
		x1 = t;
	}

	if (x1 < 0)
		x1 += m0;

	return x1;
}
 
int findMinX(int num[], int rem[], int n)
{
	// Compute product of all numbers
	int product = 1;
	for (int i = 0; i < n; i++)
		product *= num[i];

	// Initialize result
	int result = 0;

	// Apply above formula
	for (int i = 0; i < n; i++) {
		int temp = product / num[i];
		result += rem[i] * inverse(temp, num[i]) * temp;
	}

	return result % product;
}

// Main function
int main(void)
{
	int n;
	//Taking Input from user
	cout<<"How many numbers you want to enter: ";
	cin>>n;
	int num[n],rem[n];
	
	cout<<"Enter the numbers: ";
	for(int i=0;i<n;i++)
		cin>>num[i];
	cout<<"\nEnter the remainders: ";
	for(int i=0;i<n;i++)
		cin>>rem[i];
		
	//Calling the function for Chinese Remainder Theorem
	cout << "x is " << findMinX(num, rem, n);
	return 0;
}

/*
	Sammple Input:-
	n= 3
	num[]= 3 5 7
	rem[]= 2 3 2
	Sample Output:-
	x is 23
	
	Sample Input:-
	n= 4
	num[]= 2 3 5 17
	rem[]= 1 2 3 5
	Sample Output:-
	x is 413
*/
/*
	Time Complexity- O(n*log(n))
	Space Complexity-O(1) 
*/
