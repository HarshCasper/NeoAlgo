import 'dart:io'; // we need this to use stdin

bubbleSort(List array) {
  int size = array.length;
  for (int outer = 0; outer < size - 1; outer++) {
    for (int inner = 0; inner < size - outer - 1; inner++) {
      if (array[inner] > array[inner + 1]) {
        // Swapping
        int temp = array[inner];
        array[inner] = array[inner + 1];
        array[inner + 1] = temp;
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
  for (int i = 0; i < listSize; i++) {
    int userInput = int.parse(stdin.readLineSync()!);
    listUser.add(userInput);
  }
  print(bubbleSort(listUser));
}
