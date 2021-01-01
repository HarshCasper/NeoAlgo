// C++ program to count all distinct binary strings 
// without two consecutive 1's 

#include <iostream> 
using namespace std; 

int FxnCount(int n) 
{ 
	//A dynamic programming approach
	int arr1[n], arr2[n]; 
	arr1[0] = arr2[0] = 1; 
	for (int i = 1; i < n; i++) 
	{ 
		arr1[i] = arr1[i-1] + arr2[i-1]; 
		arr2[i] = arr1[i-1]; 
	} 
	return arr1[n-1] + arr2[n-1]; 
} 


// Main program
int main() 
{ 
	int n = 2;
	cout << FxnCount(n) << endl; 
	return 0; 
}

/*
Input - 2
Output - 3

 3 strings are
(00,01,10).

Time Complexity- O(n)
Space Complexity- O(n)
*/
