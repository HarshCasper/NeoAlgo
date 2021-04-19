/*

Problem Statement:
For a matrix of order n X m, with non-decreasing elements both along rows and columns, 
A "successful submatrix for K" is a square submatrix of A, i.e. a submatrix with n row 
and n column, for any integer n, such that the average of all the integers in this submatrix is ≥ K.
Find the number of such possible successful submatrices for given K.

Algorithm:
1. Preprocess matrix A such that every element in the auxiliary matrix contains the sum of all the elements 
preceding it (row-wise & column-wise)... ie, aux[i][j] stores sum of elements from (0,0) to (i,j).

2. Thereby, sum of the required submatrix can be found dynamically using : 
aux(bottom_right) - aux(bottom_left) - aux(top_right) + aux(top_left)

*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// function to return number of successful submatrix for k
int successful_submat(ll n, ll m, ll k){
    ll count=0;
    ll mat[n+1][m+1], aux[n+1][m+1], arr[n];
    // pad top & left margins of matrix with zeros
    for (ll i = 0; i <= n; i++)
        mat[i][0] = 0;
    for (ll i = 0; i <= m; i++)
        mat[0][i] = 0;

    // input matrix
    cout << "Enter the matrix of order " << n << " X " << m << endl;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
            cin >> mat[i][j];

    /* build auxiliary matrix */
    // Function to preprocess input mat[n][m]
    // Fills aux[n][m] such that aux[i][j] stores sum of elements from (0,0) to (i,j)

    // Copy first row of mat[][] to aux[][]
    for (ll i=0; i<= m; i++)
        aux[0][i] = mat[0][i];

    // Do column wise sum
    for (ll i=1; i<= n; i++)
        for (ll j=0; j<= m; j++)
            aux[i][j] = mat[i][j] + aux[i-1][j];

    // Do row wise sum
    for (ll i=0; i<=n; i++)
        for (ll j=1; j<=m; j++)
            aux[i][j] += aux[i][j-1];

    // dynamically find average of elements of each submatrix
    for(ll order=1;order<=n; order++){
        ll r=n, c=m;
        for(ll i = order; i <= r && r!=0; i++){
            for (ll j = order; j <= c && c!=0; j++){
                //condition to qualify as a successful submatrix
                if((aux[i][j] - aux[i][j-order] - aux[i-order][j] + aux[i-order][j-order]) >= order*order*k){
                    count += (r+1-i) * (c+1-j);
                    c = j-1;
                    break;
                }
            }
        }
    }
    return count;
}

// driver code
int main(void){
    ll n, m, k;
    cout << "Enter number of rows, columns and the integer k" << endl;
    cin >> n >> m >> k;
    ll count = successful_submat( n, m, k);
    cout << "Number of successful submatrices for (k = "<< k << ") is =>  " << count << endl;
    return 0;
}

/*
Sample I/O:
Enter number of rows, columns and the integer k
3 3 4
Enter the matrix of order 3 X 3
2 2 3
3 4 5
4 5 5
Number of successful submatrices for (k = 4) is =>  7

Time Complexity: O(n*m)
Space Complexity: O(n*m)
*/
