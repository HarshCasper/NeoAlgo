/*
Given a N * N square matrix. A matrix has two diagonals. One diagonal is principal which starts from the first row, first column
another diagonal is secondary which starts from the first row, last column
Find the sum of it's principal and secondary diagonal elements.
*/

#include <bits/stdc++.h>
using namespace std;
int ar[500][500];

/* From this get_principal_secondary_diagonal_sum() function we will compute matrix's principal,secondary diagonal sum */
int get_principal_secondary_diagonal_sum(int N)
{
    int principal_secondary_diagonal_sum = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i == j)
            {
                /* here principal diagonal element is at cell [1 , 1] , [0 ,0],
                [2 , 2] like this goes on
                that's why condition is i == j
                 */
                principal_secondary_diagonal_sum += ar[i][j];
            }
            else if( (i + j == (N - 1)) and i != j )
            {
                /* here secondary diagonal element is at cell [1 , 4] , [2 ,3],
                [3 , 2] like this goes on
                that's why condition is i + j == ( n - 1) and i != j
                */
                principal_secondary_diagonal_sum += ar[i][j];
            }
        }
    }
    return principal_secondary_diagonal_sum;
}

int main()
{
    cout << "Enter the size of the matrix : \n";
    int N;
    cin >> N;
    cout << "Enter matrix elements :\n";
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> ar[i][j];
        }

     }
     int principal_secondary_diagonal_sum  = get_principal_secondary_diagonal_sum(N);
     cout << "Sum of Principal and Secondary Diagonal of this matrix is : ";
     cout << principal_secondary_diagonal_sum << endl;
}

/*
Standard Input and Output

Enter the size of the matrix :
4
Enter matrix elements :
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
Sum of Principal and Secondary Diagonal of this matrix is : 68

Time Complexity : O( N * N )
Space Complexity : O( 1 )

*/
