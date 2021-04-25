/*
Sentinel Search implementation in Dart
In this search, the last element of the array is replaced with the 
element to be searched and then the linear search is performed on the array. 
*/

import 'dart:io';

bool Sentinel_Search(List arr, int n, int val) {
  // Storing the last element and replacing it with the value to be searched
  int last_ele = arr[n - 1];
  arr[n - 1] = val;

  int i = 0;
  // Iterating over the list until we find the value to be searched
  while (arr[i] != val) {
    i += 1;
  }

  // Replacing the last element of list
  arr[n - 1] = last_ele;

  if (i < (n - 1) || arr[n - 1] == val) {
    return true;
  }
  return false;
}

main() {
  var array = [];

  var n, ele, key;
  print('Enter the number of elements: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  for (int i = 1; i <= n; i++) {
    print('Enter value for element $i: ');
    ele = stdin.readLineSync();
    ele = int.parse(ele);
    array.add(ele);
  }

  print('Enter the element to be searched: ');
  key = stdin.readLineSync();
  key = int.parse(key);

  bool status = Sentinel_Search(array, n, key);
  if (status) {
    print('Element is present in array');
  } else {
    print('Element is not present in array');
  }
}

/*

TIME COMPLEXITY: O(n)

SPACE COMPLEXITY: O(1)


Enter the number of elements: 
6
Enter value for element 1: 
12
Enter value for element 2: 
43
Enter value for element 3: 
33
Enter value for element 4: 
56
Enter value for element 5: 
12
Enter value for element 6: 
90
Enter the element to be searched: 
43
Element is present in array

*/
