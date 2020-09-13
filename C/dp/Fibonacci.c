//C program to calculate the nth fibonacci term using DP memoization
#include<stdio.h>

//Global array storing the nth term index wise,the size can be changed as per use.
int f[1000];
 
//Fibonnaci function 
int fibonacci(int n)
{
  //Fibonnaci series:
  //f[0]=0 and f[1]=1
  //base condition:
  if(n<=1)
  {
    f[n]=n;
    return n;
  }
  //Recursive function:
  //f[n]=f[n-1]+f[n-2]
  else{

    if(f[n-2]==-1)

      f[n-2]=fibonacci(n-2);

    if(f[n-1]==-1)

      f[n-1]=fibonacci(n-1);

    return f[n-1]+f[n-2];
  }
}
 
//Main Function 
int main()
{
  
    int i, n;
    printf("Enter the number the indexing starts from 1\n");
    scanf("%d",&n);
    if(n<=0)
    printf("Wrong Input\n");
    else
    {
	    for(i=0;i<n;i++)
	      f[i]=-1;
	    fibonacci(n);
	 
	    printf("The nth fibonacci term is: %d",f[n-1]);
    }
    
    return 0;
}
/* Author : Chandan Kumar Sahu (@chandansahuji)
contributing as a part of hackinCodes 2020

Sample Input:
enter the number
n=5

sample output:
The nth fibonacci term is:3

Time Complexity-O(n)
Space Complexity-O(n)
*/

