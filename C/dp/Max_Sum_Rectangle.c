//C code to implement maximum sum rectangle in a 2D matrix 

#include <stdio.h>
#include<stdbool.h>
#include<string.h>
#include <limits.h>

int main() {
    
  // R & C are the number of rows and columns 
  int R, C; 
  printf("Input-->\n");
  printf("Enter the row-sze: \n");
  scanf("%d", & R);
  printf("Enter the column-sze: \n");
  scanf("%d", & C);
  int matrix[R][C], temp[R], top, bottom;
  printf("Enter the elements of 2-D matrix :\n");
  for (int ol = 0; ol < R; ol++) {
    for (int inloop= 0; inloop < C; inloop++) {
      scanf("%d", & matrix[ol][inloop]);
    }
  }
  int maxSum = INT_MIN, finalTop, finalBottom, finalRight, finalLeft;

  for (int Left= 0; Left < C; Left++) {
    // Initialize the all elements of temp as 0
    memset(temp, 0, sizeof(temp));
    for (int Right = Left; Right < C; Right++) {
      for (int i = 0; i < R; i++) temp[i] += matrix[i][Right];
      int max = INT_MIN, S = 0, localTop = 0, sum;
      bool flag = false;
      for (int index = 0; index < R; index++) {
        if (temp[index] >= 0) flag = true;
        S = S + temp[index];
        if (S < 0) {
          S = 0;
          localTop = index+ 1;
        } else if (S > max) {
          max = S;
          top = localTop;
          bottom = index;
        }
      }
      if (flag) {
        sum = max;
      } else {
        max = INT_MIN;
        //To find the maximum element in array  
        for (int index = 0; index < R; index++) {
          if (max < temp[index]) {
            max = temp[index];
            top = bottom = index;
          }
        }
        sum = max;;
      }
      // Comparison of  sum with maximum sum 
      if (sum > maxSum) {
        maxSum = sum;
        finalTop = top;
        finalBottom = bottom;
        finalLeft = Left;
        finalRight = Right;
      }
    }
  }
  printf("\nOutput-->\n");
  printf("Maximum sumRectangle is : %d\n", maxSum);

  return 0;
}

/*
 Input-->
 Enter the row-sze: 4
 Enter the column-sze: 5
 Enter the elements of 2-D matrix :
 1 2 -1 -4 -20
 -8 -3 4 2 1
 3 8 10 1 3
 -4 -1 1 7 -6
 
 Output-->
 Maximum sumRectangle is : 29
 
 Time Complexity : O(N^3) 
 Space Complexity : O(N)
 */
 