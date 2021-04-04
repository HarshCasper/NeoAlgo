// Transpose of a square matrix is obtained by changing the row to columna and vice-versa.
#include <bits/stdc++.h>
using namespace std;

#define N 3

void transpose(int a[][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int temp;
            temp = a[j][i];
            a[j][i] = a[i][j];
            a[i][j] = temp;
        }
    }
}

int main() {
    // int n;
    // cout<<"Enter the dimension of the matrix:";
    // cin>>n;

    int a[N][N];
    cout<<"Enter the elements of the matrix:"<<endl;
	for(int i=0;i<N;i++){
	    for(int j=0;j<N;j++){
	        cin>>a[i][j];
	    }
	}

    transpose(a);

	cout<<"The transpose of the given matrix is:"<<endl;
	for(int i=0;i<N;i++){
	    for(int j=0;j<N;j++){
	        cout<<a[i][j]<<" ";
	    }
	    cout<<endl;
	}

	return 0;
}

/* Sample I/O

Enter the elements of the matrix:1 2 3 4 5 6 7 8 9
The transpose of the given matrix is:
1 4 7
2 5 8
3 6 9

Time Compexity: O(n^2)
Space Complexity: O(1)
*/
