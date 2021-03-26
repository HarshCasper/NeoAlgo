import 'dart:io'; // we need this to use stdin

selectionSort(List array) {
  int size = array.length;
  for (int steps = 0; steps < size; steps++) {
    for (int forward = steps + 1; forward < size; forward++) {
      if (array[steps] > array[forward]) {
        int temp = array[steps];
        array[steps] = array[forward];
        array[forward] = temp;
      }
    }
  }
  return (array);
}

void main() {
  //Driver code
  print("Enter List size: ");
  int listSize = int.parse(stdin.readLineSync()!);
  var listUser = [];
  for (int index = 0; index < listSize; index++) {
    int userInput = int.parse(stdin.readLineSync()!);
    listUser.add(userInput);
  }
  print(selectionSort(listUser));
}
