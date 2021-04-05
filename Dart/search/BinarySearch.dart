/**
Function to search for a given element in a list using binary search algorithm.
For this algorithm we need a sorted list. After getting the list, we compare
the value of the element to be searched with the middle value and then search
for it either in the half before the middle element or after it. This way our
search area gets reduced by half.
 */
import 'dart:io';

//function which runs the binary search algorithm
int binarySearch(List arr, int num) {
  // initial bounds of array
  int low = 0;
  int high = arr.length - 1;

  while (low <= high) {
    // find middle position of the bounds
    int mid = (low + high) ~/ 2;
    // if num is found, return index
    if (arr[mid] == num) {
      return mid;
    }
    // if num > mid, that means it might be in the 2nd half of the list
    // so we increase the lower bound by 1 to get into that half
    else if (arr[mid] < num) {
      low++;
    }
    // else if num < mid, we try for first half by decreasing upper bound
    else {
      high--;
    }
  }
  // return invalid index to show that element is not in the list
  return -1;
}

// main function, entry point of program
void main() {
  print("Enter the size of list:");
  int size = int.parse(stdin.readLineSync()!);
  List arr = [];
  print("Enter the sorted list:");
  for (int i = 0; i < size; i++) {
    arr.add(int.parse(stdin.readLineSync()!));
  }
  print("Enter the number to be searched:");
  int num = int.parse(stdin.readLineSync()!);
  // sorting
  int result = binarySearch(arr, num);
  if (result != -1) {
    print("$num found at position: ${result + 1}");
  } else {
    print("$num not found in the list.");
  }
}

/**
Enter the size of list:
6
Enter the sorted list:
12
25
32
47
56
68
Enter the number to be searched:
47
47 found at position: 4

Time complexity: O(log n)
Space complexity: O(1)
 */
