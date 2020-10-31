#include<stdio.h>    
int main()    
{    
     int t1=0, t2=1, t3, i, terms;    
     printf("Number of terms in Fibonacci Series (min 3): ");    
     scanf("%d",&terms);
     
     //print first 2 terms : 0, 1
     printf("\n%d %d", t1, t2);
     
     //print 3rd and subsequent terms
     for(i=2;i<terms;++i)
     {    
         t3 = t1 + t2;    
         printf(" %d", t3);    
         t1 = t2;    
         t2 = t3;    
     }
     return 0;  
}
