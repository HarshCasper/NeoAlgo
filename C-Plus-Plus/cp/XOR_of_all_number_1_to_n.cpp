/*
  Problem Statement:
   Find XOR of all the number from 1 to n.
   i.e. 1^2^3^4^5...^n

   INPUT: 
   The first line of input contain a single integer n (1<=n<=10^9).

   OUTPUT:
   Print a single integer as XOR of all the number from 1 to n. 
*/

/*
  Naive Approach:
    1. Initialize result as 0. 
    2. Traverse from 1 to n as i.
    3. Do result = result ^ i;
    4. Print result;

  Notice: This approach will give runtime error for a large calue of n.

*/

// Efficent Approach

#include <iostream>
#include <algorithm>
using namespace std;

int findXOR(int n)
{
  // If remainder is 0
  if (n % 4 == 0)
    return n;

  // If remainder is 1
  if (n % 4 == 1)
    return 1;

  // If Remainder is 2
  if (n % 4 == 2)
    return n + 1;

  // If Remainder is 3
  if (n % 4 == 3)
    return 0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; //input
  cin >> n;

  int answer = findXOR(n);

  // output
  cout << answer << "\n";

  return 0;
}

/* 
  Example:
    Input : 6
    Output: 7

    Input: 3
    Output: 0

    Inpuut: 12
    Output: 12

*/