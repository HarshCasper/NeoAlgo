/* Sparse Matrix Representation using Array
  Input :
  Enter the size of matrix (rows and columns) :
  4
  5
  Enter the elements of matrix
  0 8 6 0 2
  9 0 0 3 0
  0 3 0 0 0
  6 0 0 0 7
  
  Output:
  3 tuple row major representation :
  4     5       8
  0     1       8
  0     2       6
  0     4       2
  1     0       9
  1     3       3
  2     1       3
  3     0       6
  3     4       7
 */


#include<stdio.h>
#include<stdlib.h>

void sparseMatrix(int sparse[][3], int arr[100][100], int m, int n)
{
	int i,j,k=1,c=0;
	
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			if(arr[i][j]!=0) //if non-zero element then put into sparse matrix
			{
				
				sparse[k][0] = i; //row number of arr[i][j] into sparse[k][0]
				sparse[k][1] = j; //column number of arr[i][j] into sparse[k][1]
				sparse[k][2] = arr[i][j]; //arr[i][j] into sparse[k][2]
				c++; //count of non-zero elements
				k++; //increment row of matrix
			}
		}
	}
	sparse[0][0] = m; //put no. of rows of arr into sparse[0][0]
	sparse[0][1] = n; //put no. of columns of arr into sparse[0][1]
	sparse[0][2] = c; //put no. of non - zero elemnts of arr into sparse[0][2]
	
}

int main()
{
	int m,n,i,j;
    int a[100][100]; 
	int ss[100][3];
	
	printf("Enter the size of matrix (rows and columns) : ");
	scanf("%d %d",&m, &n);
	
	     
	printf("\nEnter the elements of matrix");
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
		   scanf("%d", &a[i][j]);
		}
	}

	sparseMatrix(ss,a,m,n); // call sparse matrix function
	
	printf("\n3 tuple row major representation : \n");
	for(i=0; i<ss[0][2]+1 ; i++) //print row major representation, no. of rows are stored in 1st row, 3rd column
	{
		for(j=0; j<3; j++) // no. of rows will be 3
		{
			printf("%d ",ss[i][j]); 
		}
		printf("\n");
	}
	return 0;
}
/* Time Complexity:O(noOfTerms*noOfcolumn)
  Space Complexity:O(1)	 
  */
  
