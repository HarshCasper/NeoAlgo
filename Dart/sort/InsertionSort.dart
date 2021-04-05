/**
Function to sort a list of inputs using Insertion sort technique.
In every iteration we choose one value and put it at a position after
comparing it with all the other elements before it in the list.
 */
import 'dart:io';

// function that implements insertion sort
List insertionSort(List arr) {
  // this loop runs from 2nd element
  for (int i = 1; i < arr.length; i++) {
    int k = i - 1;
    int temp = arr[i];
    // this loop compares all elements before temp with temp
    // and changes positions
    while (k >= 0 && arr[k] > temp) {
      arr[k + 1] = arr[k];
      k--;
    }
    // after shifting we have one spot for temp, so we place it there
    // and close the loop
    arr[k + 1] = temp;
  }
  return arr;
}

// main function, entry point of the program
void main() {
  print("Enter the size of list:");
  int size = int.parse(stdin.readLineSync()!);
  List arr = [];
  print("Enter the numbers:");
  for (int i = 0; i < size; i++) {
    arr.add(int.parse(stdin.readLineSync()!));
  }
  // sorting
  arr = insertionSort(arr);
  print("Sorted list:");
  for (int i = 0; i < size; i++) {
    print(arr[i]);
  }
}

/**
Enter the size of list:
6
Enter the numbers:
5
0
2
1
4
3
Sorted list:
0
1
2
3
4
5

Time Complexity: O(n*2)
Space Complexity: O(1)
 */
