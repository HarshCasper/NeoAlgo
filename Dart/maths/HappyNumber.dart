/*
A happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit 
until the sum becomes a single digit number.
*/

import 'dart:io';

// Function to check if number is a Happy Number
bool isHappyNumber(int num) {
  int sum = num;

  // do while loop used as square of digits need to be taken a minimum of one time
  do{
    int copy = sum;
    sum = 0;

    // calculating sum of square of individual digits
    while(copy > 0){
      int digit = copy % 10;
      sum += (digit*digit);
      copy ~/= 10;
    }
  }
  while(sum > 9);

  if(sum == 1){
    return true;
  }
  return false;
}

void main() {
  print("Enter a number :");
  int num = int.parse(stdin.readLineSync()!);

  // Call function to check if number is a Happy number
  if (isHappyNumber(num)) {
    print("$num is a Happy Number");
  } else {
    print("$num is not a Happy Number");
  }
}

/**
Space Complexity O(1)
Time Complexity  O(nlog(n))

Sample input/output:
Enter a number :
19
19 is a Happy Number

Enter a number :
20
20 is not a Happy Number
*/
