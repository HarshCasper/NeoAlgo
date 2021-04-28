/*
HEAP SORT

It is a sorting technique based on the heap data structure.

Heap is a complete binary tree, in which every level except the last, is filled
completely with its nodes, and nodes are far left.

We implement this sorting in an array using Max Heap, in which the parent node 
value is greater than it child node values. 
*/

import 'dart:io';

void swap(List arr, int i1, int i2) {
  // Swapping elements in array
  int temp = arr[i1];
  arr[i1] = arr[i2];
  arr[i2] = temp;
}

void maxHeap(List arr, int n, int i) {
  // Making a max heap (root = largest element) using complete binary tree in array.
  // Setting indices for root, left child and right child.
  int root = i;
  int left_c = (2 * i) + 1;
  int right_c = (2 * i) + 2;

  // If left child is greater than root, changing the index of root accordingly
  if (left_c < n && arr[left_c] > arr[root]) {
    root = left_c;
  }

  // If right child is greater than root, changing the index of root accordingly
  if (right_c < n && arr[right_c] > arr[root]) {
    root = right_c;
  }

  // Recursively calling maxHeap till we set the largest element at root
  if (root != i) {
    swap(arr, i, root);
    maxHeap(arr, n, root);
  }
}

void heapSort(arr, n) {
  for (int i = (n ~/ 2); i >= 0; i--) {
    // Building maximum heap
    maxHeap(arr, n, i);
  }

  for (int i = n - 1; i >= 1; i--) {
    // Move current root to end and sorting it
    swap(arr, 0, i);

    // Bringing largest element to root
    maxHeap(arr, i, 0);
  }
}

main() {
  var array = [];

  var n, ele;
  print('Enter the number of elements: ');
  n = stdin.readLineSync();
  n = int.parse(n);

  for (int i = 1; i <= n; i++) {
    print('Enter value for element $i: ');
    ele = stdin.readLineSync();
    ele = int.parse(ele);
    array.add(ele);
  }

  heapSort(array, n);
  print('The sorted array is $array');
}

/*
TIME COMPLEXITY: O(n*logn)
SPACE COMPEXITY: O(1)

SAMPLE I/O:
Enter the number of elements: 
7
Enter value for element 1: 
13
Enter value for element 2: 
12
Enter value for element 3: 
45
Enter value for element 4: 
1
Enter value for element 5: 
89
Enter value for element 6: 
6
Enter value for element 7: 
44
The sorted array is [1, 6, 12, 13, 44, 45, 89]
*/
