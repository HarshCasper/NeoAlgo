/*

  Euler's Totient Function in Dart

  The result of the Euler's Totient Function for a number n (F(n)) 
  denotes the number of coprimes of n from 1 to n
*/

import 'dart:io';

int totientFunction(int n) {
  var arr = new List(n + 1);

  int i, j;

  arr[0] = 0;
  arr[1] = 1; // as 1 is coprime with itself

  for (i = 2; i <= n; i++) {
    arr[i] = i;
  }

  /*
    in each iteration, we find the number of coprimes of 
    that particular "i". So in the end we get return the 
    last element of the array which has the number of coprimes result.

    For example 
    if n = 8
    before this loop arr[] = [0, 1, 2, 3, 4, 5, 6, 7, 8]
    after this loop  arr[] = [0, 1, 1, 2, 2, 4, 2, 6, 4]
    Observe how every number represents its own number of coprimes
  */
  for (i = 2; i <= n; i++) {
    if (arr[i] == i) {
      for (j = i; j <= n; j += i) {
        arr[j] = arr[j] - (arr[j] / i).floor();
      }
    }
  }
  return arr[n];
}

int main() {
  stdout.write("Enter a integer: ");

  int n = int.parse(stdin.readLineSync()); // taking input as integer n

  stdout.write("no. of coprime of $n from 1 to $n: ");
  stdout.write(totientFunction(n)); // printing Euler's Totient Function for int n
  print(" ");
  return 0;
}

/*

  SAMPLE TESTS

  SAMPLE TEST 1
  Enter a integer: 5
  no. of coprimes of 5 from 1 to 5: 4
  
  Explanation
  As 5 is a prime no. so it is coprime with all 1, 2, 3 & 4.
  Therefore, its Euler's Totient Function value is 4;


  SAMPLE TEST 2
  Enter a integer: 4
  no. of coprimes of 4 from 1 to 4: 2

  Explanation
  4 is coprime with 1 and 2 only.
  Therefore its Euler's Totient function value is 2

  
  Time Complexity O(n)
  Space complexity O(n)
*/
