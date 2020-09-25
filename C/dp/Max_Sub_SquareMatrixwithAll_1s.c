// C code for Maximum size square sub-matrix with all 1's 
#include<stdio.h>

int main() {

  int r_size, c_size, mat[r_size][c_size], MaxSub[r_size][c_size];
  printf("Input --> \n");
  printf("Enter the row-size :\n");
  scanf("%d", & r_size);
  printf("Enter the column-size :\n");
  scanf("%d", & c_size);
  printf("Enter the elements of matrix  :\n");
  for (int i = 0; i < r_size; i++) {
    for (int j = 0; j < c_size; j++) {
      scanf("%d", & mat[i][j]);
    }
  }
  /* Set first column of MaxSub[][]*/
  for (int i = 0; i < r_size; i++)
    MaxSub[i][0] = mat[i][0];
  /* Set first row of MaxSub[][]*/
  for (int j = 0; j < c_size; j++)
    MaxSub[0][j] = mat[0][j];

  /* Construct other entries of MaxSub[][]*/
  for (int i = 1; i < r_size; i++) {
    for (int j = 1; j < c_size; j++) {
      if (mat[i][j] == 1) {
        int m;
        /* To get minimum of three values */
        m = MaxSub[i][j - 1];
        if (m > MaxSub[i - 1][j])
          m = MaxSub[i - 1][j];
        if (m > MaxSub[i - 1][j - 1])
          m = MaxSub[i - 1][j - 1];

        MaxSub[i][j] = m + 1;
      } else
        MaxSub[i][j] = 0;
    }
  }
  /* Find the maximum entry, and indexes of maximum entry  
      in MaxSub[][] */
  int max_of_subMat = MaxSub[0][0], max_i = 0, max_j = 0;
  for (int i = 0; i < r_size; i++) {
    for (int j = 0; j < c_size; j++) {
      if (max_of_subMat < MaxSub[i][j]) {
        max_of_subMat = MaxSub[i][j];
        max_i = i;
        max_j = j;
      }
    }
  }
  printf("Output -->\n");
  printf("Maximum square sub-matrix is: \n");
  int size = 0;
  for (int i = max_i; i > max_i - max_of_subMat; i--) {
    for (int j = max_j; j > max_j - max_of_subMat; j--) {
      printf("%d ", mat[i][j]);

    }
    printf("\n");
    size++;
  }
  printf("Size of max SubSquareMatrix : ");
  printf("%d", size);
  return 0;
}

/*
 Input -->

 Enter the row-size : 3
 Enter the column-size : 4
 Enter the elemnts of matrix :
 1 0 1 1 
 0 1 1 1
 0 0 1 1

 Output -->
 Maximum square sub-matrix is: 
 1 1 
 1 1 
 Size of max SubSquareMatrix : 2
 Time Complexity: O(m*n) where m is number of rows and n is number of columns in the given matrix.
 Auxiliary Space: O(m*n) where m is number of rows and n is number of columns in the given matrix.
*/
