/*
Radix Sort in Dart.

Radix sort is a sorting algorithm that sorts the elements by first grouping 
the individual digits of the same place value. Then, sort the elements 
according to their increasing/decreasing order.
*/

import 'dart:io';

void counting_sort(var arr, int size, int place) {
  int max = 10;
  List out = new List.filled(size, null, growable: false);
  List count = new List.filled(max, null, growable: false);

  for (int i = 0; i < max; ++i) count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++) {
    int places = (arr[i] ~/ place) % 10;
    count[places]++;
  }

  // Calculate cummulative count
  for (int i = 1; i < max; i++) count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    int places = (arr[i] ~/ place) % 10;
    int pos = count[places] - 1;
    out[pos] = arr[i];
    count[places]--;
  }

  // changing position based on places sorting
  for (int i = 0; i < size; i++) arr[i] = out[i];
}

void radix_sort(var arr, int size) {
  // max element to calculate significant digits
  int max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max) max == arr[i];
  }

  // place
  for (int place = 1; max / place > 0; place *= 10) {
    counting_sort(arr, size, place);
  }
}

void main() {
  var arr = [];

  // User inputs
  var n, each;
  print('Enter the number of Elements: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  for (int i = 1; i <= n; i++) {
    print('Enter Element $i: ');
    each = stdin.readLineSync();
    each = int.parse(each);
    arr.add(each);
  }

  // Applying Radix Sort
  radix_sort(arr, n);

  print(arr);
}

/*
Time Complexity : O(n*k/d)
Space Complexity : O(n+2^d)
where, 
    k = maximum possible value
    d = no. of digits 

SAMPLE I/O:
Enter the number of Elements:
6
Enter Element 1: 
12
Enter Element 2: 
33
Enter Element 3: 
4
Enter Element 4: 
1
Enter Element 5: 
1000
Enter Element 6:
9

[1, 4, 9, 12, 33, 1000]
 */
