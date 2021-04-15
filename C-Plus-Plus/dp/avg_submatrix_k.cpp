/******************************************************************************
Author: @Suvraneel Bhuin

For a matrix with non-decreasing elements both along rows (left to right) and columns (top to bottom), 
A "successful submatrix for K" is a square submatrix of A, i.e. a submatrix with n row and n column, for any integer n, such that the average of all the integers in this submatrix is ≥K.

Algorithm:
1. Preprocess matrix A such that every element in the auxiliary matrix contains the sum of all the elements preceding it (row-wise & column-wise)... ie, aux[i][j] stores sum of elements from (0,0) to (i,j).
2. Thereby, sum of the required submatrix can be found dynamically using : 
aux(bottom_right) - aux(bottom_left) - aux(top_right) + aux(top_left)
*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(void){
   //fast.io
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n, m, k, t;
   cin>>t;
   while(t--){
      ll count=0;
      cin >> n >> m >> k;
      ll mat[n+1][m+1], aux[n+1][m+1], arr[n];
      //pad top & left margins of matrix with zeros
      for (ll i = 0; i <= n; i++)
         mat[i][0] = 0;
      for (ll i = 0; i <= m; i++)
         mat[0][i] = 0;

      //input
      for (ll i = 1; i <= n; i++)
         for (ll j = 1; j <= m; j++)
            cin >> mat[i][j];

      /* build auxiliary matrix*/
      // Function to preprocess input mat[M][N].  This function mainly fills aux[M][N] such that aux[i][j] stores sum of elements from (0,0) to (i,j)

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

      //dynamically find submatrix sum
      for(ll order=1;order<=n; order++){
         ll r=n, c=m;
         for(ll i = order; i <= r && r!=0; i++){
            for (ll j = order; j <= c && c!=0; j++){
               if((aux[i][j] - aux[i][j-order] - aux[i-order][j] + aux[i-order][j-order]) >= order*order*k){
                  count += (r+1-i) * (c+1-j);
                  c = j-1;
                  break;
               }
            }
         }
      }
      cout << count << endl;
   }
   return 0;
}

/*
Time Complexity: O(n*m)
Space Complexity: O(n*m)

Sample Input:
1
3 3 4
2 2 3
3 4 5
4 5 5

Standard Output:
7

Explanation:
The following are the seven successful submatrices for k=4:
⌈3   4⌉
⌊4   5⌋ with average 4; this matrix occurs only once
⌈4   5⌉
⌊5   5⌋ with average 4.75; this matrix also occurs only once
[4] with average 4; we find this matrix twice in A
[5] with average 5; we find this matrix 3 times in A
*/
