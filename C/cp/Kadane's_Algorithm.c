#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


int main(void) {
    
	// Aceepting an array 
	int n;
	printf("Enter number of elemets in array \n");
	scanf (" %d ", &n);
	
	int arr[n];
	printf("Enter elemets of array \n");
	for (int i = 0; i < n; i++ ){
	    scanf(" %d ", &arr[i]);
	}
	
	//KADANE'S ALGORITHM
	int max_sum  = arr[0];
	int curr_max = arr[0];
	for (int i = 1; i < n; i++ ){
	    curr_max = MAX(arr[i], arr[i] + curr_max);
	    max_sum = MAX(curr_max, max_sum);
	}
	
	printf("Maximum sum of subarray is %d \n", max_sum);
	
	
	return 0;
}

/*
TEST CASE 

INPUT
Enter number of elemets in array 4
Enter elemets of array  2 -3 4 6 

OUTPUT
Maximum sum of subarray is 10 


INPUT
Enter number of elemets in array 4
Enter elemets of array  2 3 4 6 

OUTPUT
Maximum sum of subarray is 15 
*/

