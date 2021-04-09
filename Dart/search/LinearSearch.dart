/**
 A linear search or sequential search is a method for finding an element within a list.
 It sequentially checks each element of the list until a match is found or the whole list has been searched
 */
import 'dart:io';

linearSearch(List array, int toFind) {
  for (int index = 0; index < array.length; index++) {
    if (array[index] == toFind) {
      // If element is found return index at which it is found
      return index;
    }
  }
  // If element is not found return -1
  return -1;
}

void main() {
  //Driver code
  print("Enter List size: ");
  int listSize = int.parse(stdin.readLineSync()!);
  var listUser = [];

  // Take list input
  print("Enter $listSize elements: ");
  for (int i = 0; i < listSize; i++) {
    int userInput = int.parse(stdin.readLineSync()!);
    listUser.add(userInput);
  }
  print("Enter Element to search: ");
  int toFind = int.parse(stdin.readLineSync()!);
  // Search and display result
  int result = linearSearch(listUser, toFind);
  if (result == -1) {
    print("$toFind not found in list");
  } else {
    print("$toFind found at index $result");
  }
}

/**
Time complexity: O(n)
Space complexity: O(1)

Enter List size:
5
Enter 5 elements:
1
2
3
4
5
Enter Element to search:
4
4 found at index 3
 */
