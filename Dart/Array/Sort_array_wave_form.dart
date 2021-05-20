/*
Sort an array in wave form by using DART.

Given an unsorted array of integers, sort the array into a wave like array.
*/
import 'dart:io';

void wave_sort_array(var array, int n) {
  for (int i = 0; i < n; i += 2) {
    if (i > 0 && array[i - 1] > array[i]) {
      int temp = array[i];
      array[i] = array[i - 1];
      array[i - 1] = temp;
    }

    // If current even element is smaller than next
    if (i < n - 1 && array[i] < array[i + 1]) {
      int temp = array[i];
      array[i] = array[i + 1];
      array[i + 1] = temp;
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

  print("\nElemnts after wave sorting are: ");
  wave_sort_array(data, n);
  print(data);
}

/*
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

Enter the number of Elements: 
6
Enter size of K: 
34
Enter Element 1: 
56
Enter Element 2: 
54
Enter Element 3: 
2
Enter Element 4: 
9
Enter Element 5: 
0
Enter Element 6: 
43
Entered List is: 
[56, 54, 2, 9, 0, 43]

Elemnts after wave sorting are:
[56, 2, 54, 0, 43, 9] 
*/
