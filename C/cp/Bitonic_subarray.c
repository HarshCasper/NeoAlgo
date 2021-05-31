#include<stdio.h>
#include<stdlib.h>
 
int bitonic(int *arr, int n)
{
    int inc[n]; // Length of increasing subarray ending at all indexes
    int dec[n]; // Length of decreasing subarray starting at all indexes
    int i, max;
 
    // length of increasing sequence ending at first index is 1
    inc[0] = 1;
 
    // length of increasing sequence starting at first index is 1
    dec[n-1] = 1;
 
    // Step 1) Construct increasing sequence array
    for (i = 1; i < n; i++)
       inc[i] = (arr[i] >= arr[i-1])? inc[i-1] + 1: 1;
 
    // Step 2) Construct decreasing sequence array
    for (i = n-2; i >= 0; i--)
       dec[i] = (arr[i] >= arr[i+1])? dec[i+1] + 1: 1;
 
    // Step 3) Find the length of maximum length bitonic sequence
    max = inc[0] + dec[0] - 1;
    for (i = 1; i < n; i++)
        if (inc[i] + dec[i] - 1 > max)
            max = inc[i] + dec[i] - 1;
 
    return max;
}
 

int main()
{
    int i,NoOfElements;
	int *A;
	printf("How many elements? Enter the size: ");
	scanf("%d",&NoOfElements);

	A=(int*)malloc(NoOfElements*sizeof(int));

	if(A==NULL){
		printf("ERROR: MEMORY ALLOCATION FAIL\n");
		return 1;
	}
	printf("Enter %d elements",NoOfElements);
	for (i=0; i<NoOfElements; ++i){
		scanf("%d",&A[i]);
	}

	printf("Array elements are:\n");
	for(i=0;i < NoOfElements;i++){
		printf("%d\n",A[i]);
    }
    int n = sizeof(A)/sizeof(A[0]);
    printf("nLength of max length Bitnoic Subarray is %d",
            bitonic(A, n));
    return 0;
}

