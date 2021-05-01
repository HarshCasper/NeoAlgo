/*
Counting Sort in Dart

Counting sort is a sorting algorithm where the number of occurances of each
element of the given array is stored in a frequency counter array which is
used to further map according to their index into the sorted array.
*/

import 'dart:io';

void countSort(List array, int size) {
  // Setting limit for length of array
  const int MAX = 1000;

  // Initializing an array to store sorted elements temporarily
  List temp = new List.filled(MAX, null, growable: false);
  // Initializing array to store count of elements
  List count = new List.filled(MAX, 0, growable: false);

  // Finding the largest element in the array
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }

  // Storing the number of occurances of each element in array at the
  // respective index in count array
  for (int i = 0; i < size; i++) {
    count[array[i]] += 1;
  }

  // Storing the total count of each element
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Placing the elements according to the index of count array in the
  // temporary array
  for (int i = size - 1; i >= 0; i--) {
    temp[count[array[i]] - 1] = array[i];
    count[array[i]] -= 1;
  }

  // Placing elements that are sorted back into the array
  for (int i = 0; i < size; i++) {
    array[i] = temp[i];
  }
}

main() {
  // Taking user input
  var n, ele;
  print('Enter the number of Elements: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  List array = new List.filled(n, null, growable: false);

  for (int i = 0; i < n; i++) {
    print('Enter Element $i: ');
    ele = stdin.readLineSync();
    ele = int.parse(ele);
    array[i] = ele;
  }
  countSort(array, n);
  print('The sorted array is: $array');
}

/*
Time Complexity: O(n+k) where n is the number of elements in input array and k 
is the max element. 
Auxiliary Space: O(n+k)

SAMPLE I/O:
Enter the number of Elements: 
6
Enter Element 0: 
78
Enter Element 1: 
56
Enter Element 2: 
90
Enter Element 3: 
44
Enter Element 4: 
23
Enter Element 5: 
12
The sorted array is: [12, 23, 44, 56, 78, 90]
*/
