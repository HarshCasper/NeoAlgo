#include <stdio.h>
int catalan(int n) {
   if (n <= 1) {
       return 1;
   }
   int res = 0;
   for (int i=0; i<n; i++)
      res += catalan(i)*catalan(n-i-1);
   return res;
}
int main(){
   int n;
   printf("Enter Number: ");
   scanf("%d",&n);
   printf("\n");
   for(int i =1;i<=n;i++)
   {
       printf("%d ",catalan(i));
   }
   return 0;
}

/*
Sample input and output
Enter number: 7
1 2 5 14 42 132 429

time complexity: O(n^2)
space complexity: O(n)
*/ 