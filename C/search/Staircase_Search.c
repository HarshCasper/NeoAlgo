/*
Staircase Search is used to search for a key in a 2D Array whose row and column elements are sorted.
	* The idea is to remove a row or a column in each comparison until an element is found. 
	* Searching is started from the top-right corner of the matrix and has three possible cases: 
		1. The key is greater than the current element, this means, that all the elements in the current row are smaller than the key.
       So, the row can be skipped and move to next row.
		2. The key is smaller than the current number, this means, that all the elements in the current column are greater than the key.
       So, the column can be skipped and move to previous column.
		3. The key is equal to the current number, this means, the key is found.
	* If the bounds of the 2D Array are reached, this means, the key is not found.
*/

#include<stdio.h>     
#include<stdlib.h>    

void staircase_search(int** matrix, int n, int m, int key) {

	int is_found=0;
	// Start from top right corner
	int i = 0, j = m - 1;

	// To search for a element until the indices satisfy the matrix bounds
	while (i <= n - 1 && j >= 0) {

		if (matrix[i][j] == key) {

			// If key is found
			printf("Element fouund at : %d %d\n",i,j);
			is_found = 1;
			break;

		} else if (matrix[i][j] > key) {

			// If current element is greater than the key, then the current column can be skipped and move to previous column
			j--;

		} else {

			// If current element is lesser than th key, then the current row can be skipped and move to next row
			i++;

		}

	}

	// If the element is not found
	if (!is_found)
		printf("Element not found\n");
}


int main() {

	// Take in input
	int n, m,ele,i,j;
	printf("Enter the dimensions of the array: ");
	scanf("%d %d",&n,&m);
  
	printf("Enter the element to be searched: ");
	scanf("%d",&ele);
	
  // Declare 2D Matrix dynamically
	int** a = (int **)malloc(n*sizeof(int *));
	for (i = 0; i < n; i++) {
		a[i] = (int *)malloc(m*sizeof(int));
	}
  printf("Enter the elements of the array: \n";
	// Take matrix input
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d",&a[i][j]);
		}
	}
  //Function to search the element
	staircase_search(a, n, m, ele);
}

/*
Input:
Enter the dimensions of the array: 5 5
Enter the element to be searched: 20
Enter the elements of te array: 
1 4 8 10 45
2 5 9 15 55
6 16 18 20 12
7 14 21 27 11
11 17 19 23 19
Output:
2 3
*/

/*
Time Complexity: O(max(n, m))
Auxiliary Space: O(1)
*/
