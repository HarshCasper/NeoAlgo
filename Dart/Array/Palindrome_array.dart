/*
Check wether the array is Palindrome by using DART.

Given an array of integers, check wether the array is Palindrome or not.
*/

import 'dart:io';

int palindrome_array(var array, int len) {
  int flag = 0;
  for (int i = 0; i <= len ~/ 2; i++) {
    if (array[i] != array[len - i - 1]) {
      flag = 1;
      break;
    }
  }
  return flag;
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
  int ans = palindrome_array(data, n);
  if (ans == 1)
    print("Array is not a Palindrome");
  else
    print("Array is a Palindrome");
}

/*
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)

Example 1:

Enter the number of Elements: 
3
Enter Element 1: 
1
Enter Element 2:
2
Enter Element 3:
3

Inputted array is [1, 2, 3]
Array is not a Palindrome

Example 2:

Enter the number of Elements: 
5
Enter Element 1: 
1
Enter Element 2: 
2
Enter Element 3: 
3
Enter Element 4: 
2
Enter Element 5: 
1

Inputted array is [1, 2, 3, 2, 1]
Array is a Palindrome
*/
