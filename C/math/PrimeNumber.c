#include <stdio.h>
int main() {
   int num, flag = 0;
   
   printf("Enter number to check prime or not : ");
   scanf("%d",&num);
   
   for(int i=2 ; i < num/2 ; i++) {
      if(num%i == 0) {
         printf("%d is not a prime number", num);
         flag = 1;
         break;
      }
   }
   if(flag == 0) {
      printf("%d is a prime number", num);
   }
}


/*

Time Complexity

BestCase = O(1)
WorstCase = O(n)
AverageCase  = O(n/2) = O(n)

*/
