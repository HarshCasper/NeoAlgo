/* This is a problem to solve the gcd of two numbers, the solution includes both the naive and recursive solution.

Example : gcd(357,234)
Output : 3

*/

#include <iostream>

int gcd_recur(int a,int b)
{
	if(b!=0)
	   return gcd_recur(b,a%b);
	else
	   return a;
}
int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a,b) << std::endl;
  std::cout << gcd_recur(a, b) << std::endl;
  return 0;
}
