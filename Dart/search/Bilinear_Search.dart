/*
Implementing Bilinear search by using DART.

Given an array of integers, check wether the element to search exists or not in
the array, and if it exists find its position.
*/
import 'dart:io';

int bilinearSearch(var array, int key) {
  int front = 0;
  int back = array.length - 1;

  while (front <= back) {
    if (array[front] == key) return front + 1;
    if (array[back] == key) return back + 1;
    front += 1;
    back -= 1;
  }
  return -1;
}

void main() {
  var data = [];

  // taking input from user and storing it in data array
  var n, ele, key;
  print('Enter the number of Elements: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  for (int i = 1; i <= n; i++) {
    print('Enter Element $i: ');
    ele = stdin.readLineSync();
    ele = int.parse(ele);
    data.add(ele);
  }

  print("\nInputted array is $data");

  print("\nEntered the element you want to search: ");
  key = stdin.readLineSync();
  key = int.parse(key);

  int found = bilinearSearch(data, key);
  if (found != -1)
    print("Element found at position: $found");
  else
    print("Element not found!!!");
}

/*
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

Sample I/O:
Example 1:

Enter the number of Elements: 
5
Enter Element 1: 
2
Enter Element 2: 
23
Enter Element 3: 
4
Enter Element 4: 
5
Enter Element 5: 
6

Inputted array is [2, 23, 4, 5, 6]

Entered the element you want to search:
7
Element not found!!!

Example 2:

Enter the number of Elements: 
5
Enter Element 1: 
89
Enter Element 2: 
34
Enter Element 3: 
16
Enter Element 4: 
60
Enter Element 5: 
33

Inputted array is [89, 34, 16, 60, 33]

Entered the element you want to search:
16
Element found at position: 3
*/
