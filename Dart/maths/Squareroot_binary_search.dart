/* 
Finding square root of an integer by using Binary Search DART.

Given an integer x, find it’s square root. If x is not a perfect square, 
then return floor(√x).
*/

import 'dart:io';

int square_root_binary_search(int n) {
  int root = 1;

  // Return same number when n is 0 and 1.
  if (n == 0 || n == 1) return n;

  // Using Binary Search to find Square Root or nearest
  // square root of n.
  int left = 1, right = n;
  while (left <= right) {
    int mid = left + (right - left) ~/ 2;

    if (mid * mid == n) return mid;
    if (mid * mid < n) {
      left = mid + 1;
      root = mid;
    } else
      right = mid - 1;
  }
  return root;
}

void main() {
  // taking input from user
  var n;
  print('Enter the element: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  int sq_root;
  print("\nSquare Root of $n is: ");
  sq_root = square_root_binary_search(n);
  print(sq_root);
}
/*
TIME COMPLEXITY: O(log n).
SPACE COMPLEXITY: O(1).

SAMPLE INPUT/OUTPUT:
Enter the element:
67

Square Root of 67 is:
8
*/

