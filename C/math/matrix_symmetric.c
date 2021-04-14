/*
Matrix is a 2-D Array.
A Symmetric Matrix is a square matrix that is equal to its Transpose.
The code gives output as it checks whether the matrix is symmetric or not.
*/
#include<stdio.h>
#include<stdlib.h>

int main(){
	int row,column,i,j,flag=0;
	int **matrix;
	printf("Enter number of rows of matrix:");
    scanf("%d",&row);
    printf("Enter number of coloumns of matrix:");
    scanf("%d",&column);
    //checking whether the given matrix is square matrix or not
    if(row == column){
        matrix = (int **)malloc(row * sizeof(int *));
        for(i = 0; i < row; i++)
            matrix[i] = (int *)malloc(column * sizeof(int));
        //enter the value of matrices
        printf("Enter matrix:\n");
        for(i = 0; i < row; i++)
            for(j = 0; j < column; j++)
              scanf("%d",&matrix[i][j]);
        for (i = 0; i < row; i++){
            for (j = 0; j < column; j++){
      		     if (matrix[i][j] != matrix[j][i]){
      		         flag = 1;
                     break;
      		     }
            }
            if( flag == 1)
                break;
        }
        if(flag == 1)
            printf("The matrix isn't symmetric.\n");
        else
            printf("The matrix is symmetric.\n");
    }
    else
        printf("The matrix is not square symmetric.\n");
  return 0;
}

/*

Sample Output:

Enter number of rows of matrix:2
Enter number of coloumns of matrix:2

Enter matrix:
1  2
2  1

The matrix is symmetric.

Time Complexity : O(mn)
Space Complexity : O(mn)
where,
       m = number of rows
       n = number of columns
*/
