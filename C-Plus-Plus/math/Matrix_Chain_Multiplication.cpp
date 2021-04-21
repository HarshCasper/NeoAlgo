/*
Given a sequence of matrices, find the most efficient way to multiple these matrices together. 
We have to find the way which costs minimum.
Let's asssume two matrices are there of order 10X30 and 30X20 so cost of multiplication of them will be 10*30*20 ,
we will take the common order element only once .
*/

#include <bits/stdc++.h>

using namespace std;

int t[1001][1001];
int solve(int arr[], int i, int j) {
  /*
   If there is no element in the array then we don't have any matrix .
   If there is only one element in the array then we can't find the order of the matrix as order of matrix at ith index is arr[i-1]*arr[i].
   */
  if (i >= j) {
    return 0;
  }

  memset(t, -1, sizeof(t));
  if (t[i][j] != -1) {
    return t[i][j];
  }

  int ans = INT_MAX;
  /* moving from first matrix which will be at index 1 and its order will be arr[0]*arr[1]
    to last matrix which will be at index n-2 and its order will be arr[n-3]*arr[n-2] . */
  for (int k = i; k < j; k++) {
    /* splitting the problem into two parts and finding answers of both parts and adding cost of multiplying both answers in temp */
    int temp = solve(arr, i, k) +
      solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
    // getting minimum of all costs.
    ans = min(ans, temp);
  }

  return t[i][j] = ans;
}

int matrixMultiplication(int N, int arr[]) {
  int i = 1, j = N - 1;

  return solve(arr, i, j);
}

int main() {
  int N;
  cout << "Size of array -" << endl;
  cin >> N;
  int arr[N + 1];
  cout << "Input Array -" << endl;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  cout << "Minimum costs -" << endl;
  cout << matrixMultiplication(N, arr);
}
/*

Input: 
Size of array -                                                                                                                                 
4                                                                                                                                               
Input Array -                                                                                                                                   
10 30 5 60  

Output:                                                                                                                                    
Minimum costs -                                                                                                                                 
4500

Time Complexity: O(N ^ 3)
Space Complexity: O(N ^ 2)
*/
