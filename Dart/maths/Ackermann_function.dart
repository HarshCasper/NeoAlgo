/**
 * Ackermann Function is a function with 2 aguments ( A(m,n) ). Each argument can be assigned any non negative integer
 * in A(m,n),
    * If m=0, then A(m,n) = n+1
    * If m != 0 but n=0, A(m,n)=A(m-1,1)
    * If m and n both are not zero then... A(m,n) = A( m-1, A(m,n-1) )
 *  */

import 'dart:io';

int Ackermann_Function(int m, int n) {
  if (m == 0)
    return n + 1;
  else if (m > 0 && n == 0)
    return Ackermann_Function(m - 1, 1);
  else if (m > 0 && n > 0) return Ackermann_Function(m - 1, Ackermann_Function(m, n - 1));

  return 0;
}

void main() {
  print("Input first Number");
  int m = int.parse(stdin.readLineSync()!);
  print("Input second Number");
  int n = int.parse(stdin.readLineSync()!);
  int result = Ackermann_Function(m, n);
  print("Result: $result");
}

/*
 * Time complexity:-O(2^(2^n)) to compute A(m, n). 
    Ackermann's function is like the upper bound for primitive recursive functions. Also, O(2^(2^n)) time complexity is much worse than n^n. 
 
 * Space complexity:- O(m) to compute A(m, n)

Examples:-

Input first Number
1
Input second Number
2
Result: 4

Input first Number
3
Input second Number
3
Result: 61
*/
