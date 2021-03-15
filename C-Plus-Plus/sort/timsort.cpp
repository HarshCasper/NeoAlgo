//Implementing TimSort in C++
#include<bits/stdc++.h>
using namespace std;

const int Run = 32;

void insertionSort(int arr[], int left, int right){ //for sorting array from left to right which is of size atmost Run
    for(int i=left+1; i<=right; i++){ 
        int temp = arr[i]; 
        int j=i-1; 
        while(j>=left && arr[j]>temp){ 
            arr[j+1] = arr[j]; 
            j--; 
        } 
        arr[j+1] = temp; 
    } 
} 
  
void merge(int arr[], int l, int m, int r){ //for merging the sorted runs
    // Breaking the original array into left and right
    int len1=m-l+1, len2=r-m; 
    int left[len1], right[len2]; 
    for(int i=0; i<len1; i++) left[i] = arr[l+i]; 
    for (int i=0; i<len2; i++) right[i] = arr[m+1+i]; 
    int i=0, j=0, k = l; 
    //We merge these two arrays into larger subarray after comparing 
    while(i<len1 && j<len2){ 
        if(left[i]<=right[j]){ 
            arr[k] = left[i]; 
            i++; 
        }else{ 
            arr[k] = right[j]; 
            j++; 
        } 
        k++; 
    }
    //Copying the leftover elements of left 
    while(i<len1){ 
        arr[k] = left[i]; 
        k++; 
        i++; 
    } 
    //Copying the leftover elements of right 
    while(j<len2){ 
        arr[k] = right[j]; 
        k++; 
        j++; 
    } 
} 
   
void timSort(int arr[], int n){ //TimSort function for sorting
    for(int i=0; i<n; i+=Run) insertionSort(arr, i, min((i+31), (n-1))); //Sorting subarrays of size Run individually
    for(int size=Run; size<n; size=2*size){ //We now start merging from size Run(that is 32) which will merge to form sizes 64, 128, etc.
        //Algorithm: Pick the starting element of left and we will merge arr[left..left+size-1] and arr[left+size, left+2*size-1]. After merging each time we increment left by 2*size.
        for(int left=0; left<n; left += 2*size){
            //Now we find end point of left subarray by treating mid+1 as the starting of right subarray
            int mid=left+size-1; 
            int right=min((left + 2*size - 1), (n-1)); 
            //Now merge arr[left...mid] and arr[mid+1...right]
            merge(arr, left, mid, right); 
        } 
    } 
}
  
//Main Function 
int main(){ 
    int arr[] = {-4, 5, 13, -16, -2, 13, -2, 5, -9, -6, -15, 3, 6, -16, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("Given Array is\n"); 
    for (int i = 0; i < n; i++) 
        printf("%d  ", arr[i]); 
    printf("\n"); 
    timSort(arr, n); 
    printf("After Sorting Array is\n"); 
    for (int i = 0; i < n; i++) 
        printf("%d  ", arr[i]); 
    return 0; 
} 