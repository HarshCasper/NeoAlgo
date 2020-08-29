
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
*/

#include <bits/stdc++.h>
using namespace std;

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
    int oneD_arr[n*n + 2]; // Array to store all the elements in 1_D for sorting
    int pos = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            oneD_arr[pos++] = arr[i][j];
        }
    }
    sort(oneD_arr, oneD_arr+pos); // Using inbuilt sort
    pos = 0;
    cout<<"\n Sorted 2-D Matrix is:"<<"\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            arr[i][j] = oneD_arr[pos++]; // changing value of intial array with sorted values
            cout<<arr[i][j]<<" "; // displays output
        }
        cout<<"\n";
    }
    return (0);
}