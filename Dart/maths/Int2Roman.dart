/*
Given a number, we find its corresponding Roman numeral.
*/

import 'dart:io';

String int2Roman(int number) {
  var roman = "";
  var num_arr = [1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000];
  var sym = [
    "I",
    "IV",
    "V",
    "IX",
    "X",
    "XL",
    "L",
    "XC",
    "C",
    "CD",
    "D",
    "CM",
    "M"
  ];
  int i = 12;
  while (number > 0) {
    int div = number ~/ num_arr[i];
    number = number % num_arr[i];
    while (div-- != 0) {
      roman += sym[i];
    }
    i--;
  }
  return roman;
}

void main() {
  // taking input from user
  var n;
  print('Enter a number: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  String roman = int2Roman(n);
  print("Roman number of $n is $roman");
}

/*
TIME COMPLEXITY: O(logN)
SPACE COMPLEXITY: O(1)

Example 1:
Enter a number:
78
Roman number of 78 is LXXVIII

Example 2:
Enter a number: 
56
Roman number of 56 is LVI
*/
