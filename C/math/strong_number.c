/*
 C Program to check whether a given number is Strong number or not.
 Strong number is a special number whose sum of factorial of digits is equal to the original number.
Eg: 145 is strong number. Since, 1! + 4! + 5! = 145
*/

#include <stdio.h>

int factorial (int num)
{
  int i = 0;
  int fact = 1;
  for (i = 1; i <= num; i++)
    {
      fact = fact * i;
    }
  return fact;
}

int main ()
{
  int sum = 0;
  int lastDigit, number;
  printf ("Enter the number to be checked\n");
  scanf ("%d", &number);
  int originalNumber = number;
  while (number > 0)
    {
      lastDigit = number % 10;
      sum = sum + factorial (lastDigit);
      number = number / 10;
    }
  if (sum == originalNumber)
    {
      printf ("Strong number!");
    }
  else
    {
      printf ("Not a strong number!");
    }
  return 0;
}

/*
Sample Input-Output:
Example 1-
Enter the number to be checked
145
Strong number!
Example 2-
Enter the number to be checked
456
Not a strong number!
*/
