import 'dart:io';

// Function to check if number is Strong
bool checkStrong(int num) {
  int sum = 0;
  int num_copy = num;

  while (num_copy > 0) {
    int digit = num_copy % 10;
    sum += fact(digit);
    num_copy ~/= 10;
  }
  if (sum == num) {
    return true;
  }
  return false;
}

// Function to calculate factorial of a number
int fact(int number){
  int result = 1;
  int count = 1;
  while(count <= number){
    result *= count;
    count++;
  }
  return result;
}

// Main Function with driver code
void main() {
  print("Enter a number :");
  int num = int.parse(stdin.readLineSync()!);

  // Call function to check if number is Strong
  if (checkStrong(num)) {
    print("$num is a Strong Number");
  } else {
    print("$num is not a Strong Number");
  }
}

/**
Sample input/output:
Enter a number :
145
145 is a Strong Number

Enter a number :
234
234 is not a Strong Number
*/
