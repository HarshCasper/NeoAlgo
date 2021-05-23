/*
The script below determines if a number is Trimorphic or not.
A trimorphic number is whose cube's last digits are equal to the actual number.
*/

import 'dart:io';

// Function to check if a number is Trimorphic or not
bool checkTrimorphic(int no) {
  // Cubing the number
  int cube = no * no * no;

  // checking if the last digits of the cube is exactly equal to the given number
  while (no > 0) {
    // If a digit is not equal, we can say it is not trimorphic
    if (no % 10 != cube % 10) return false;

    // Obtaining each digit of the number and cube respectively
    no = (no / 10).floor();
    cube = (cube / 10).floor();
  }

  return true;
}

main() {
  // Taking user input
  var number;
  print('Enter a number: ');
  number = stdin.readLineSync();
  number = int.parse(number);

  bool result = checkTrimorphic(number);

  // Displaying results
  if (result)
    print('$number is a Trimorphic Number');
  else
    print('$number is not a Trimorphic Number');
}

/*
TIME COMPLEXITY: O(log N)
SPACE COMPLECITY: O(1)

SAMPLE I/O 1:
Enter a number: 
12
12 is not a Trimorphic Number
Explanaton: 12*12*12 = 1728

SAMPLE I/O 2:
Enter a number: 
9
9 is a Trimorphic Number
Explanation: 9*9*9 = 729
*/
