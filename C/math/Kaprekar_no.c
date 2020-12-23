/*
C program to check whether a number is kaprekar number or not
Kaprekar number is a number whose square when divided into two parts and then added gives the original number
Eg: 45 (45^2 = 2025 -->20+25 = 45)
*/

#include<stdio.h>
#include<math.h>
#include<stdbool.h>

bool kaprekar (int n);

int main ()
{
  int n;
  printf ("Enter the number to check:\n");
  scanf ("%d", &n);
  if (kaprekar (n) == true)
    {
      printf ("Kaprekar Number!");
    }
  else
    {
      printf ("Not Kaprekar Number !");
    }
  return 0;
}

bool kaprekar (int n)
{
  if (n == 1)
    return true;
  int s = n * n;
  int t = 0;
  while (s)
    {
      t = t + 1;
      s = s / 10;
    }
  s = n * n;
  for (int c = 1; c < t; c++)
    {
      int f, x1, x2, sum;
      f = pow (10, c);
      if (f == n)
	continue;
      x1 = s / f;
      x2 = s % f;
      sum = x1 + x2;
      if (sum == n)
	return true;
    }
  return false;
}

/*
SampleInput-Output1:
Enter the number to check:
297
Kaprekar Number!

SampleInput-Output2:
Enter the number to check:
12
Not Kaprekar Number!

Time Complexity: O(n)
*/
