/*
Given a series of AP with one element missing, find the missing number.

In the given solution we use the approach of binary search, to find the missing
element.
*/

import 'dart:io';
import 'dart:math';

findMissingAp(List arr, int n) {
  // Calculating the common difference in AP
  int diff = ((arr[n - 1] - arr[0]) / n).floor();

  int low = 0;
  int high = n - 1;

  int flag = 0;
  int result = 0;

  // Performing Binary Search
  while (low <= high) {
    int mid = ((high - low) / 2).floor();

    // If the element before mid is missing
    if (mid > 0 && arr[mid] - arr[mid - 1] != diff) {
      result = arr[mid - 1] + diff;
      flag = 1;
      break;
    }

    // If the element after mid is missing
    if (arr[mid + 1] - arr[mid] != diff) {
      result = arr[mid] + diff;
      flag = 1;
      break;
    }

    // Continuing the search with elements after mid
    if (arr[mid] == arr[0] + (diff * mid)) {
      low = mid + 1;
      continue;
    }

    // Continuing the search with elements before mid
    high = mid - 1;
  }

  if (flag == 1) {
    print('The missing element is: $result');
    return;
  }
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

  findMissingAp(array, n);
}

/*
TIME COMPLEXITY: O(log N)
SPACE COMPLEXITY: O(1)

SAMPLE I/O:
Enter the number of elements: 
6
Enter value for element 1: 
1
Enter value for element 2: 
6
Enter value for element 3: 
11
Enter value for element 4: 
21
Enter value for element 5: 
26
Enter value for element 6: 
31
The missing element is: 16
*/
