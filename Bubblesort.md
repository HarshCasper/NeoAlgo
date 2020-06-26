**Bubble sort program in C**

#include<stdio.h>

int main(){

   int num, temp, i, j, number[30];

   printf("Enter number of Elements: ");
   scanf("%d",&num);

   printf("Enter %d numbers: ",num);

   for(i=0;i<num;i++)
   scanf("%d",&number[i]);

   
   for(i=num-2;i>=0;i--){
      for(j=0;j<=i;j++){
        if(number[j]>number[j+1]){
           temp=number[j];
           number[j]=number[j+1];
           number[j+1]=temp;
        }
      }
   }

   printf("Sorted elements: ");
   for(i=0;i<num;i++)
      printf(" %d",number[i]);

   return 0;
}
