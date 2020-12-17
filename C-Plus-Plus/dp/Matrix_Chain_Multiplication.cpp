// Matrix chain multiplication algorithm 
#include <bits/stdc++.h> 
using namespace std; 

// Matrix Ai has dimension p[i-1] x p[i] 
// for i = 1..n we will have P[n+1] array of dimensions
int *p= NULL;
int n; //number of matrices
int minMul=0; //min scalar multiplication

int **m=NULL;
int **s=NULL;

//function to take dimensions as input
void input()
{
	cin>>n; //number of matrices
	p=new int[n+1];
	for(int i=0;i<=n;i++)
		cin>>p[i];
	
	m=new int*[n];		// to store the number of scalar multiplications
	for(int i = 1; i <= n; ++i)
      m[i] = new int[n];
	
	s=new int*[n-1];		//to store the K for paranthesis
	for(int i = 1; i <= n-1; ++i)
      s[i] = new int[n-1];
}
void MatrixChainMultiply() 
{ 
  
    //int m[n][n]; 	// to store the number of scalar multiplications
	//int s[n-1][n-1];   //to store the K for paranthesis
	
    int i, j, k, L, q; 
  
    /* m[i, j] = Minimum number of scalar multiplications needed to compute the 
    matrix A[i]A[i+1]...A[j] = A[i..j] where dimension of A[i] is p[i-1] x p[i] */
  
    // cost is zero when multiplying only one matrix. 
    for (i = 1; i <= n; i++) 
        m[i][i] = 0; 
  
    // L is chain length. 
    for (L = 2; L <= n; L++)  
    { 
        for (i = 1; i <= n - L + 1; i++)  
        { 
            j = i + L - 1; 
            m[i][j] = INT_MAX; 
            for (k = i; k <= j - 1; k++)  
            { 
                // q = cost per scalar multiplications 
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                { 
					m[i][j] = q;
					s[i][j] = k;
				}				
            } 
        } 
    } 
	
    minMul = m[1][n]; 
	cout<<"*************** Matrix Chain Multiplication ***************"<<endl<<endl;
	cout<<"Minimum number of multiplications are: "<<minMul<<endl;
} 
void printOptimalParens(int i,int j)
{
	if(i==j)
		cout<<"A"<<i;
	else
	{
		cout<<"(";
		printOptimalParens(i,s[i][j]);
		printOptimalParens(s[i][j]+1,j);
		cout<<")";
	}
}	
// Driver Code 
int main() 
{ 
	input();
	MatrixChainMultiply(); 
	cout<<"The way which give the minimum number of scalar multiplications is: ";
	printOptimalParens(1,n);
	cout<<endl;
    return 0; 
} 
  
/*Input
Number of matrices=n= 4
dimensions = 10 20 30 40 50

Output
*************** Matrix Chain Multiplication ***************

Minimum number of multiplications are: 38000
The way which give the minimum number of scalar multiplications is: (((A1A2)A3)A4)

Complexity:
Time: O(n^3)
Space: O(n^2)
*/
