// C Program to find the sum of digits of a number using recursion

#include<conio.h>
#include<stdio.h>

int sum(int n)
{
    
if(n == 0)
  return 0;
else
  // extracting each digit and recursively calling 'sum' function to compute the sum 
  return(n%10 + sum(n/10));
}

int main()
{
  int num,result;
  // getting our input
  printf("Enter no.: ");
  scanf("%d",&num);
  // calling 'sum' function to compute the sum for 'num'
  result = sum(num);
  printf("Sum of digits is: %d",result);
  getch();
}

/*

TIME COMPLEXITY:
O(N)

SPACE COMPLEXITY:
O(1)

SAMPLE WORKING:
Enter no.: 301
Sum of digits is: 4

*/