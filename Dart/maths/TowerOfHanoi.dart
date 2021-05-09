/*
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. 
The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:
1) Only one disk can be moved at a time.
2) Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
3) No disk may be placed on top of a smaller disk.
*/

import 'dart:io';

void towerOfHanoi (int num, String from,String aux, String to){
  
  // Base case
  if (num == 1){
    print("Move Disk from Rod-$from to Rod-$to");
  }
  // Recursive case
  else{
    towerOfHanoi(num-1, from, to, aux);
    towerOfHanoi(1, from, aux, to);
    towerOfHanoi(num-1, aux, from, to);
  }
}

// Main function with driver function
void main(){
  // Take user input
  print("Enter Number of disk:");
  int num = int.parse(stdin.readLineSync()!);

  // Pass to Tower of Hanoi Recurrsive function
  towerOfHanoi(num, 'A','B', 'C');
}

/**
Time Complexity: O(2^N)
Space Complexity: O(N)

Sample input/output:

Enter Number of disk:
2
Move Disk from Rod-A -> Rod-B
Move Disk from Rod-A -> Rod-C
Move Disk from Rod-B -> Rod-C

Enter Number of disk:
3
Move Disk from Rod-A to Rod-C
Move Disk from Rod-A to Rod-B
Move Disk from Rod-C to Rod-B
Move Disk from Rod-A to Rod-C
Move Disk from Rod-B to Rod-A
Move Disk from Rod-B to Rod-C
Move Disk from Rod-A to Rod-C

*/
