#include <iostream>
using namespace std;

int main ()
{
  int res = 0, number;
  cout << "Enter a number ";
  cin >> number;
  while (number > 0)
    {
      number = (number & (number - 1));
      res++;
    }
  cout << res;
  return 0;
}
