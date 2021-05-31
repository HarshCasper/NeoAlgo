/*
Implementing Stooge Sort by using DART.

Stooge Sort is a recursive sorting algorithm. It is inefficient but interesting 
sorting algorithm. It divides the array into two overlapping parts (2/3 each). 
Then it performs sorting in first 2/3 part and then it performs sorting in last 
2/3 part. After that, sorting is done on first 2/3 part to ensure the array is 
sorted.

*/
import 'dart:io';

void stoogeSort(var array, int start, int end) {
  // swapping first and last element if start is greater than end
  if (array[start] > array[end]) {
    int temp = array[start];
    array[start] = array[end];
    array[end] = temp;
  }

  // If there are more than 2 elements
  if ((end - start + 1) > 2) {
    int two_third = (end - start + 1) ~/ 3;

    // Recursively sort first 2/3 elements
    if ((end - two_third) >= start) stoogeSort(array, start, end - two_third);
    // Recursively sort last 2/3 elements
    if (end >= (start + two_third)) stoogeSort(array, start + two_third, end);
    // Recursively sort first 2/3 elements again for conformation
    if ((end - two_third) >= start) stoogeSort(array, start, end - two_third);
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

  print("\nInputted array is $data");
  stoogeSort(data, 0, n - 1);
  print("\nArray after sorting is $data");
}
/*
Time Complexity: O(n^2.7095)
Space Complexity: O(n)

Sample I/O:
Enter the number of Elements: 
6
Enter Element 1: 
36
Enter Element 2: 
2
Enter Element 3: 
73
Enter Element 4: 
11
Enter Element 5: 
95
Enter Element 6: 
100

Inputted array is [36, 2, 73, 11, 95, 100]

Array after sorting is [2, 11, 36, 73, 95, 100]
*/
