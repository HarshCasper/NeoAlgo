#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ROW, COLUMN;
    printf("Enter Row: ");
    scanf("%d", &ROW);
    printf("Enter Column: ");
    scanf("%d", &COLUMN);
    printf("Enter the elements of Matrix:\n");
    int arr[ROW][COLUMN], minimum, i, j, temp, k, w, z = 0, q = 0 ;
    /* 
     i = row iterator
     j= column iterator
     temp = temporary Variable to swap the values
     k = iteration for row iterator i
     w = for storing the previous value of column iterator j;
     z = used as a temporary variable for storing k
     q = used as temporary variable for storing column iterator j

     */

    for(i = 0;i < ROW;i++)
        for(j = 0;j < COLUMN;j++)
        {
            scanf("%d",&arr[i][j]);
        }


    for(i = 0;i < ROW;i++)
        for(j = 0;j < COLUMN;j++)
        {
            temp = i;
            q = j;
            minimum = arr[i][j];
            w = j;
            for(k = i;k < ROW;k++)
            {

                for(;w < COLUMN;w++)
                if(arr[k][w] < minimum)
                {
                    minimum = arr[k][w];
                    z = k;
                    q = w;
                }
                w = 0;
            }
            if(arr[z][q] < arr[i][j])
            {
                temp = arr[i][j];
                arr[i][j] = minimum;
                arr[z][q] = temp;
            }
        }

    printf("\nSorted Matrix: \n");
    for(i = 0; i < ROW; i++)
    {
        for(j = 0;j < COLUMN;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    
    return 0;
}
/*C implementation to sort the given matrix

 Input :
  Enter Row: 3
  Enter Column: 3
  Enter the elements of matrix :
  7 8 9
  5 6 4
  3 1 2
  Output :
  Sorted Matrix :
  1 2 3
  4 5 6
  7 8 9

  Time Complexity: O(n2log2n)
  Space Complexity : Auxiliary Space: O(n2)
 */