/**
This algorithm is an improvement over Binary Search. In this case we use linear
interpolation from graphical methods and try to find the position of the item,
as if the array elements are on a straight line. 
 */
import 'dart:io';

// function that runs the interpolation
int interpolationSearch(List arr, int item, int first, int last) {
  // checking if the item is present in array range
  if (last >= first && item >= arr[first] && item <= arr[last]) {
    // finding value of position by interpolation
    int position = first +
            ((item - arr[first]) * ((last - first) ~/ (arr[last] - arr[first])))
        as int;

    // checking if this is corect position
    if (arr[position] == item) {
      return position;
    }

    // if item is greater its in right portion
    if (arr[position] < item) {
      return interpolationSearch(arr, item, position + 1, last);
    }

    // if item is smaller then its in the left portion
    if (arr[position] > item) {
      return interpolationSearch(arr, item, first, position - 1);
    }
  }
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
  int item = int.parse(stdin.readLineSync()!);
  // sorting
  int result = interpolationSearch(arr, item, 0, size - 1);
  if (result != -1) {
    print("$item found at position: ${result + 1}");
  } else {
    print("$item not found in the list.");
  }
}

/*

Sample Output:

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

Time complexity: O(log(log n))
Space complexity: O(1)
*/
