/* 
Quick Sort in Dart

Quicksort algorithm is based on the divide and conquer approach where
  1. An array is divided into subarrays by selecting a pivot element.
  2. The left and right subarrays are also divided using the same approach. 
    This process continues until each subarray contains a single element.
  3. At this point, elements are already sorted. Finally, elements are 
    combined to form a sorted array.
*/

import 'dart:io';

// function to find the partition position
int partition(var array, int low, int high) {
  // choosing rightmost element as pivot
  int pivot = array[high];
  // pointer for greater element
  int i = low - 1;

  for (int j = low; j < high; j++) {
    // compare each element with pivot
    if (array[j] <= pivot) {
      i = i + 1;
      // if element smaller than pivot is found swap it i
      int temp = array[j];
      array[j] = array[i];
      array[i] = temp;
    }
  }
  // swapping pivot with greater element
  int temp = array[i + 1];
  array[i + 1] = array[high];
  array[high] = temp;

  // return the position from where partition is done
  return i + 1;
}

// function to perform quicksort
void quickSort(array, low, high) {
  if (low < high) {
    // find pivot element such that
    // element smaller than pivot are on left and greater than are at right
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

// main function
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

  // Implementing quick sort
  quickSort(data, 0, n - 1);

  // displaying sorted array
  print(data);
}

/*

Time Complexities:
  1. Worst Case Complexity : O(n^2)
  2. Best Case Complexity : O(n*log n)
  3. Average Case Complexity : O(n*log n)

Space Complexity : O(log n)

INPUT :-
Enter the number of Elements: 
5
Enter Element 1: 
20
Enter Element 2: 
10
Enter Element 3: 
44
Enter Element 4:
33
Enter Element 5:
99

Output :-
[10, 20, 33, 44, 99]
*/
