// Transpose of a square matrix is obtained by changing the rows to columns and vice-versa.
#include <bits/stdc++.h>
using namespace std;



void transpose(int *a,int N){
    int i,j;
    for( i=0;i<N;i++){
        for( j=i+1;j<N;j++){
            int temp;
            temp = *(a+ j *N + i);
            *(a+ j *N + i) = *(a+ i *N + j);
            *(a+ i *N + j) = temp;
        }
    }
}

int main() {
    int N;
    cout<<"Enter the dimension of the matrix:";
    cin>>N;

    int a[N][N];
    cout<<"Enter the elements of the matrix:";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>a[i][j];
        }
    }

    transpose(a[0],N);

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

Enter the dimension of the matrix:3
Enter the elements of the matrix:1 2 3 4 5 6 7 8 9
The transpose of the given matrix is:
1 4 7
2 5 8
3 6 9


Time Compexity: O(n^2)
Space Complexity: O(1)
*/
