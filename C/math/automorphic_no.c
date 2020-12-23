/*C program to check whether the number is automorphic or not.
Automorphic number is a number whose square ends with the original number itself
Eg: 6 , As the square of 6 is 36 and 36 ends with 6  */
#include<stdio.h>

int main() {
  int n;
  printf("Enter the number to check:\n");
  scanf("%d", & n);
  int s, temp, l;
  temp = n;
  s = n * n;
  int flag = 1;
  while (n != 0) {
    flag = flag * 10;
    n = n / 10;
  }
  l = s % flag;
  if (l == temp)
    printf("\nAUTOMORPHIC NUMBER !");
  else
    printf("\nNOT AUTOMORPHIC NUMBER !");
  return 0;
}
/*
Sample Input-Output:1
Enter the number to check:
7
NOT AUTOMORPHIC NUMBER !

Sample Input-Output:2
Enter the number to check:
5
AUTOMORPHIC NUMBER !

Time Complexity: O(n)
*/

