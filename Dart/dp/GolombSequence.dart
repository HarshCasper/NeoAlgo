/*
Golomb sequence is a non-decreasing integer sequence where n'th
term is  equal to the number of times n appears in the sequence 
*/

import 'dart:io';

// Recursive golomb function
int golomb(int n){

    //Base case
    if(n==1){
      return 1;
    }
    // recursive case
    return 1 + golomb(n -golomb(golomb(n - 1)));
}

// Function to add golomb sequence in a list
int print_golomb(int n){
  List<int> dp = [];

  // Add golomb numbers to the list
  for(int i=1; i<n+1; i++){
    dp.add(golomb(i));
  }

  // Print list element at index n
  return dp.elementAt(n-1);
}

void main(){
  print("Enter the value of 'n', where you need the n'th number in the golomb sequence:");
  int num = int.parse(stdin.readLineSync()!);

  if (num <= 0){
    print("The given value of n is invalid.");
  }

  // pass input to golomb calculator
  int res = print_golomb(num);

  print("The ${num}th term in the golomb sequence is $res");
}

/*
Time Complexity: O(n), where 'n' is the given number
Space Complexity: O(n)

Sample I/O:

Enter the value of 'n', where you need the n'th number in the golomb sequence:
12
The 12th term in the golomb sequence is 6

Enter the value of 'n', where you need the n'th number in the golomb sequence:
30
The 30th term in the golomb sequence is 10

Enter the value of 'n', where you need the n'th number in the golomb sequence:
60
The 60th term in the golomb sequence is 15
*/

