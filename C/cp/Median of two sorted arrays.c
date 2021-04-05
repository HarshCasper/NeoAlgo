
////Given two sorted arrays nums1 and nums2 of size m and n 
//respectively, return the median of the two sorted arrays
#include<stdio.h>
#include<stdlib.h>
double findMedianSortedArrays(int* arr1, int n, int* arr2, int m);
int main(){

  int n,m;
  int sum=0, s=0;
  //accepting the sizes
  scanf("%d %d",&n,&m);
  int *arr1 = (int *) malloc(sizeof(int)*n);
  int *arr2 = (int *) malloc(sizeof(int)*m);
  //accepting the array elements
  for(int i=0;i<n;i++){
    scanf("%d ",arr1+i);

  }
  for(int i=0;i<m;i++){
    scanf("%d ",arr2+i);

  }
//print the median
 printf("%f",findMedianSortedArrays(arr1, n, arr2, m));
 return 0;
}

//function to find the median of two arrays
double findMedianSortedArrays(int* arr1, int n, int* arr2, int m){
    //create a new array to store the two arrays
    int arr3Size = n+m;
    int *arr3 = (int *) malloc(sizeof(int)*arr3Size);
    int j=0, k=0;
    //if arraysize is 0 then return 0
    if (arr3Size == 0)
        return 0;
    //if any arraysize is 0 then store the other array in arr3
    else if (n == 0) {
        for (int i=0; i < m; i++) {
            arr3[i] = arr2[i];
        }
    }
    else if (m == 0) {
        for (int i=0; i < n; i++) {
            arr3[i] = arr1[i];
        }
    }
    else {
        //now store the two arrays in the new created array
        for (int i=0; i < arr3Size; i++) {
            if (k == m && j < n){
                arr3[i] = arr1[j];
                j++;
            }
            else if (j == n && k < m) {
                arr3[i] = arr2[k];
                k++;
            }
            else if (arr2[k] < arr1[j]) {
                arr3[i] = arr2[k];
                k++;
            }
            else if (arr1[j] <= arr2[k]){
                arr3[i] = arr1[j];
                j++;
            }
        }
    }

    if (arr3Size == 1)
        return arr3[0];
      //if array size is even then return mid element  
   else if (arr3Size % 2 == 0) {
       int index = arr3Size/2;
       double median = (arr3[index-1]+arr3[index])/(double) 2;
       return median;
   }
    else {

        return arr3[arr3Size/2];
    }
    //return -1 if none of the conditions satisfy
    return -1;
}
/*
Time complexity: O(n)
Space complexity: O(n)

Example 1:
Input:
2 1
1 3
2
Output:
2.00000

Example 2:
Input:
5 3
1 5 7 8 9
2 4 4
Output:
4.50000

*/

