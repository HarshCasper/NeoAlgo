/*
k largest elements in an array by using DART.

Given an array, find K largest elements from it.
*/
import 'dart:io';

List K_largest(var array, int k) {
  // sorting the array in descending order
  array.sort();
  array = new List.from(array.reversed);

  // List to store K elements.
  var kLarge = [];
  for (int i = 0; i < k; i++) {
    kLarge.add(array[i]);
  }
  return kLarge;
}

void main() {
  var data = [];

  // taking input from user and storing it in data array
  var n, ele, k;
  print('Enter the number of Elements: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  print("Enter size of K: ");
  k = stdin.readLineSync();
  k = int.parse(k);

  for (int i = 1; i <= n; i++) {
    print('Enter Element $i: ');
    ele = stdin.readLineSync();
    ele = int.parse(ele);
    data.add(ele);
  }

  print("Entered List is: ");
  print(data);

  print("\nK Largest element are: ");
  var k_element = K_largest(data, k);
  print(k_element);
}

/*
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(k)

SAMPLE INPUT/OUTPUT:
Enter the number of Elements: 
5
Enter size of K: 
3
Enter Element 1: 
10
Enter Element 2: 
22
Enter Element 3: 
45
Enter Element 4: 
11 
Enter Element 5: 
2
Entered List is: 
[10, 22, 45, 11, 2]

K Largest element are:
[45, 22, 11]
*/
