/*
Cutting a Rod problem
We are given a rod of length 'n' and the cost of the rod of different length from
1 to n. We need to find the maximum sell price that can be obtained by cutting the rod
at any lengths.
*/

import 'dart:io';

// Function to get maximum selling price
int maximum_sp(int length, List cost) {
  // Initialising dynamic programming list
  List<int> dp = [];
  dp.add(0);

  // iterate to find out all possible prices and push to list
  for (int count1 = 1; count1 <= length; count1++) {
    int max_sp_this = -2147483647 - 1;
    for (int count2 = 0; count2 < count1; count2++) {
      max_sp_this = getMax(max_sp_this,
          cost.elementAt(count2) + dp.elementAt(count1 - count2 - 1));
    }
    dp.add(max_sp_this);
  }

  // return Selling price for given length
  return dp.elementAt(length);
}

// Function to return maximum out of two numbers
int getMax(int num1, int num2) {
  if (num1 > num2) {
    return num1;
  }
  return num2;
}

// main function with driver code
void main() {
  print("Enter the length of the rod:");
  int length = int.parse(stdin.readLineSync()!);
  List arr = [];

  print("Enter the cost of the rod from 1 to $length:");
  for (int i = 0; i < length; i++) {
    arr.add(int.parse(stdin.readLineSync()!));
  }

  // Pass array and length to Maximum price function
  int max_price = maximum_sp(length, arr);
  print("The maximum seeling price is $max_price");
}

/*
Time Complexity- O(n^2)
Space Complexity- O(n)

Sample I/O:

Enter the length of the rod:
4
Enter the cost of the rod from 1 to 4:
12
9
21
13
The maximum seeling price is 48

Enter the length of the rod:
5
Enter the cost of the rod from 1 to 5:
2
5
7
8
10
The maximum seeling price is 12
*/

