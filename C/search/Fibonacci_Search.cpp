
// C program implementation for Fibonacci Search 


#include <stdio.h> 

//function to find minimum of two elements 
int min(int x, int y) 
{ 
	return (x<=y)? x : y; 
} 

//Returns index of x if present, else returns -1 
int Fibonacci_Search(int arr[], int x, int n) 
{ 
	// Initialize fibonacci numbers
	int Fib_no_2 = 0; 
	int Fib_no_1 = 1; 
	int Fib_no = Fib_no_2 + Fib_no_1; 

	/* Fib_no is going to store the smallest Fibonacci 
	Number greater than or equal to n */
	while (Fib_no < n) 
	{ 
		Fib_no_2 = Fib_no_1; 
		Fib_no_1 = Fib_no; 
		Fib_no = Fib_no_2 + Fib_no_1; 
	} 

	int offset = -1; 

	while (Fib_no > 1) 
	{ 
		int i = min(offset+Fib_no_2, n-1); 

		/* If x is greater than the value at index Fib_nom2, 
		cut the subarray array from offset to i */
		if (arr[i] < x) 
		{ 
			Fib_no = Fib_no_1; 
			Fib_no_1 = Fib_no_2; 
			Fib_no_2 = Fib_no - Fib_no_1; 
			offset = i; 
		} 

		/* If x is greater than the value at index Fib_nom2, 
		cut the subarray after i+1 */
		else if (arr[i] > x) 
		{ 
			Fib_no = Fib_no_2; 
			Fib_no_1 = Fib_no_1 - Fib_no_2; 
			Fib_no_2 = Fib_no - Fib_no_1; 
		} 

		// return index 
		else
		 return i; 
	} 

	/* comparing the last element with x */
	if(Fib_no_1 && arr[offset+1]==x)return offset+1; 

	//element not found
	return -1; 
} 

// The Main function 
int main(void) 
{ 
	int no_element=0;
	int x;
	printf("Enter the no of element in the array: "); 
    scanf("%d", &no_element);
	int arr[no_element];

	// taking input 
	printf("Enter the array: \n"); 
	for(int z=0; z < no_element; z++){
		scanf("%d", &arr[z]);
	}
	printf("Enter the no for searching: "); 
	scanf("%d", &x);
	
	int n = sizeof(arr)/sizeof(arr[0]); 
	
	(-1 == Fibonacci_Search(arr, x, n)) ? printf("Not Found") : 
	printf("Found the number at index: %d", Fibonacci_Search(arr, x, n));
	
	return 0; 
} 
