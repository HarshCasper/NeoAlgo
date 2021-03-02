/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Sample case 1:

	Input:

	Enter Rows:2
	Enter Column: 2
	1
	2
	3
	4

	Output:

	Entered Matrix:
	1 2 
	3 4

	Spiral Order of the Matrix: 1 2 4 3

Sample Case 2:

	Input:

	Enter Rows:2
	Enter Column: 2
	0
	0
	0
	0

	Output:

	Null Matrix

Time Complexity: O(ROW*COLUMN)
Space Complexity:O(1).
*/
#include <stdio.h> 
int main() 
{ 
	int ROW, COLUMN, is_null = 0;

	printf("Enter Row: ");
	scanf("%d",&ROW);

	printf("Enter column: ");
	scanf("%d",&COLUMN);

	int matrix[ROW][COLUMN];

	for(int i=0; i < ROW; i++)
	{
		for(int j = 0; j  <COLUMN; j++)
		{
			scanf("%d",&matrix[i][j]);
			if(matrix[i][j] == 0)
				is_null++;
		}
	}
	if(is_null == ROW*COLUMN)
	{
		printf("\nNull Matrix\n");
	}
	else
	{
		printf("Entered Matrix:\n");
		for(int i = 0; i < ROW; i++)
		{
			printf("\n");
			for(int j = 0; j < COLUMN; j++)
			{
		
				printf("%d",matrix[i][j]);
				printf("\t");
			}
		}
		printf("\n\nSpiral Order Of the Matrix: \t");
		int i;
		int first_row = 0, first_column = 0;

		while (first_row < ROW && first_column < COLUMN)
		{ 
			/* Print the first row from the remaining rows */
			for (i = first_column;  i < COLUMN; ++i) 
			{ 
				printf("%d ", matrix[first_row][i]); 
			} 
			first_row++; 

			/* Print the last column from the remaining columns */
			for (i = first_row; i < ROW; ++i) 
			{ 
				printf("%d ", matrix[i][COLUMN - 1]); 
			} 
			COLUMN--; 

			/* Print the last row from the remaining rows */
			if (first_row < ROW) 
			{ 
				for (i = COLUMN - 1; i >= first_column; --i) 
				{ 
					printf("%d ", matrix[ROW - 1][i]); 
				} 
				ROW--; 
			} 

			/* Print the first column from the remaining columns */
			if (first_column < COLUMN) 
			{ 
				for (i = ROW - 1; i >= first_row; --i) 
				{ 
					printf("%d ", matrix[i][first_column]); 
				} 
				first_column++; 
			} 
		} 
	}

	return 0; 
} 
