// function to sort the list
import 'dart:io';

List bubbleSort(List arr) {
  int len = arr.length;
  int temp = 0;
  for (int i = 0; i < len; i++) {
    bool isSorted = true;
    for (int j = 1; j < (len - i); j++) {
      if (arr[j - 1] > arr[j]) {
        // swap elements
        temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        isSorted = false;
      }
    }
    if (isSorted) {
      break;
    }
  }
  return arr;
}

// Main function, entry point of the program
void main() {
  print("Enter the size of list:");
  int size = int.parse(stdin.readLineSync()!);
  List arr = [];
  print("Enter the numbers:");
  for (int i = 0; i < size; i++) {
    arr.add(int.parse(stdin.readLineSync()!));
  }
  // sorting
  arr = bubbleSort(arr);
  print("Sorted list:");
  for (int i = 0; i < size; i++) {
    print(arr[i]);
  }
}
/**
 * Space complexity: O(1)
 * Time complexity: O(n^2) {worst} / O(n) {best}
 * Enter the size of list:
 * 10
 * Enter the numbers:
 * 9
 * 8
 * 7
 * 6
 * 5
 * 4
 * 3
 * 2
 * 1
 * 0
 * Sorted list:
 * 0
 * 1
 * 2
 * 3
 * 4
 * 5
 * 6
 * 7
 * 8
 * 9
 */
