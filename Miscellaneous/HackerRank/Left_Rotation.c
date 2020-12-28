
#include <stdio.h>
#include <stdlib.h>


int* rotateLeft(int d, int arr_count, int* arr, int* result_count) {
      *result_count=arr_count;
      int *a=malloc(arr_count*sizeof(int));
      int i,j;
      for(i=0;i<arr_count;i++)
      {
          j=(i+d)%arr_count;
          a[i]=arr[j];
      }
    return a;