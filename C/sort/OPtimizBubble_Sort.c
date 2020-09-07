/*Bubble Sort Algorithm is the sorting algorithm in which each element is compared to its adjacent element 
and if first elememt is greater than second element ,then the swapping occurs.
The swapping occurs till the array is sorted.
*/
// C program to illustate Optimized Bubble Sorting

#include<stdio.h>
#include<stdbool.h>

int main() {
  //Declarartion of required variables
  int size, arr[size], temp;
  bool sort = true;
  //Reading Input
  printf("Input :\n");
  printf("Enter the size of an array : \n");
  scanf("%d", & size);
  printf("Enter the elements of an array :\n");
  for (int index = 0; index < size; index++) {
    scanf("%d", & arr[index]);
  }
  //Outer Loop
  for (int index = 0; index < size; index++) {
    //Inner Loop
    for (int j = 0; j < size - 1 - index; j++) {
      //Checking if the adjacent element is larger 
      if (arr[j] > arr[j + 1]) {
        //Swapping the elements, temp is used to store the temporary variable
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        sort = false;
      }
    }
    if(sort) {
      break;
    }
  }
  //Displaying Output
  printf("Output :\n");
  printf("The sorted array is :\n");
  for (int index = 0; index < size; index++) {
   printf("%d ", arr[index]);
  }
  return 0;
}

/*
 Input:
 Enter the size of an array: 5
 Enter the elements of an array :
 7 9 8 2 4
 Output :
 2 4 7 8 9
 Time Complexity :O(n)
 Space Complexity :O(1)
*/