/*
JUMP SEARCH IN DART
Jump search is a sorting algorithm suited for ordered lists. 
It creates a block and tries to find the element in that block. 
If the item is not in the block, it shifts the entire block. 
The block size chosen is √n, where n is the size of the array.
*/

import 'dart:io';
import 'dart:math';

int jumpSearch(List arr, int len, int key) {
  int begin = 0;
  // Setting the size of each block as squareroot of length of array
  int block_size = sqrt(len).floor();

  // Finding the block in which the key may potentially lie
  while (arr[block_size] <= key && block_size < len) {
    // setting the beginning index for the next block
    begin = block_size;
    // setting the ending index for the next block
    block_size += sqrt(len).floor();

    // if the block_size index lies beyond the length of array
    // indicating the key may or may not lie in last block
    // if it lies then linear search will find it and if not
    // return -1
    if (block_size > len - 1) {
      block_size = len;
      break;
    }
  }

  // performing linear search in the block in which the key may lie
  for (int ind = begin; ind < block_size; ind += 1) {
    if (arr[ind] == key) return ind;
  }
  return -1;
}

void main() {
  var n, ele, key;
  print('Enter the number of elements (n): ');
  n = stdin.readLineSync();
  n = int.parse(n);

  List array = new List.filled(n, null, growable: false);

  for (int i = 0; i < n; i++) {
    print('Enter value for element $i: ');
    ele = stdin.readLineSync();
    ele = int.parse(ele);
    array[i] = ele;
  }

  print('Enter the element to be searched (key): ');
  key = stdin.readLineSync();
  key = int.parse(key);

  int index = jumpSearch(array, n, key);

  if (index >= 0)
    print('$key was found at index $index');
  else
    print('$key is not present in the given array');
}

/*
TIME COMPLEXITY: O(√n)
SPACE COMPLEXITY: O(1)

SAMPLE INPUT/OUTPUT:
Enter the number of elements (n): 
7
Enter value for element 0: 
11
Enter value for element 1:
12
Enter value for element 2:
33
Enter value for element 3:
44
Enter value for element 4:
55
Enter value for element 5:
66
Enter value for element 6:
77
Enter the element to be searched (key):
55
55 was found at index 4
*/
