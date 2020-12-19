/* Extended Euclidean Algorithm

  GCD of two numbers is the largest number that divides both of them.
  A simple way to find GCD is to factorize both numbers and multiply
  common factors.
 
     GCD(a,b) = ax + by
     
  If we can find the value of  x and y then we can easily find the
  value of GCD(a,b) by replacing (x,y) with their respective values.
*/

#include <stdio.h>

int extendedGCD(int a, int b, int *x, int *y)
{
    //base case
    if (a == 0)
    {
        *x = 0;
        *y = 0;
        return b;
    }
   
    int x1, y1;
   
    //recursive call
    int ans = extendedGCD(b % a, a, &x1, &y1);
   
    //Update x and y using results of recursive call
    *x = y1 - (b/a) * x1;
    *y = x1;
   
    return ans;
}

//Driver Code
int main()
{
    int x, y, a, b;
    printf("Enter the values of a and b : ");
    scanf("%d %d", &a, &b);
    int gextnd = extendedGCD(a, b, &x, &y);
    printf("\nGCD using Extended Euclidean algorithm is: %d ", gextnd);
    return 0;
}

/*
Time Complexity : O(log(max(A, B)))

Sample I/O :

Input :
Enter the values of a and b : 55 10                                                                                          
 
Output :
GCD using Extended Euclidean algorithm is: 5
*/
