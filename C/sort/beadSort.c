/* Bead sort, also called as gravity sort, is a natural sorting algorithm since this algorithm was inspired
from natural phenomenons and was designed keeping in mind objects(or beads) falling under the influence of gravity.
The bead sort operation can be compared to the manner in which beads slide on parallel poles, such as on an abacus.
However, each pole may have a distinct number of beads. */

#include <stdio.h>
#include <stdlib.h>
#define BEAD(i, k) beads[i * max + k]

void bead_sort(int *arr, int n){
    int max=arr[0],sum,i,k;
	for (i = 1; i < n; i++)
		if (arr[i] > max)
		    max = arr[i];

	// pointer to the first character of string beads
	unsigned char *beads;

	// allocate one block of memory of size (max*n) to first char beads and initialize it to 0
	beads = calloc(1, max * n);

	for (i = 0; i < n; i++){
	    for (k = 0; k < arr[i]; k++){
	        BEAD(i, k) = 1;
	    }

	}

	for (k = 0; k < max; k++) {
		sum=0;
		for (i = 0; i < n; i++) {
			sum = sum + BEAD(i, k);
			BEAD(i, k) = 0;
		}
		for (i = n - sum; i < n; i++)
		    BEAD(i, k) = 1;
	}

	for (i = 0; i < n; i++) {
		for (k = 0; k < max && BEAD(i, k); k++);
		arr[i] = k;
	}

	//deallocate the memory allocated to beads
	free(beads);
}

int main(void) {

	int n, i, k;
	printf("Enter the number of elements in the array : ");
	scanf("%d",&n);

	int nums[n];
	printf("Enter the elements of the array : ");
	for(i = 0; i < n; i++){
	    scanf("%d",&nums[i]);
	}
        bead_sort(nums, n);

	printf("The array elements after sorting are : ");
	for (i = 0; i < n; i++)
		printf("%d\n", nums[i]);

	return 0;
}

/*

Input:
Enter the number of elements in the array : 5
Enter the elements of the array : 14 26 43 92 18

Output:
The array elements after sorting are : 14
18
26
43
92

Time Complexities:
Bead sort can be implemented with four general levels of complexity, among others:
O(n): in best case
O(S): in worst case, where S is the sum of all beads

*/
