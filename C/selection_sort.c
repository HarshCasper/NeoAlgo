/*
selection sort is an in-place comparison sorting algorithm. It has an O(n²) time complexity, 
which makes it inefficient on large lists, and generally performs worse than the similar insertion 
sort. 

Time complexity:O(n^2)

The selection sort algorithm sorts an array by repeatedly finding the minimum element
(considering ascending order) from unsorted part and putting it at the beginning.
The algorithm maintains two subarrays in a given array.

1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.

In every iteration of selection sort, the minimum element (considering ascending order) from the 
unsorted subarray is picked and moved to the sorted subarray.

arr[] = 64 25 12 22 11   min(11,25,12,22,64)=11

// Find the minimum element in arr[0...4]
// and place it at beginning
11 25 12 22 64                                min(12,25,22,64) = 12

// Find the minimum element in arr[1...4]
// and place it at beginning of arr[1...4]
11 12 25 22 64                                min(25,22,64) = 22

// Find the minimum element in arr[2...4]
// and place it at beginning of arr[2...4]
11 12 22 25 64                                min(25,64) = 25

// Find the minimum element in arr[3...4]
// and place it at beginning of arr[3...4]
11 12 22 25 64                                 min(64) = 64

*/

#include<stdio.h>
#include<stdlib.h>




void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}
//create a array dynamically
int* create(int n){
    int *a = (int*)malloc(n*sizeof(int));

    for (int i = 0; i < n; i++)
    {
        /* take input using element */
        scanf("%d",(a+i));
    }

    return a;
    
}

//display the arrray
void display(int* a,int n){
     for (int i = 0; i < n; i++)
     {
         /* display it */
         printf("%d",*(a+i));
         printf(" ");
     }
     
}

//selection sort function
int* selection_sort(int *a,int n){
     int i, j, min_index; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_index = i; 
        for (j = i+1; j < n; j++) 
          if (a[j] < a[min_index]) 
            min_index = j; 
  
        // Swap the found minimum element with the first element 
        swap(&a[min_index], &a[i]); 
    } 

     return a;
     
}

int main(int argc, char const *argv[])
{
    int n;

    printf("\nenter teh size of the array:");
    scanf("%d",&n);

    int* a = create(n);
    
     
    printf("\nunsorted array:");
    display(a,n);

    int *b = selection_sort(a,n);
  
    printf("\n\nsorted array:");
    display(b,n);

    return 0;
}


