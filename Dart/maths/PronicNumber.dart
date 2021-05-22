/*
The numbers that can be arranged to form a rectangle are called Pronic Numbers.
(also known as Rectangular Numbers).
Pronic number is a number which is the product of two consecutive integers, 
i.e., a number n is a product of x and (x+1). 

Some of the Pronic numbers are: 0, 2, 6, 12, 20, 30, and so on.
*/

import 'dart:io';
import 'dart:math';

bool checkPronic(int key) {
  int sq = sqrt(key).floor();
  for (int i = 0; i <= sq; i++) {
    // Checking if key is a Pronic Number by multiplying consecutive numbers
    if (key == i * (i + 1)) {
      return true;
    }
  }

  return false;
}

main() {
  // Taking user input
  var number;
  print('Enter a number: ');
  number = stdin.readLineSync();
  number = int.parse(number);

  // Function to check if a number is Pronic
  bool result = checkPronic(number);

  // Displaying the results
  if (result)
    print('$number is a Pronic Number');
  else
    print('$number is not a Pronic Number');
}

/*
TIME COMPLEXITY: O(n)

SPACE COMPLEXITY: O(1)

SAMPLE I/O:
Enter a number: 
12
12 is a Pronic Number

Enter a number: 
14
14 is not a Pronic Number
*/
