/**
Algorithm to sort arrays when numbers are distributed over a range. In this
algorithm we divde the whole array into buckets and then sort the smaller buckets
to get the sorted array.
 */
import 'dart:io';
import 'dart:math';

// function that implements bucket sort
List bucketSort(List arr, int bucketNum) {
  // get max value in array to find upper limit of bucket
  num maxVal = arr[0];
  for (int i = 0; i < arr.length; i++) {
    maxVal = max(maxVal, arr[i]);
  }
  maxVal++;

  // making bucket list and adding buckets to it
  List bucketList = new List.empty(growable: true);
  for (int i = 0; i < bucketNum; i++) {
    bucketList.add(new List.empty(growable: true));
  }

  // dividing numbers in different buckets
  for (int i = 0; i < arr.length; i++) {
    int bucketIndex = ((arr[i] * bucketNum) ~/ maxVal) as int;
    bucketList[bucketIndex].add(arr[i]);
  }

  // sorting each bucket one-by-one
  for (int i = 0; i < bucketNum; i++) {
    bucketList[i].sort();
  }

  // joining buckets
  int pos = 0;
  for (int i = 0; i < bucketNum; i++) {
    for (int j = 0; j < bucketList[i].length; j++) {
      arr[pos] = bucketList[i][j];
      pos += 1;
    }
  }

  return arr;
}

// main function, entry point of the program
void main() {
  print("Enter the size of list:");
  int size = int.parse(stdin.readLineSync()!);
  List arr = [];
  print("Enter the numbers:");
  for (int i = 0; i < size; i++) {
    arr.add(int.parse(stdin.readLineSync()!));
  }
  print("Enter number of buckets:");
  int buckets = int.parse(stdin.readLineSync()!);
  // sorting
  arr = bucketSort(arr, buckets);
  print("Sorted list:");
  for (int i = 0; i < size; i++) {
    print(arr[i]);
  }
}

/**
Enter the size of list:
6
Enter the numbers:
5
0
2
1
4
3
Enter number of buckets:
5
Sorted list:
0
1
2
3
4
5

Time Complexity: O(n+k)
Space Complexity: O(n+k)
 */
