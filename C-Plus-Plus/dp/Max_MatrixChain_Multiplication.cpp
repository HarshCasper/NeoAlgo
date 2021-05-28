/*
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient 
way to multiply these matrices. In other words, determine where to place parentheses to 
minimize the number of multiplications.
*/

#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(int arr, int n){
    /
        For simplicity of the program, one extra row and one
        extra column are allocated in dp[][]. Oth row and oth
        column of dp[][] are not used
    /

    n += 1;

    /
        dp[i,j] = Minimum number of scalar multiplications needed
        to compute the matrix A[i]A[i+1]...A[j] = A[i..j] where
        dimension of A[i] is arr[i-1] x arr[i]
    */

    vector<vector<int>> dp(n, vector <int>(n));

    //Cost is zero when multiplying one matrix
    for(int i=1; i<n; i++){
        dp[i][i]=0;
    }

    //L is chain length
    for(int L=2; L<n; L++){
        for(int i=1; i<n-L+1; i++){
            int j = i+L-1;
            dp[i][j] = INT_MAX;
            for(int k=i; k<=j-1; k++){
                int q = dp[i][k] + dp[k+1][j] + (arr[i-1] * arr[k] * arr[j]);
                if(q<dp[i][j])
                    dp[i][j]=q;
            }
        }
    }
    return dp[1][n-1];
}

int main() {
    int size;
    cout<<"Enter the size of the array:";
    cin >> size;
    int* arr = new int[size];
   cout<<"Enter the array elements:"
    for (int i = 0; i <= size; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, size);

    delete[] arr;
}

/*
Time Complexity: O(N^3);
Space Complexity: O(N^2)
where N is the number of matrices to multiply

Sample Input:
5
2 4 6 12 11 21
Sample Output:
918
*/
