/*
C++ program to reverse a number.
The reverse of a number is a number that is obtained when a number is traversed from right to left.
*/

#include <bits/stdc++.h>
using namespace std;
// Function to do reverse

int reverse(int num) {
  // Initializing rev as 0

  int rev = 0;
  do {
    // Adding the last digit

    rev = rev * 10 + num % 10;
    // Removing the last digit

    num = num / 10;
  } while (num > 0);

  return rev;
}

int main() {
  int num;
  // Taking Input 

  cout << "Enter the number: ";
  cin >> num;
  // Printing Output

  cout << "The reverse of the given number is: " << reverse(num);
  return 0;
}

/*
Time Complexity - O(n), where 'n' is the number of digits in the number.
Space Complexity - O(1)

SAMPLE INPUT AND OUTPUT
SAMPLE I

INPUT
Enter the number: 1234

OUTPUT
The reverse of the given number is: 4321

*/
  
