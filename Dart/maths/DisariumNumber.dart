/*
The script below determines if a number is Disarium or not.
A disarium number is a number in which the sum of each digit raised to the power
of its position in the number is equal to the actual number.
*/

import 'dart:io';
import 'dart:math';

bool checkDisarium(int no) {
  // Counting the number of digits in the number
  int num_digits = 0;
  int temp1 = no;
  while (temp1 != 0) {
    temp1 = (temp1 / 10).floor();
    num_digits += 1;
  }

  // Getting sum of individual digits raised to the power of their position
  int total = 0;
  int temp2 = no;
  while (temp2 != 0) {
    int last = temp2 % 10;
    total = total + pow(last, num_digits--).toInt();
    temp2 = (temp2 / 10).floor();
  }

  // If the computed sum is equal to the actual number, we return true
  if (total == no) return true;
  return false;
}

main() {
  // Taking user input
  var number;
  print('Enter a number: ');
  number = stdin.readLineSync();
  number = int.parse(number);

  // Function to check if a number is Disarium
  bool result = checkDisarium(number);

  // Displaying the results
  if (result)
    print('$number is a Disarium Number');
  else
    print('$number is not a Disarium Number');
}

/*
TIME COMPLEXITY: O(log N)
SPACE COMPLEXITY: O(1)

SAMPLE I/O 1:
Enter a number: 
89
89 is a Disarium Number
Explanation:
8^1 + 9^2 = 89

SAMPLE I/O 2:
Enter a number: 
49
49 is not a Disarium Number
Explanation:
4^1 + 9^2 = 85
*/
