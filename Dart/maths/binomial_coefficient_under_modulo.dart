/*
This algorithm is used to calculate nCr under some mod.

nCr = factorial(n)/(factorial(r)*factorial(n-r))

nCr%mod = factorial(n)*inverse(factorial(r))%mod*inverse(factorial(n-r)%mod)%mod (here inverse is modinverse)

We use Fermat's little theorem to calculate modinverse of a value
According to Fermat's little theorem 
num^(p-1)=1(mod p)
Multiplying by side by num^-1, we get
num^(p-2)=num^-1(mod p)

So, to get inverse, we need to calulate (mod-2)th power of num under modulo mod.
*/

import 'dart:io';

int inverse(int val, int mod) {
  int power = mod - 2;
  int answer = 1;
  while (power > 0) {
    if (power % 2 == 1) {
      answer = ((answer * val).floor() % mod).floor();
    }
    val = ((val * val).floor() % mod).floor();
    power = (power / 2).floor();
  }
  return answer;
}

int nCr(int n, int r, int mod) {
  late int facn, facr, facnr;
  int curr_value = 1;
  for (int i = 1; i <= n; ++i) {
    curr_value = curr_value * i;
    if (i == n) {
      facn = curr_value;
    }
    if (i == r) {
      facr = curr_value;
    }
    if (i == n - r) {
      facnr = curr_value;
    }
  }
  int answer = facn * inverse(facr, mod) % mod * inverse(facnr % mod, mod) % mod;
  return answer;
}

void main() {
  int n, r, mod;
  print("Enter value of n: ");
  n =  int.parse(stdin.readLineSync()!);
  print("Enter value of r: ");
  r = int.parse(stdin.readLineSync()!);
  print("Enter value of mod: ");
  mod = int.parse(stdin.readLineSync()!);
  int nCrUnderMod = nCr(n, r, mod);
  print("nCr%mod = $nCrUnderMod");
}

/*
Sample I/O

1. 
    INPUT 
    Enter value of n: 3
    Enter value of r: 2
    Enter value of mod: 1
    OUTPUT
    nCr%mod = 0
2.
    INPUT
    Enter value of n: 11
    Enter value of r: 7 
    Enter value of mod: 13
    OUTPUT
    nCr%mod = 5
*/

/*
  Time Complexity: O(n)
  Space Complexity: O(1)
*/
