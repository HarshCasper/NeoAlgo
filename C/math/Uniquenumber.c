/*
Program to check whether a number is a unique number or not.A unique number is a number which is positive and 
has all digits different
*/

#include <stdio.h>
#include <conio.h>

int main(void)
{
	int n;
	printf("Enter a number\n");
	scanf("%d",&n);
	if(n<0)
	{
		printf("Not a unique number\n");
	}
	else
	{
		int t,b,f,c=0;
		t=n;
      while(t!=0)
	  {
		  b=t%10;
		  while(n!=0)
		  {
			  f=n%10;
			  if(b==f)
			  c++;
			  n=n/10;
		  }
		  t=t/10;
	  }
	  if(c==1)
	  printf("The entered number is unique\n");
	  else
	  printf("Not a unique number\n");
	}
	return 0;
}

/*
Time Complexity-O(log(n)) n is number
Space Complexity-O(1)
Input/Output:-
Enter a number 123452
Not a unique number
*/
