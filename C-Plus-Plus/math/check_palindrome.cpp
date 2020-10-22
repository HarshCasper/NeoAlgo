#include <iostream>
using namespace std;

int main()
{
     int n, num, digit, rev = 0;
     cout << "Enter a positive number: ";
     cin >> num;

     n = num;

     do
     {
         digit = num % 10;
         rev = (rev * 10) + digit;
         num = num / 10;
     } while (num != 0);

     if (n == rev)
         cout << " The number is a palindrome.";
     else
         cout << " The number is not a palindrome.";
     //sample input 1
     //232
     //sample output 1
     // The number is a palindrome.
     //sample input 2
     //456
     //sample output 2
     // The number is not a palindrome.
     //sample input 3
     //12321
     //sample output 3
     // The number is a palindrome.
    return 0;
}
