/*
Lucas Number is a sequence of numbers similar to the Fibonacci Series and is defined as the sum of previous two digits
starting with "2" and "1".
*/


#include <bits/stdc++.h>

using namespace std;
void lucas(int n) {
  int x = 2;
  int y = 1;
  int z, count;
  if (n == 0)
    cout << " ";
  else if (n == 1)
    cout << x;
  else {
    cout << x << " " << y << " ";

    for (count = 2; count < n; count++) {
      z = x + y;
      x = y;
      y = z;
      cout << y << " ";
    }
  }

}
int main() {
  int n;
  cout << "Enter the number of terms of Lucas Numbers you want to print: ";
  cin >> n;
  cout << "The Lucas Series of " << n << " terms is: ";
  lucas(n);
}
 
/*
Time Complexity: O(n)
Space Complexity: O(1)
where n is the input number (number of terms)

Sample Input:
Enter the number of terms of Lucas Numbers you want to print: 9

Sample Output:
The Lucas Series of 9 terms is: 2 1 3 4 7 11 18 29 47 

*/
