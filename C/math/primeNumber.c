#include <stdio.h>
int main() {
   int num = 33, flag = 0;
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
