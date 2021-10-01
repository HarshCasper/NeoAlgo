/*
The function find the MEX of an n integer array.
MEX is the minimum excluded element in an array, i.e, the minimum number which
is not present in the given array.
*/

import 'dart:io';
import 'dart:core';

int get_MEX_of_array(List arr, int n) {
  // Creating a set to store the unique elements of the array
  var mex_find = <int>{};
  for (int i = 0; i < n; i++) {
    mex_find.add(arr[i]);
  }

  // Iterating through the array and checking if integers from 0 to n are not in
  // the given array
  int mex = 1;
  for (int i in mex_find) {
    // Checking if the mex chosen is in the set mex_find
    if (mex_find.contains(mex)) {
      mex++;
    }
    // Indicating that we have already found the mex of the array
    else if (i > mex) {
      break;
    }
  }
  return mex;
}

main() {
  // Driver code to take user input
  var array = [];

  var n, ele, x;
  print('Enter the number of Elements: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  for (int i = 1; i <= n; i++) {
    print('Enter Element $i: ');
    ele = stdin.readLineSync();
    ele = int.parse(ele);
    array.add(ele);
  }

  int arr_mex = get_MEX_of_array(array, n);
  print("Minimum excluded element of the Array is : $arr_mex");
}

/*

TIME COMPLEXITY: O(log N)

SPACE COMPLEXITY: O(N)

Standard I/O:
Enter the number of Elements: 
6
Enter Element 1: 
5
Enter Element 2: 
2
Enter Element 3: 
9
Enter Element 4: 
1
Enter Element 5: 
1
Enter Element 6: 
3
Minimum excluded element of the Array is : 4
*/
