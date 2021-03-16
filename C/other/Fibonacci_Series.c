/*
The Fibonacci Sequence

The Fibonacci sequence appears in nature all around us, in the arrangement of seeds in a sunflower and the spiral of a nautilus for example.

The Fibonacci sequence begins with 0 and 1 as its first and second terms. After these first two elements, each subsequent element is equal to the sum of the previous two elements.

Programmatically:

fibonacci(0) = 0
fibonacci(1) = 1

fibonacci(n) = fibonacci(n-1) + fibonacci(n-2)

Given n, return the nth number in the sequence.
*/

#include<stdio.h>

void fibonacci(int n)
{
    int a = -1;
    int b = 1;
    int c;

    for(int i=0; i<=n;i++)
    {
      c = a+b;
      a = b;
      b = c;

      printf("Value number %d: %d\n",i, c);
    }

}

int main()
{
  int no;

  scanf("%d", &no);

  fibonacci(no);
}
