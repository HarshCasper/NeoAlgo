// SudokuSolver
//Given a partially filled 9×9 2D array ‘grid[9][9]’, the goal is to assign digits (from 1 to 9) to the empty cells so that every row, column, and subgrid of size 3×3 contains exactly one instance of the digits from 1 to 9.
#include <iostream>
#include <cmath>
using namespace std;

bool isSafeToPut(int mat[][9],int i,int j,int n,int number){
	// Check the rows and cols
	for(int k=0;k<n;k++){
		if(mat[k][j]==number){
			return false;
		}
	}

	for(int k=0;k<n;k++){
		if(mat[i][k]==number){
			return false;
		}
	}

	n=sqrt(n);
	int starti=(i/n)*n;
	int startj=(j/n)*n;

	for(int k=starti;k<starti+n;k++){
		for(int l=startj;l<startj+n;l++){
			if(mat[k][l]==number){
				return false;
			}
		}
	}
	return true;

}


bool SudokuSolver(int mat[][9],int i,int j,int n){
	if(i==n){
		// Print the sudoku
		for(int k=0;k<n;k++){
			for(int l=0;l<n;l++){
				cout<<mat[k][l]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return true;
	}
	if(j==n){
		return SudokuSolver(mat,i+1,0,n);
	}
	if(mat[i][j]!=0){
		return SudokuSolver(mat,i,j+1,n);
	}
	for(int number=1;number<=n;number++){
		if(isSafeToPut(mat,i,j,n,number)){
			mat[i][j]=number;
			bool t=SudokuSolver(mat,i,j+1,n);
			if(t){
				return true;
			}
			mat[i][j]=0;
		}
	}
	return false;
}


int main(){
	int mat[9][9] =
		{{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}};

	SudokuSolver(mat,0,0,9);

	return 0;
}
 
/*Input
        {5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
Output
    
5 3 4 6 7 8 9 1 2                                                                                                                               
6 7 2 1 9 5 3 4 8                                                                                                                               
1 9 8 3 4 2 5 6 7                                                                                                                               
8 5 9 7 6 1 4 2 3                                                                                                                               
4 2 6 8 5 3 7 9 1                                                                                                                               
7 1 3 9 2 4 8 5 6                                                                                                                               
9 6 1 5 3 7 2 8 4                                                                                                                               
2 8 7 4 1 9 6 3 5                                                                                                                               
3 4 5 2 8 6 1 7 9  

Time Complexity
 O(9^(n*n))*/
