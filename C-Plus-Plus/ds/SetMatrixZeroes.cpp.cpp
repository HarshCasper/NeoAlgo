/*
This program is about setting the elements of a mXn matrix corresponding row and column into zeroes 

For this,I will use the First Row and first columm for keeping track whether 

any row or column has 0 or not,and furthur on finding zero,we mark it on firstrow and firstcolumn 

and then on finding 0 on firstrow or firstcolumn we convert the elements of its whole row and column to 0.

*/



#include <iostream>

#include<algorithm>

#include<vector>

using namespace std;

//Function for making an entire row and column  to be 0
void setZeroes(vector < vector < int >> & matrix) {
  //Base Case
  if (matrix.size() == 0 || matrix[0].size() == 0) {
    return;
  }
  int m = matrix.size();
  int n = matrix[0].size();

  bool firstRowZero = false;
  bool firstColZero = false;

  for (int j = 0; j < n; j++) {
    if (matrix[0][j] == 0) {
      firstRowZero = true;
      break;
    }
  }

  for (int i = 0; i < m; i++) {
    if (matrix[i][0] == 0) {
      firstColZero = true;
      break;
    }
  }

  // If you found a zero in matrix then simply mark it on first row and first column
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (matrix[i][j] == 0) {
        matrix[0][j] = 0;
        matrix[i][0] = 0;
      }
    }
  }

  /*On finding zero on firstrow and firstcolumn convert its corresponding row and column elements as 0
  This step helps to avoid converting all elements of matrix 0
  */
  
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
  }

  //Boundary Case 
   
  if (firstRowZero) {
    for (int j = 0; j < n; j++) {
      matrix[0][j] = 0;
    }
  }

  if (firstColZero) {
    for (int i = 0; i < m; i++) {
      matrix[i][0] = 0;
    }
  }
}

int main() {
  int t;
  cout << "Enter the number of testcases:" << endl;
  cin >> t;
  while (t--) {
    vector < vector < int >> matrix;
    int m, n;
    cin >> m;
    cin >> n;
    for (int i = 0; i < m; i++) {
      vector < int > ans;
      for (int j = 0; j < n; j++) {
        int temp;
        cin >> temp;
        ans.push_back(temp);
      }
      matrix.push_back(ans);
    }
    cout << "Current Matrix:" << endl;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
    setZeroes(matrix);
    cout << "Matrix after setting zeroes:" << endl;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }

  }

}

/*

Enter the number of testcases:
1
3
3
1
2
3
1
0
1
3
2
1
Current Matrix:
1 2 3 
1 0 1 
3 2 1 
Matrix after setting zeroes:
1 0 3 
0 0 0 
3 0 1 

Time Complexity- O(n) or O(m) depending upon m and n
Space Complexity-O(1)

*/
