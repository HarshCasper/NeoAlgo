/* 

    Iterative version of merge sort in C++ 


We start by sorting all subarrays of 1 element,
then merge results into subarrays of 2 elements,
then merge results into subarrays of 4 elements, 
Likewise,perform successive merges until the array is completely sorted.


*/




#include <iostream>       //Header files 
#include<stdlib.h>
using namespace std;
 
/* Function to merge the two halves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r);
 
// function to find minimum of two integers
int min(int x, int y) {
    return (x<y)? x :y;
    }
 
 
/*

    Iterative mergesort function to sort arr[0...n-1] 

*/

void mergeSort(int arr[], int n) {
   
   int curr_size;  // For current size of subarrays to be merged
                   // curr_size varies from 1 to n/2
                   
   int left_start; // For picking starting index of left subarray
 
 
    /* 
        Merge subarrays in bottom up manner.First merge subarrays of 
        size 1 to create sorted subarrays of size 2, then merge subarrays
        of size 2 to create sorted subarrays of size 4, and so on.
        
    */
   
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size) {
       
       // Pick starting point of different subarrays of current size
       for (left_start=0; left_start<n-1; left_start += 2*curr_size) {
           
           // Find ending point of left subarray. mid+1 is starting 
           int mid = min(left_start + curr_size - 1, n-1);
           
           int right_end = min(left_start + 2*curr_size - 1, n-1);
           
           // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
           merge(arr, left_start, mid, right_end);
       }
   }
}
 
/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r) {
    
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        
        k++;
    }
 
    /* Copy the remaining elements of L[], if there are any */
    while (i < n1) {
        
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there are any */
    while (j < n2) {
        
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
 
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << A[i] << " ";
    }
 
 
int main() {
    
    
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Given array is: " << endl;

    // Calling printarray function to print initial given array
    printArray(arr, n);
    
    // Calling mergesort function to sort elements of array
    mergeSort(arr, n);
 
    // Calling printarray function and printing the result of sorted elements  
    cout << "\nSorted array is:\n";
    printArray(arr, n);
    return 0;

}


/*

Output:

Given array is:                                                                                                                                 
12 11 13 5 6 7

Sorted array is:                                                                                                                                
5 6 7 11 12 13 


time complexity for merge sort is the same in all three cases (worst, best and average)
as it always divides the array into sub-arrays and then merges the sub-arrays taking linear time.
that is of  O (n*logn).

***It saves the auxilary space requires by call stack.


*/