/*
Reverse an array in groups of given size by using DART.

Given an array, reverse every subarray formed by 
consecutive k elements.
*/

import 'dart:io';

void reverse_array_groups(var array, int n, int k) {
  // going group by group using forloop.
  for (int i = 0; i < n; i += k) {
    int left = i;
    int right;
    if (i + k - 1 > n - 1)
      right = n - 1;
    else
      right = i + k - 1;

    // reversing the subarray.
    while (left < right) {
      int temp = array[left];
      array[left] = array[right];
      array[right] = temp;
      left++;
      right--;
    }
  }
}

void main() {
  var data = [];

  // taking input from user and storing it in data array
  var n, ele, k;
  print('Enter the number of Elements: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  print('Enter group size: ');
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

  print("\nList after reversing in group is: ");

  reverse_array_groups(data, n - 1, k);
  print(data);
}

/*
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

SAMPLE INPUT/OUTPUT:
Enter the number of Elements: 
7
Enter group size: 
3
Enter Element 1: 
10
Enter Element 2: 
20
Enter Element 3: 
30
Enter Element 4: 
40
Enter Element 5: 
50
Enter Element 6: 
60
Enter Element 7: 
70
Entered List is: 
[10, 20, 30, 40, 50, 60, 70]

List after reversing in group is:
[30, 20, 10, 60, 50, 40, 70]
*/
