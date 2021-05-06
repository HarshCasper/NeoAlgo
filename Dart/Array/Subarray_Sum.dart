/*
Find the subarray with the given sum:

Given an unsorted array of nonnegative integers, 
the given script shows the implementation to find 
a continuous subarray which adds up to the desired sum. 

*/

import 'dart:io';

List findSubarray(var arr, int n, int total) {
  // Initializing a counter for the total sum so far
  var curr_sum = arr[0];

  // Setting initial index as 0
  int init = 0;

  for (int i = 1; i <= n; i++) {
    // increasing the initial index if the current sum becomes
    // greater than the total i.e., removing those elements below init
    while (curr_sum > total && init < i - 1) {
      curr_sum = curr_sum - arr[init];
      init += 1;
    }

    // Creating sub-array, if the sum is equal
    if (curr_sum == total) {
      var sub_arr = [];
      for (int j = init; j < i; j++) {
        sub_arr.add(arr[j]);
      }
      return sub_arr;
    }

    // Adding the given element to the current sum
    if (i < n) {
      curr_sum = curr_sum + arr[i];
    }
  }

  // In case of no subarray of the given sum
  return [];
}

main() {
  // Taking user input
  var array = [];

  var n, ele, total;
  print('Enter the number of Elements: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  for (int i = 1; i <= n; i++) {
    print('Enter Element $i: ');
    ele = stdin.readLineSync();
    ele = int.parse(ele);
    array.add(ele);
  }

  print('Enter the desired total: ');
  total = stdin.readLineSync();
  total = int.parse(total);

  // Calling function to obtain the required results
  List soln = findSubarray(array, n, total);
  print("The subarray is as follows: $soln");
}

/*
Time Complexity:  O(n)
Space Complexity: O(1)

Sample I/O:
Enter the number of Elements: 
5
Enter Element 1: 
67
Enter Element 2: 
55
Enter Element 3: 
4
Enter Element 4: 
5
Enter Element 5: 
9
Enter the desired total: 
18
The subarray is as follows: [4, 5, 9]

*/
