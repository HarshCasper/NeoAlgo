#include <iostream>
using namespace std;

int main ()
{
  int n;
  cout << "enter the number to check sparse" << endl;
  std::cin >> n;
  if (n & (n >> 1))
    {
      cout << "Number is not sparse";
    }
  else
    {
      cout << "Number is sparse";
    }
  return 0;
}
