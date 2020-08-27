
/**
 * @author GrayFlask (Gaurav Kumar)
 * Given a n x n matrix. The problem is to sort the given matrix in strict order. 
 * Here strict order means that matrix is sorted in a way such that all elements
 * in a row are sorted in increasing order and for row ‘i’,
 * where 1 <= i <= n-1, first element of row 'i' is greater than or equal to the last element of row 'i-1'.
 * Input:
 * First line of input contains dimension n of the matrix.
 * Next n line form n rows with n elements each.
 * Output:
 * 
 *
 * Example:
 * Input:
 * 3
 * 5 4 7
 * 1 3 8
 * 2 9 6
 *
 * Output:
 * 1 2 3
 * 4 5 6
 * 7 8 9
 * 
 * Explanation:
 * @source: https://www.geeksforgeeks.org/sort-given-matrix/
*/

#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000
// function to print the given matrix
void printMat(int mat[SIZE][SIZE], int n)
{
    cout<<"Sorted Matrix is:"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}
void sortMat(int mat[SIZE][SIZE], int n)
{
    // temporary matrix of size n^2
    int temp[n*n];
    int k = 0;
    // copy the elements of matrix one by one
    // into temp[]
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[k++] = mat[i][j];
    // sort temp[]
    sort(temp, temp + k);
    // copy the elements of temp[] one by one
    // in mat[][]
    k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = temp[k++];
    printMat(mat, n);
}
int main() {
    int n;
    cout << "Enter the size of an array : " <<endl;
    cin >> n;
    int arr[1000][1000];
    cout << "Enter the elements in an array : " <<endl;
    for (int i=0 ; i<n; i++) {
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    sortMat(arr, n);
    return (0);
}