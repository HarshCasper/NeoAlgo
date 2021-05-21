/*
Segregate Even and Odd numbers of an Array by using DART.

Given an array of integers, segregate the numbers into two groups of even and
odd.
*/

import 'dart:io';

void segregate_even_odd(var array, int len) {
  int j = -1;

  for (int i = 0; i < len; i++) {
    if (array[i] % 2 == 0) {
      j++;

      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
}

void main() {
  var data = [];

  // taking input from user and storing it in data array
  var n, ele;
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
  segregate_even_odd(data, n);
  print("Array after segregating is $data");
}

/*
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

Enter the number of Elements:
7
Enter Element 1: 
12
Enter Element 2: 
3
Enter Element 3: 
54
Enter Element 4: 
1
Enter Element 5: 
11
Enter Element 6: 
22
Enter Element 7: 
3

Inputted array is [12, 3, 54, 1, 11, 22, 3]
Array after segregating is [12, 22, 54, 1, 11, 3, 3]
*/
