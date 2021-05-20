/*
If the ratio of any two consecutive terms is always same for a series, then the 
given series is said to be in Geometric Progression.

In the below code we check if a given list of elements is in GP or not.
*/

import 'dart:io';
import 'dart:math';

bool checkGP(List arr, int n) {
  if (n == 1) return true;

  // Calculate ratio
  int r = arr[1] ~/ arr[0];

  // Check if the ratio is common between the consecutive elements
  for (int i = 1; i < n; i++) {
    if ((arr[i] / (arr[i - 1])) != r) {
      return false;
    }
  }
  return true;
}

main() {
  // Driver code to take user input
  var array = [];

  var n, ele;
  print('Enter the number of elements: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  for (int i = 1; i <= n; i++) {
    print('Enter value for element $i: ');
    ele = stdin.readLineSync();
    ele = int.parse(ele);
    array.add(ele);
  }

  print('The given list of elements is: $array');

  if (checkGP(array, n))
    print('The given series is in GP');
  else
    print('The given series is not in GP');
}

/*

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(1)

SAMPLE I/O:
Enter the number of elements: 
6
Enter value for element 1: 
2
Enter value for element 2: 
6
Enter value for element 3: 
18
Enter value for element 4: 
54
Enter value for element 5: 
162
Enter value for element 6: 
486
The given list of elements is: [2, 6, 18, 54, 162, 486]
The given series is in GP

*/
