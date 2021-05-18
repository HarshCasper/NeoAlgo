/*
MERGE SORT IN DART
Merge sort is a divide-and-conquer algorithm. 
It keeps on dividing the array in 2 halves until we reach a stage 
where it can no longer be divided, 
and then merges the two sorted halves.
*/

import 'dart:io';

void merge(var arr, int l, int m, int h) {
  int len1 = m - l + 1;
  int len2 = h - m;

  List Left = new List.filled(len1, null, growable: false);
  List Right = new List.filled(len2, null, growable: false);

  for (int i = 0; i < len1; i++) {
    Left[i] = arr[l + i];
  }
  for (int j = 0; j < len2; j++) {
    Right[j] = arr[m + 1 + j];
  }

  // Setting the initial index of the subarrays and actual array
  int i = 0, j = 0, k = l;

  // Sorting and placing the elements of subarray in the main array
  while (i < len1 && j < len2) {
    if (Left[i] <= Right[j]) {
      arr[k] = Left[i];
      i++;
    } else {
      arr[k] = Right[j];
      j++;
    }
    k++;
  }

  // Placing all the remaining elements in the array
  while (i < len1) {
    arr[k] = Left[i];
    i++;
    k++;
  }

  while (j < len2) {
    arr[k] = Right[j];
    j++;
    k++;
  }
}

void mergeSort(var arr, int low, int high) {
  if (low < high) {
    // finding mid element
    int mid = low + (high - low) ~/ 2;

    // recursively calling merge sort for each division
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    // merging the subarrays
    merge(arr, low, mid, high);
  }
}

void main() {
  var arr = [];

  // taking input from user for elements in array
  var n, each;
  print('Enter the number of Elements: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  for (int i = 1; i <= n; i++) {
    print('Enter Element $i: ');
    each = stdin.readLineSync();
    each = int.parse(each);
    arr.add(each);
  }

  // applying merge sort to array
  mergeSort(arr, 0, n - 1);

  print(arr);
}

/*
Time Complexity : O(n*log n)
Space Complexity : O(n)

Sample Input/Output:

Enter the number of Elements: 
5
Enter Element 1: 
23
Enter Element 2: 
12
Enter Element 3: 
1
Enter Element 4: 
444
Enter Element 5:
23
[1, 12, 23, 23, 444]

*/
