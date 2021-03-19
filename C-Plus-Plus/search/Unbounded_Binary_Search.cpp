/*
Given a function ‘int f(unsigned int x)’ which takes a non-negative integer ‘x’ 
as input and returns an integer as output. The function is monotonically increasing 
with respect to value of x, i.e., the value of f(x+1) is greater than f(x) for every 
input x. Find the value ‘n’ where f() becomes positive for the first time.
Since f() is monotonically increasing, values of f(n+1), f(n+2),… must be positive and 
values of f(n-2), f(n-3), .. must be negative.
*/
#include<bits/stdc++.h> 
using namespace std; 

int binarySearch(int low, int high); 

// Let's take an example function 
// f(x) = x^2 - 10*x - 20 
int function(int x) 
{ 
	return (x*x - 10*x - 20);
} 

int findFirstPositive() 
{ 
	if (function(0) > 0) 
		return 0; 

	int i = 1; 
	while (function(i) <= 0) 
		i = i*2; 

	return binarySearch(i/2, i); 
} 

int binarySearch(int low, int high) 
{ 
	if (high >= low) 
	{ 
		int mid = low + (high - low)/2;

		if (function(mid) > 0 && (mid == low || function(mid-1) <= 0)) 
			return mid; 

		if (function(mid) <= 0) 
			return binarySearch((mid + 1), high); 
		else 
			return binarySearch(low, (mid -1)); 
	} 
	return -1; 
} 
/* Driver code */
int main() 
{ 
	cout<<"The value n where function() becomes positive first is "<< findFirstPositive(); 
	return 0; 
} 
/*
SAMPLE OUTPUT:

Input : x^2 - 10*x - 20
Output : The value n where function() becomes positive first is 12

Time Conplexity:O(log n)
Space Complexity:O(1)
*/

