/*
This progarm is about finding a pair of element with sum k using hash table in a
Unsorted array.
Here user going to give an input of k value based upon the input the code will
check whether all the possible pair sum from the array
is equal to k value or not.

Ex:-
array = {1,7,4,2,3} , K = 5

1 + 7 != 5
1 + 4  = 5
1 + 2 != 5
...
...
...
2 + 3  = 5

The above array is unsorted. The code will take up all the possible pair
from the array. It will keep on going
until array becomes empty and it will add up those pair from
array and check whether the pair of sum and k is equal or not.
If it is equal then it will show in the output screen else not.

*/
#include <stdio.h>
#include <stdlib.h>
// Define a structure for an array.
struct Array {
  int *A;
  int size;
};
void pairwithsumhash(struct Array arr) {
  // Declaring a greatestno and smallestno
  int i, greatestno = 0, smallestno = 32767;
  // Declaring a integer type pointer for hash table
  int *H;
  // Declaring a variable
  int k;
  printf("Enter the sum of k:");
  // Taking inputs for sum of k
  scanf("%d", &k);
  for (i = 0; i < arr.size; i++) {
    // Checking for greatestno in the array
    if (arr.A[i] > greatestno)
      greatestno = arr.A[i];
    // Checking for smallestno in the array
    if (arr.A[i] < smallestno)
      smallestno = arr.A[i];
  }
  // Allocating memory dynamically
  H = (int *)malloc((greatestno + 1) * sizeof(int));
  // Defining hash table size as per the greatestno
  for (int i = 0; i < greatestno + 1; i++)
    H[i] = 0;
  // Incrementing hash table for every array value.
  for (int i = 0; i < arr.size; i++)
    H[arr.A[i]] = 1;
  for (i = 0; i < arr.size; i++) {
    // Applying condition
    if ((k - arr.A[i]) >= 0 && H[k - arr.A[i]] != 0) {
      // Printing the result if condition satisfies.
      printf("%d+%d=%d\n", arr.A[i], k - arr.A[i], k);
      // Decrementing hash table
      H[arr.A[i]]--;
    }
  }
  // Deleting the memory
  free(H);
  // Making pointer to NUll.
  H = NULL;
}
int main() {
  // Declaring struct
  struct Array arr;
  // Declaring the varibles.
  int ch, i;
  printf("Enter Size of Array");
  // Asking user to enter the size of the array.
  scanf("%d", &arr.size);
  // Alloacting memory for an array dynamically.
  arr.A = (int *)malloc(arr.size * sizeof(int));
  printf("Enter the array elements");
  for (i = 0; i < arr.size; i++) {
    // Asking user to enter the array values.
    scanf("%d", &arr.A[i]);
  }
  do {
    printf("\n1. Find a pair of element with sum k using hash in a Unsorted "
           "array: \n");
    printf("2. Exit\n");
    printf("enter you choice ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      printf("Pair of Elements with sum k using hash table in a unsorted "
             "array: \n");
      pairwithsumhash(arr);
      break;
    }
  } while (ch < 2);
  // Deleting the array
  free(arr.A);
  // Making pointer to point on NUll.
  arr.A = NULL;
  return 0;
}

// Output:-
/*
Enter Size of Array5
Enter the array elements4
2
1
3
8

1. Find a pair of element with sum k using hash in a Unsorted array:
2. Exit
enter you choice 1
Pair of Elements with sum k using hash table in a unsorted array:
Enter the sum of k:5
4+1=5
2+3=5

*/

