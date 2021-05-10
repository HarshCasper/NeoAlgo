/*
It will be given a seuence of matrices to find the most 
efficient way to multiply these matrices together.
The problem is not to perform the actual multiplication 
but it is to find the most appropriate order to perform that multiplication.
We have many option to muliply a chain of matrices because matrix is associative.  

*/




#include<stdio.h>
#include<limits.h>

//Matrix Ai has dimension a[i-1]xa[i] for i=1....n
int MatrixChain(int a[],int n)
{
	/*
	For simplicity of the program, one extra row and one 
	extra column are allocated in m[][].
	0th row and 0th coulmn of m[][] are not used.
	*/
	
	int m[n][n];
	int i,j,k,L,q;
	
	/*M[i][j]= Minimum number of scalar multiplications
	needed to compute the matrix A[i],A[i+1],.....A[j]=A[i,....j]  where dimension  of A[i] is a[i-1]xa[i] 
	*/
	
	
	//cost is zero when multiply one matrix...
	for(i=1;i<n;i++)
	{
		m[i][i]=0;
	}
	//L is length of the Chain
	for(L=0;L<n;L++)
	{
		for(i=1;i<n-L+1;i++)
		{
			j=L+i-1;
			//initializing it to max possible value.
			m[i][j]=INT_MAX;
			for(k=i;k<=j;k++)
			{
				//q= cost/scalar multiplications
				q=m[i][k]+m[k=1][j]+p[i-1]*p[k]*p[j];
				//condition checking
				if(q<m[i][j])
				m[i][j]=q;
				
			}
		}
	}
	//return the minimum count
	return m[1][n-1];
}

//Driver Code
int main()
{
	// size of matrix

	int n;
	//taking input
  	printf("Enter the size of Matrix");
	scanf("%d",&n);
	int i;
	int arr[n];
	printf("Enter your Matrix");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	//calling the funtion
	printf("Minimum Number of multiplication is %d",MatrixChain(arr,n));
	getchar();
	return 0;
	
}

/*
Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/
/*
Sample Input:
{1,2,3,4}

sample output:
Minimum Number of multiplication is 18
*/

