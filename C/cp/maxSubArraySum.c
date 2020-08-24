#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))


int main(void) {
    
	// Aceepting an array 
	int size;
	printf("Enter the size of the array ");
	scanf ("%d", &size);
	
	printf("Enter elements of array \n");
	int arr[size];
	for (int index = 0; index < size; index++ ){
	    scanf("%d", &arr[index]);
	}
	
	//KADANE'S ALGORITHM
	int max_sum  = arr[0];
	int curr_max = arr[0];
	for (int index = 1; index < size; index++ ){
	    curr_max = MAX(arr[index], arr[index] + curr_max);
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

