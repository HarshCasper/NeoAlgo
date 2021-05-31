/*
Remove duplicates from an array by using DART.

Given an array, remove duplicate element from it so
that it only consists of unique elements in the array.
*/

import 'dart:io';

void duplicates(var array) {
  // sorting the array
  array.sort();
  for (int i = 0; i < array.length - 1; i++) {
    // checking if the next element is same
    if (array[i] == array[i + 1]) {
      array.remove(array[i + 1]);
      i -= 1;
    }
  }
}

void main() {
  var data = [];

  // taking input from user and storing it in data array
  var n, ele;
  print('Enter the number of Elements: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  for (int i = 1; i <= n; i++) {
    print('Enter Element $i: ');
    ele = stdin.readLineSync();
    ele = int.parse(ele);
    data.add(ele);
  }

  print("Entered List is: ");
  print(data);

  print("\nList after removing duplicates: ");
  duplicates(data);
  print(data);
}

/*
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

SAMPLE INPUT/OUTPUT:
Enter the number of Elements:
5
Enter Element 1:
1
Enter Element 2:
2
Enter Element 3:
2
Enter Element 4:
1
Enter Element 5:
3
Entered List is:
[1, 2, 2, 1, 3]

List after removing duplicates:
[1, 2, 3]
*/
