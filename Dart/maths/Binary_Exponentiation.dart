// Dart Program to find Binary Exponent Iteratively and Recursively.

import 'dart:io';

// Iterative function to calculate exponent.

int binExpo_iterate(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b % 2 != 0) {
      res = res * a;
    }
    a = a * a;
    b = (b / 2).floor();
  }
  return res;
}

// Recursive function to calculate exponent.

int binExpo_recurse(int a, int b) {
  if (b == 0) {
    return 1;
  }
  int res = binExpo_recurse(a, (b / 2).floor());
  if (b % 2 != 0) {
    return res * res * a;
  } else {
    return res * res;
  }
}

// Main function

void main() {
  print("Lets calculate Binary Exponent a^b");
  print("Enter a");
  int a = int.parse(stdin.readLineSync());
  
  print("Enter b");
  int b = int.parse(stdin.readLineSync());

  if (a == 0 && b == 0) {
    print("Math Error");
  } else if (b < 0) {
    print("Exponent must be Positive");
  } else {
    int resIterate = binExpo_iterate(a, b);
    int resRecurse = binExpo_recurse(a, b);

    print(resIterate);
    print(resRecurse);
  }
}

/**
Sample Input and Output :

Lets calculate Binary Exponent a^b
Enter a
3
Enter b
5
243
243


Time complexity = O(n)
Space complexity = O(1)
 */
