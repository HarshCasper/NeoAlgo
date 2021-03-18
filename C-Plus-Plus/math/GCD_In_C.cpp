//C program to implement Euclid's Algorithm to find greatest common divisor

#include<stdio.h>

// It is a recursive function that calculates greatest common divisor or hcf of 2 
// integer numbers a and b 
// GCD of two numbers is the largest number that divides both of them.
// A simple way to find GCD is to factorize both numbers and multiply common factors.

int gcd(int a,int b)
{ //base case
  if (a==0)
     return b;
  //recursive case
  else
     return gcd(b%a,a);
}

//initializing a and b.
//Here a is always the smaller number and
// b is always the bigger number between the two.

int main()
{  int a = 10, b = 15; 
    printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));  //should print 5
    a = 35, b = 10; 
    printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b)); //should print 5
    a = 31, b = 2; 
    printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b)); //should print 1
    return 0; 
}
