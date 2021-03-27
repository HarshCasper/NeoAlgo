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
  for (int i = 0; i < listSize; i++) {
    int userInput = int.parse(stdin.readLineSync()!);
    listUser.add(userInput);
  }
  print("Enter Element to search: ");
  int toFind = int.parse(stdin.readLineSync()!);
  print(linearSearch(listUser, toFind));
}
