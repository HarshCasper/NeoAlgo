/* swapping means exchanging the value of two variable.
 it can be done using xor operator , without using the third variable.
*/


#include<stdio.h>
 
int main() {
   int num1, num2;
 
   printf("\nEnter First Number : ");
   scanf("%d", &num1);
 
   printf("\nEnter Second Number : ");
   scanf("%d", &num2);
 
   num1 = num1 ^ num2;
   num2 = num1 ^ num2;
   num1 = num1 ^ num2;
 
   printf("\n Numbers after Exchange : ");
   printf("\n Num1 = %d and Num2 = %d", num1, num2);
 
   return 0;
}
/*
Time Complexity:O(1)
Space Complexity:O(1)

Input:-
Enter First Number : 10

Enter Second Number : 32

Output:-
 Numbers after Exchange :
 Num1 = 32 and Num2 = 10
*/
