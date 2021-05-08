/**
Sorting algorithm that is also called Gravity Sort. It can be visualised as
beads of an abacus falling under the influence fo gravity with the row having
the most beads is at the bottom and least is at top.
 */
import 'dart:io';

enum SortStatus { BEAD, BLANK, NULL }
// function that implements bead sort
List beadSort(List arr) {
  // finding max item to decide width of the abacus
  int max = 0;
  for (int item in arr) {
    if (item > max) {
      max = item;
    }
  }

  // setting the abacus
  List abacus = List.generate(arr.length, (index) => new List.filled(max, SortStatus.NULL),
      growable: false);
  List level = [];
  for (int i = 0; i < max; i++) {
    level.add(0);
    for (int j = 0; j < arr.length; j++) {
      abacus[j][i] = SortStatus.BLANK;
    }
  }

  // adding the beads
  for (int item in arr) {
    for (int j = 0; item > 0; j++, item--) {
      abacus[level[j]++][j] = SortStatus.BEAD;
    }
  }

  // counting beads
  for (int i = 0; i < arr.length; i++) {
    int number = 0;
    for (int j = 0;
        j < max && abacus[arr.length - 1 - i][j] == SortStatus.BEAD;
        j++) {
      number++;
    }
    arr[i] = number;
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
  arr = beadSort(arr);
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
Enter number of buckets:
5
Sorted list:
0
1
2
3
4
5

Time Complexity: O(n)
Space Complexity: O(n^2)
 */
