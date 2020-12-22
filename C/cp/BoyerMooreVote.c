/*C code to find the majority element in a given set of string by Boyer-Moore voting algorithm */
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct boyerMajorityCheck{
    int majority_number,majority_check;
};  //declaring a structure for returning two integers in a function

typedef struct boyerMajorityCheck Struct;

//function to find the boyer-moore majority element
Struct boyerMooreVote(int ar[],int len)
{
    Struct bmv;
    int i,count=1;
    int temp=ar[0];
    for(i=1;i<len-1;i++){
        if(count==0){
            temp=ar[i];
            count=1;
        }          
        else{
         if(temp==ar[i]){
             count+=1;
         }
         else{
             count-=1;
         }     
       }
        /*algorithm used to find the majoritty number */
    }
  bmv.majority_number=temp;
  int count2=0;
  for(i=0;i<len-1;i++)
  {
      if(temp==ar[i])
        count2+=1;
  }
  if(count2>len/2)
     bmv.majority_check=1;
  else
     bmv.majority_check=0;
return bmv;
}

//driver function

int main()
{
    int arr[MAX],n,i,result;
    printf("Enter the number of elements:-");
    scanf("%d",&n);
    printf("Enter the elements :-");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    Struct Result=boyerMooreVote(arr,n);
    if (Result.majority_check==0)
      printf("The majority number is %d and it's occurance is less than N/2",Result.majority_number);
    else
    {
        printf("The majority number is %d and it's count is more than N/2",Result.majority_number);
    }
  return 0;
}

/* 
Time complexity : O(n) where n is the snumber of elements
OUTPUT
Enter the number of elements:-8
Enter the elements :-3 4 3 5 3 3 7 9
The majority number is 3 and it's count is more than N/2
*/