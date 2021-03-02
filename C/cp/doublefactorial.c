#include <stdio.h>

int iterative_doublefactorial(int n) {
  int res = 1;
  for (int i = n; i > 0; i -= 2) {
    if (n == 0 || n == 1)
      return res;
    else
      res = res * i;
  }

}

int recursive_doublefactorial(int n) {
  if (n == 0 || n == 1)
    return 1;
  else
    return n * recursive_doublefactorial(n - 2);
}

int main() {
  int n;
  printf("Enter the number :");
  scanf("%d", & n);
  int k;
  do {
    printf("Enter the choice below :\n1.Iterative solution \n2.Recursive Solution \n3.Exit \n");
    scanf("%d", & k);
    switch (k) {
    case 1:
      printf("The Double Factorial is : %d\n", iterative_doublefactorial(n));
      break;
    case 2:
      printf("The Double Factorial is : %d\n", recursive_doublefactorial(n));
      break;
    }
  } while (k != 3);

  return 0;
}

/*
Enter the number :7
Enter the choice below :
1.Iterative solution 
2.Recursive Solution 
3.Exit 
1
The Double Factorial is : 105
Enter the choice below :
1.Iterative solution 
2.Recursive Solution 
3.Exit 
2
The Double Factorial is : 105
Enter the choice below :
1.Iterative solution 
2.Recursive Solution 
3.Exit 
3
*/
