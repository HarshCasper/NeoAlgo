/*
Problem : 
	Given a 2D array  of size N*N. Find the total sum of all the submatrices in the given matrix.

-->Naive method :
	Consider a submtarix to be formed from an element which represents top left position say,(i1, j1) and a bottom right position say, (i2, j2). 
	The bruteforce method would be to find all the submatrices starting from a particular index(i1, j1) and calculating the sum of each submatrix and finally adding to the total answer.
	If we proceed in this manner, we will require a complexity of O(n^2) for selecting (i1, j1), another O(n^2) for selecting the corresponding (i2, j2) for each (i1, j1) and finally O(n^2) for calculating the sum.
	Hence the total time complexity will be O(n^6).

-->Efficient Method : (USING REVERSE LOOKUP in 2D)

	In this method, the main intution is to get the number of subarrays where a particular element is included.
	Once we have the repetition number, we can multiply the element with the number of times it is repeated in order to get the actual contribution of that element towards the final sum.
	
	For example, let's say we have an element with value X placed at (i, j)th position in the matrix. Now for X to be included in a submatrix, that particular submatrix must start from any index between (0, 0) to (i, j) and must end between any indicies from (i, j) to (N-1, N-1).
	Therefore, the total number of possibilities for selecting a top-left index which includes (i, j) = ( i + 1 ) * ( j + 1 )
	and the the total number of possibilities for selecting a bottom-right index which includes (i, j) = ( N - i ) * ( N - j )

	The contribution by X = X * total posibilities  = X * ( i + 1 ) * ( j + 1 ) * ( N - i ) * ( N - j )

	Hence the total time complexity would just be O(N^2).

Note : In order to avoid overflows while adding, use Modular arithmethic
-> (a + b) % M = ((a % M) + (b % M)) % M
-> (a * b) % M = ((a % M) * (b % M)) % M
where, M = 10^9 + 7

*/

#include <bits/stdc++.h>
using namespace std;

//initializing the mod value to avoid overflows
const long long M = 1e9 + 7;

int main(){
	int n, value; 
	cin >> n;

	//initialization
	long long total_contribution, top_left_contrib, bottom_right_contrib, total_sum = 0;
	vector<vector<int>> array;

	//reading the matrix
	for(int i = 0; i < n; i++){
		vector<int> row;
		for(int j = 0; j < n; j++){
			cin >> value;
			row.push_back(value);
		}
		array.push_back(row);
	}

	//calculating contribution and computing total sum
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			top_left_contrib = (( i + 1) % M * ( j + 1) % M ) % M;
			bottom_right_contrib = (( n - i) % M * ( n - j ) % M ) % M;  
			
			//total_contribution = top_left_contrib * bottom_right_contrib * array[i][j]
			total_contribution = ((top_left_contrib % M * bottom_right_contrib % M ) % M * array[i][j] % M ) % M;
			total_sum = ((total_sum % M) + (total_contribution % M)) % M;
		}
	}

    cout << total_sum;

	return 0;
}


/*
Input : 
3
1 5 3
4 5 6
7 1 9

Output:
452

Time Complexity : O(n^2)
Space Complexity : O(1)

*/