/* 
Shell Sort in Dart

Shell sort is an algorithm that first sorts the elements far apart from 
each other and successively reduces the interval between the elements to 
be sorted. 
*/

import 'dart:io';

void ShellSort(var arr, int n) {
  // Setting the intervals as n/2, n/4, n/8, ...
  for (int interval = (n / 2).floor();
      interval > 0;
      interval = (interval / 2).floor()) {
    // traversing through the right side of the interval
    for (int i = interval; i < n; i++) {
      int temp = arr[i];

      int j;

      // Sorting the temp element by comparing it with left side of the interval
      for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
        arr[j] = arr[j - interval];
      }
      arr[j] = temp;
    }
  }
}

void main() {
  var array = [];

  var n, ele;
  print('Enter the number of Elements: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  for (int i = 1; i <= n; i++) {
    print('Enter Element $i: ');
    ele = stdin.readLineSync();
    ele = int.parse(ele);
    array.add(ele);
  }

  ShellSort(array, n);
  print(array);
}

/*
Time Complexity:
1. Worst Case Complexity: O(n^2)
2. Best Case Complexity: O(n*log n)
3. Average Case Complexity: O(n*log n)

Space Complexity: O(1) 

Sample Input/Output:
Input :
Enter the number of Elements: 
5
Enter Element 1: 
50
Enter Element 2: 
30
Enter Element 3: 
10
Enter Element 4: 
40
Enter Element 5: 
20
Output:
[10, 20, 30, 40, 50]

*/
