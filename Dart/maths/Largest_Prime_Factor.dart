/* 
Finding largest prime factor of a given number by using DART.

Given a positive integer, find largest prime factor.
*/

import 'dart:io';

int largest_Prime_Factor(int n) {
  int larg_prime = -1;
  // return larg_prime;

  // if there is a number divisible by 2 then remove all 2s which can are
  // dividing that number so that we can focus on more greater prime number
  while (n % 2 == 0) {
    larg_prime = 2;
    n = n ~/ 2;
  }

  for (int i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      larg_prime = i;
      n = n ~/ i;
    }
  }

  // when n itself is a prime number then we considering it here
  if (n > 2) larg_prime = n;

  return larg_prime;
}

void main() {
  // taking input from user
  var n;
  print('Enter the element: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  int prime;
  print("\nLargest prime number of $n is: ");
  prime = largest_Prime_Factor(n);
  print(prime);
}

/*
TIME COMPLEXITY: O(√n).
SPACE COMPLEXITY: O(1).

SAMPLE INPUT/OUTPUT:
Enter the element: 
99

Largest prime number of 99 is:
11
*/
