/*
Given a sorted array and a value x, find the floor of x in the array.
The floor of x is the largest element in array smaller than or equal to x.
The function shows the implementation of the function, using binary search. 
*/

import 'dart:io';

int findFloor(List arr, int n, int x) {
  // Initializing low and high indices
  int low = 0;
  int high = n - 1;

  // Initialinzing floor value
  int floor_val = -1;

  // Applying binary search
  while (low <= high) {
    // Finding the mid index
    int mid = ((low + high) / 2).floor();

    // If the mid index element is equal to the given element
    if (arr[mid] == x) {
      return arr[mid];
    }

    // If given element is less than mid index element, 
    // performing search on the left of mid index
    if (x < arr[mid]) {
      high = mid - 1;
      continue;
    }

    // If given element is greater than mid index element, 
    // performing search on the right of mid index
    if (x > arr[mid]) {
      floor_val = arr[mid];
      low = mid + 1;
      continue
    }
  }

  return floor_val;
}

main() {
  // Taking user input
  var array = [];

  var n, ele, x;
  print('Enter the number of Elements: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  for (int i = 1; i <= n; i++) {
    print('Enter Element $i: ');
    ele = stdin.readLineSync();
    ele = int.parse(ele);
    array.add(ele);
  }
  array.sort();
  print('The sorted array entered is: $array');

  print('Enter a number X: ');
  x = stdin.readLineSync();
  x = int.parse(x);

  // Calling function to obtain the required results
  int floor = findFloor(array, n, x);
  print("Floor of $x is : $floor");
}

/*
TIME COMPLEXITY: O(log N)
SPACE COMPLEXITY: O(1)

SAMPLE I/O:
Enter the number of Elements: 
7
Enter Element 1: 
1
Enter Element 2: 
2
Enter Element 3: 
8
Enter Element 4: 
8
Enter Element 5: 
18
Enter Element 6: 
27
Enter Element 7: 
35
The sorted array entered is: [1, 2, 8, 8, 18, 27, 35]
Enter a number X: 
9
Floor of 9 is : 8
*/