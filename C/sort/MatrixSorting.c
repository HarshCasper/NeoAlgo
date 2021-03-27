/*Matrix Sort Method
Matrix is sorted in a way such that all elements in a row are sorted in increasing order and for row ‘i’, 
where 1 <= i <= n-1, first element of row 'i' is greater than or equal to the last element of row 'i-1'.
*/
#include <stdio.h>
#include <stdlib.h>

void matrix_sort(int[][10], int, int);
int main()
{
	int ROW, COLUMN;
	printf("Enter Row: ");
	scanf("%d", &ROW);
	printf("Enter Column: ");
	scanf("%d", &COLUMN);
	printf("Enter the elements of Matrix:\n");
	int arr[10][10], i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	matrix_sort(arr, ROW, COLUMN);
	printf("\nSorted Matrix: \n");
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
			printf("%d ", arr[i][j]);
		}

		printf("\n");
	}

	return 0;
}

// Sorting the matrix using matrix sort method
void matrix_sort(int arr[][10], int ROW, int COLUMN)
{
	int i, j, minumum, temp, q, w, minimum, k, z;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
			temp = i;
			q = j;
			minimum = arr[i][j];
			w = j;
			for (k = i; k < ROW; k++)
			{
				for (; w < COLUMN; w++)
				{
					if (arr[k][w] < minimum)
					{
						minimum = arr[k][w];
						z = k;
						q = w;
					}
				}

				w = 0;
			}

			if (arr[z][q] < arr[i][j])
			{
				temp = arr[i][j];
				arr[i][j] = minimum;
				arr[z][q] = temp;
			}
		}
	}
}

/*
Sample Output
Enter Row: 3
Enter Column: 3
Enter the elements of matrix :
7 8 9
5 6 4
3 1 2
Sorted Matrix :
1 2 3
4 5 6
7 8 9

Complexities
Time Complexity: O(n2log2n)
Space Complexity : Auxiliary Space: O(n2)
 */

 