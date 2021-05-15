/* 
Finding Modular multiplicative inverse by using DART.

Given two integers ‘n’ and ‘m’, find modular multiplicative inverse of ‘n’ 
under modulo ‘m’.
The modular multiplicative inverse is an integer ‘i’ such that. 

n i ≅ 1 (mod m)
*/

import 'dart:io';

int modulo_inverse(int n, int m) {
  int mod = m;
  for (int i = 1; i < m; i++) {
    if (((n % m) * (i % m)) % m == 1) {
      mod = i;
      break;
    }
  }
  return mod;
}

void main() {
  // taking input from user
  var n, m;
  print('Enter the element: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  print('Enter the modulo: ');
  m = stdin.readLineSync();
  m = int.parse(m);

  int mod_inv;
  print("\nModular multiplicative inverse of ‘$n’ under modulo ‘$m’ is: ");
  mod_inv = modulo_inverse(n, m);
  print(mod_inv);
}

/*
TIME COMPLEXITY: O(n).
SPACE COMPLEXITY: O(1).

SAMPLE INPUT/OUTPUT:
Enter the element: 
11
Enter the modulo: 
28

Modular multiplicative inverse of ‘11’ under modulo ‘28’ is:
23
*/
