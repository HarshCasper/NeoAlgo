#include<bits/stdc++.h>
using namespace std;

int main() {

  int m, n;
  cout << "Enter the total number of elements in array1 and array2 respectively\n";
  cin >> m >> n;

  int arr1[m], arr2[n];
  cout << "enter 1st array elements\n";
  for (int i = 0; i < m; i++) {
    cin >> arr1[i];
  }
  cout << "enter 2nd array elements\n";
  for (int i = 0; i < n; i++) {

    cin >> arr2[i];
  }
  
  // iterating through first array from the end and the second array from start.
  for (int i = m - 1, j = 0; i >= 0 && j < n; i--, j++) {
    int temp;
    // swap if number in 1st array is greater than 2nd array.
    if (arr1[i] > arr2[j]) {
      temp = arr1[i];
      arr1[i] = arr2[j];
      arr2[j] = temp;
    }
  }
  
  //sorting both the arrays to get final result.
  sort(arr1, arr1 + m);
  sort(arr2, arr2 + n);
  cout << "answer: ";
  for (int i = 0; i < m; i++) {
    cout << arr1[i] << " ";
  }
  for (int i = 0; i < n; i++) {
    cout << arr2[i] << " ";
  }
  cout << endl;

  return 0;
}

/*

Time complexity : NlogN (where N will be max of n and m)

Sample output:
Enter the total number of elements in array1 and array2 respectively
3 4
enter 1st array elements
2 4 6
enter 2nd array elements
1 3 5 7
answer: 1 2 3 4 5 6 7

*/
