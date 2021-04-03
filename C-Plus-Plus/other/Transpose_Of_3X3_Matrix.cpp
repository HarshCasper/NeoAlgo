/* Transpose of a matrix is a new matrix in which the rows
of the original matrix are the columns now and vice versa.
If the given matrix is 1 2 3
                       4 5 6
                       7 8 9

then the transpose if  1 4 7
                       2 5 8
                       3 6 9
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int matrix[3][3];

	cout<<"Enter the elements of the matrix:"<<endl;
	for(int i=0;i<3;i++){
	    for(int j=0;j<3;j++){
	        cin>>matrix[i][j];
	    }
	}

	int transpose[3][3];
	for(int i=0;i<3;i++){
	    for(int j=0;j<3;j++){
	        transpose[i][j]=matrix[j][i];
	    }
	}

	cout<<"The transpose of the given matrix is:"<<endl;
	for(int i=0;i<3;i++){
	    for(int j=0;j<3;j++){
	        cout<<transpose[i][j]<<" ";
	    }
	    cout<<endl;
	}

	return 0;
}

/* Sample I/O

Enter the elements of the matrix:
1 2 3
4 5 6
7 8 9
The transpose of the given matrix is:
1 4 7
2 5 8
3 6 9

Time Complxity: O(n^2)
Space Complexity: O(1)

*/
