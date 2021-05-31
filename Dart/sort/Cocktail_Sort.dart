/*
COCKTAIL SORT IN DART
Cocktail Sort is a variation of Bubble sort. 
Cocktail Sort traverses through a given array in both directions alternatively,
in a similar fashion of Bubble sort where comparision is performed between 
consecutive elements. 
*/

import 'dart:io';

CocktailSort(var arr, int n) {
  bool flag = true;
  int first = 0;
  int last = n - 1;

  while (flag) {
    // resetting the flag
    flag = false;

    // loop from left to right and performing comparisons 
    // through the iterations to check for greater values
    for (int i = first; i < last; ++i) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        flag = true;
      }
    }

    // if no swapping occured, the array is sorted
    if (!flag) break;

    // Resetting the flag
    flag = false;
    --last;

    // loop from right to left and performing comparisons 
    // through the iterations to check for greater values
    for (int i = last - 1; i >= first; --i) {
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        flag = true;
      }
    }

    ++first;
  }
}

main() {
  // Driver code to generate the required input/output
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

  CocktailSort(array, n);
  print(array);
}

/*
TIME COMPLEXITY: O(n*n)
SPACE COMPLEXITY: O(1)

SAMPLE I/O:
Enter the number of Elements: 
7
Enter Element 1: 
34
Enter Element 2: 
23
Enter Element 3: 
78
Enter Element 4: 
90
Enter Element 5: 
9
Enter Element 6: 
66
Enter Element 7: 
45
[9, 23, 34, 45, 66, 78, 90]