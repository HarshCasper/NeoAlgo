/* 
Tim Sort:
Sorting algorithm based on merge sort and insertion sort
*/

import 'dart:io';
import 'dart:math';

void timSort(var arr, int n) {
  // Setting the RUN (arbitrary size of a section of array) size as 32
  const int RUN = 32;

  for (int i = 0; i < n; i += RUN) {
    // Sorting each RUN using insertion sort
    insertionSort(arr, i, min((i + RUN - 1), (n - 1)));
  }

  // Merging and doubling the size (initially equal to RUN) after each iteration
  for (int s = RUN; s < n; s = 2 * s) {
    // Doubling the size of subarray after every merge
    for (int left = 0; left < n; left += 2 * s) {
      // Determining the middle and last index of the subarray
      int mid = left + s - 1;
      int right = min((left + 2 * s - 1), (n - 1));

      // merging the subarrays
      if (mid < right) {
        merge(arr, left, mid, right);
      }
    }
  }
}

void merge(var arr, int l, int m, int h) {
  // Setting the length of the new arrays
  int n1 = m - l + 1;
  int n2 = h - m;

  // Creating new subarrays to store the values of the array
  List left = new List.filled(n1, null, growable: false);
  List right = new List.filled(n2, null, growable: false);

  // Putting the array values in the subarrays
  for (int i = 0; i < n1; i++) {
    left[i] = arr[l + i];
  }
  for (int j = 0; j < n2; j++) {
    right[j] = arr[m + 1 + j];
  }

  // Setting the initial index of the subarrays and actual array
  int i = 0;
  int j = 0;
  int k = l;

  // Sorting and placing the elements of subarrays in the main array
  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i += 1;
    } else {
      arr[k] = right[j];
      j += 1;
    }
    k += 1;
  }

  // Storing the rest of the elements
  while (i < n1) {
    arr[k] = left[i];
    i += 1;
    k += 1;
  }

  while (j < n2) {
    arr[k] = right[j];
    j += 1;
    k += 1;
  }
}

void insertionSort(var arr, int l, int r) {
  // starts from the 2nd element from l index
  for (int i = l + 1; i <= r; i++) {
    int temp = arr[i];
    int j = i - 1;
    // Comparing all elements to the left of l,
    // inorder to place temp in the correct position
    while (j >= l && arr[j] > temp) {
      arr[j + 1] = arr[j];
      j -= 1;
    }
    arr[j + 1] = temp;
  }
}

void main() {
  var arr = [];

  // User inputs
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

  // Applying Tim Sort
  timSort(arr, n);

  print(arr);
}

/*
Time Complexity : O(n*log n)
Space Complexity : O(n)

SAMPLE I/O:
Enter the number of Elements: 
6
Enter Element 1: 
23
Enter Element 2: 
11
Enter Element 3: 
29
Enter Element 4: 
90
Enter Element 5: 
77
Enter Element 6: 
565
[11, 23, 29, 77, 90, 565]
*/
