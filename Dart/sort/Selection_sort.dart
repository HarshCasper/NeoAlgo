/* 
Selection Sort implementation in Dart
In this algorithm array is sorted by repeatedly finding the minimum element 
from unsorted part of the array and putting it at the beginning. 
*/

import 'dart:io';

void Selection_Sort(List arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[i]) {
        // Swapping the elements
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
      }
    }
  }
}

main() {
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

  Selection_Sort(array, n);
  print('The sorted array is $array');
}

/*

TIME COMPLEXITY: O(n^2)

SPACE COMPLEXITY: O(1)


Sample Input/Output:

Enter the number of elements: 
6
Enter value for element 1: 
89
Enter value for element 2: 
45
Enter value for element 3: 
12
Enter value for element 4: 
34
Enter value for element 5: 
1
Enter value for element 6: 
9
The sorted array is [1, 9, 12, 34, 45, 89]

*/
