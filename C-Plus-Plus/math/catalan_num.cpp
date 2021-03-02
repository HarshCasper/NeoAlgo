/*
Catalan numbers is a number sequence, which is found useful in a number of
combinatorial problems, often involving recursively-defined objects.
*/

#include <iostream>
using namespace std;

// To find nth catalan number using recursive function
unsigned long int catalan(unsigned int n)
{

  if (n <= 1)
    return 1;
  unsigned long int res = 0;
  for (int i = 0; i < n; i++)
    res = res + catalan(i) * catalan(n - i - 1);

  return res;
}

int main()
{
  cout << "Enter the Number:" << endl;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cout << catalan(i) << " ";
  }
  cout << endl;
  return 0;
}

/*
Input:
Enter the Number:
15
Ouput:
1 1 2 5 14 42 132 429 1430 4862 16796 58786 208012 742900 2674440

Time Complexity: O(2^n)
Space Complexity: O(1)
*/