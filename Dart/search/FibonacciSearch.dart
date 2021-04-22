/**
Program to search a given element using Fibonacci Search. We use Fibonacci
numbers and compare them to the indexes of array elements to divde the array
into smaller parts.
 */
import 'dart:io';
import 'dart:math';

// fibonacci search function
int fiboSearch(List arr, int item, int size) {
  // initialising fibonacci numbers
  int num1 = 0, num2 = 1, fibNum = num1 + num2;

  // fibNum stores the first fibonacci number greater than or equal to
  // the size of the array
  while (fibNum < size) {
    num1 = num2;
    num2 = fibNum;
    fibNum = num2 + num1;
  }

  // marks the eliminated range from the beginning
  int pos = 0;

  // we compare arr[num1] with x. if fibNum = 1 then num1 = 0
  while (fibNum > 1) {
    int i = min(pos + num1, size - 1);

    if (arr[i] > item) {
      // move two down
      fibNum = num1;
      num2 -= num1;
      num1 = fibNum - num2;
    } else if (item > arr[i]) {
      // move one down and reset offset
      fibNum = num2;
      num2 = num1;
      num1 = fibNum - num2;
      pos = i;
    } else {
      // item found
      return i;
    }
  }

  // element not found
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
  int result = fiboSearch(arr, num, size);
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
Best case Time complexity: O(1)
Space complexity: O(1)
 */
