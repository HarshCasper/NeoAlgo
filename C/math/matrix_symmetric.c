/*
Matrix is a 2-D Array.
A Symmetric Matrix is a square matrix that is equal to its Transpose.
The code gives output as it checks whether the matrix is symmetric or not.
*/
#include<stdio.h>
#include<stdlib.h>
//Function to check whether the given matrix is Symmetric or not
void symmetric(int row,int column){
    	int **matrix,flag = 0;
        matrix = (int **)malloc(row * sizeof(int *));
        for(int i = 0; i < row; i++)
        matrix[i] = (int *)malloc(column * sizeof(int));
        //enter the value of matrices
        printf("Enter matrix:\n");
        for(int i = 0; i < row; i++)
            for(int j = 0; j < column; j++)
              scanf("%d",&matrix[i][j]);
        for (int i = 0; i < row; i++){
            for (int j = 0; j < column; j++){
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

int main(){
	int row,column;
	printf("Enter number of rows of matrix:");
    scanf("%d",&row);
    printf("Enter number of coloumns of matrix:");
    scanf("%d",&column);
    //checking whether the given matrix is square matrix or not
    if(row == column){
        symmetric(row,column);
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
