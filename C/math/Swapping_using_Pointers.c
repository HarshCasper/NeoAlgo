// C Program to swap two numbers using pointers

#include<stdio.h>

void swap()
{
  int x,y,*a,*b,temp;
  // getting input
  printf("Enter 2 nos. to swap: ");
  scanf("%d%d",&x,&y);
  // showing values of 'x' and 'y' before swapping
  printf("Before swapping:\nx=%d\ty=%d",x,y);
  // making use of pointers for swapping
  a = &x;
  b = &y;
  temp = *b;
  *b = *a;
  *a = temp;
  // showing values of 'x' and 'y' after swapping
  printf("\nAfter swapping:\nx=%d\ty=%d",x,y);
}

void main()
{
  // calling 'swap' function to input numbers from user and swap them
  swap();
}

/*

TIME COMPLEXITY:
O(1)

SPACE COMPLEXITY:
O(1)

SAMPLE WORKING:
Enter 2 nos. to swap: 3 5
Before swapping:
x=3	y=5
After swapping:
x=5	y=3

*/