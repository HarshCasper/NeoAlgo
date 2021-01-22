//***************************** CODE ************************************
#include <stdio.h>   
int countingSort(int A[], int k, int n){
 int i, j;
 int B[15], C[100];
 for (i = 0; i <= k; i++){
   C[i] = 0;
 }
 for (j = 1; j <= n; j++){
   C[A[j]] = C[A[j]] + 1;
 }
 for (i = 1; i <= k; i++){
   C[i] = C[i] + C[i-1];
 }
 for (j = n; j >= 1; j--){
   B[C[A[j]]] = A[j];
   C[A[j]] = C[A[j]] - 1;
 }
 printf("The Sorted array is : ");
 for (i = 1; i <= n; i++){
   printf("%d ", B[i]);
 }
 return 0;
}
int main(){
 int n, k = 0, A[15], i;
 printf("Enter the number of input : ");
 scanf("%d", &n);
 printf("\nEnter the elements to be sorted :\n");
 for (i = 1; i <= n; i++){
   scanf("%d", &A[i]);
   if (A[i] > k) {
      k = A[i]; }   
 }
 countingSort(A, k, n);
 printf("\n");
 return 0;
}

//*************************** SAMPLE OUTPUT ******************************
/*
Enter the number of input : 12
Enter the elements to be sorted : 76 54 32 90 87 55 32 65 77 88 42 10
The Sorted array is : 10 32 32 42 54 55 65 76 77 87 88 90 
*/

//************************* COMPLEXITIES **********************************
/*
Counting sort is an algorithm for sorting a collection of objects according to keys that are small integers i.e; it is an integer sorting algorithm. It operates by counting the number of objects that have each distinct key value, and using arithmetic on those counts to determine the positions of each key value in the output sequence. 
Worst complexity: O(n+k)
Average complexity: O(n+k)
Space complexity: O(n+k)
where n is the number of elements in input array and k is the range of input.
*/

//*********************************************************************
//This code is by japneetbhatia for submission in DWOC
