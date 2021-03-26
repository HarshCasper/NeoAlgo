// transposing a matrix without extra space

#include <bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int> > matrix){

	int n = matrix.size();

	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			swap(matrix[i][j], matrix[j][i]);
		}
	}
}

int main(){
	int n; // for a nxn matrix
	cin>>n;
	vector<vector<int> > matrix;
	for(int i=0; i<n; i++){
		for(int j=0; j<n;j++){
			int a;
			cin>>a;
			matrix[i][j]=a;
		}
	} 

	transpose(matrix);

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}

/*
	example:
		intput matrix:

			1 2 3 4
			4 6 7 8
			3 7 8 4
			7 3 9 6

		transposed matrix:

			2 4 3 7
			2 6 7 3
			3 7 8 9
			4 8 4 6
*/