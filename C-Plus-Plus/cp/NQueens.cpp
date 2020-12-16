/**
N-Queens problem is a famous problem
The paradigm used to solve the problem is backtracking
The problem is to find a way to place n queens on nXn board
such that no queen can kill the other
**/

#include <bits/stdc++.h>
using namespace std;

#define N 20
    
void solve(bool board[N][N], bool cols[N], bool ndiag[2*N-1], bool rdiag[2*N-1], int row, string asf, int n) {
    
    if(row == n) {
        cout << asf << '.' << '\n';
        return;
    }
    
    for(int col=0; col<n; col++) {
        if(cols[col] == false && ndiag[row+col] == false && 
            rdiag[row-col+n-1] == false) {
                // place the queen
                cols[col] = true;
                ndiag[row+col] = true;
                rdiag[row-col+n-1] = true;
                board[row][col] = true;
                solve(board, cols, ndiag, rdiag, row+1, asf+to_string(row)+"-"+to_string(col)+", ", n);
                // backtrack
                cols[col] = false;
                ndiag[row+col] = false;
                rdiag[row-col+n-1] = false;
                board[row][col] = false;
            }
    }
}

int main() {
	int n;
	cin >> n;

	bool board[N][N];
    bool cols[N];
    bool ndiag[2*N-1], rdiag[2*N-1];

	// initialize
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			board[i][j] = false;

    // initialize that no column has a queen
	for(int i = 0; i < n; i++)
		cols[i] = false;

	for(int i = 0; i < 2*n-1; i++) {
		ndiag[i] = false;
		rdiag[i] = false;
	}

	solve(board, cols, ndiag, rdiag, 0, "", n);
}

/**
Input :
4
Output :
0-1, 1-3, 2-0, 3-2, .
0-2, 1-0, 2-3, 3-1, .
Space Complexity : O(n^2)
Time Complexity : upperbounded by O(n^n)
**/