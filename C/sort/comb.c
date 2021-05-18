
/*

COMB SORT :

Comb Sort is mainly an improvement over Bubble Sort. Bubble sort always compares adjacent values.
So all inversions are removed one by one. Comb Sort improves on Bubble Sort by using gap of size
more than 1. The gap starts with a large value and shrinks by a factor of 1.3 in every iteration
until it reaches the value 1. Thus Comb Sort removes more than one inversion counts with one swap
and performs better than Bubble Sort.
*/



#include <stdio.h>

void comb_sort(int *ar, int n){

    //gap variable gives gap between the values to compare
    int gap = n;
    int q,w;
    
    while(gap>1){
        //updating the gap variable
        gap = gap/1.3;
        if(gap<1){
            gap = 1;
        }
        q=0;w=q+gap;
        while(w<n){
            if(ar[q]>ar[w]){
		        //swap values
                int temp = ar[q];
                ar[q] = ar[w];
                ar[w] = temp;
            }
            w++;q++;
        }
    }
}

int main()
{
    int n;
    int *ar;
    printf("Enter the limit : ");

    //Input the number of elements to be sorted
    scanf("%d",&n);

    //Dynamically allocate memory for the array
    ar = (int*)malloc(n * sizeof(int));

    //Input numbers to be sorted
    for(int i=0;i<n;i++){
        scanf("%d",&ar[i]);
    }
    
    printf("Unsorted array : \n");

    //Print the unsorted array
    for(int i=0;i<n;i++){
        printf("%d ",ar[i]);
    }
    printf("\n\n");
    
    //Execute the comb sort function
    comb_sort(ar, n);
    
    printf("Sorted array : \n");

    //Print the sorted array
    for(int i=0;i<n;i++){
        printf("%d ",ar[i]);
    }
    
    return 0;
}

/*
CASE 1:
input = [1, 8, 7, 61, 5, 4, 11];
EXPECTED: [1,4,5,7,8,11,61]

CASE 2:
input = [1,8,3,9,10,10,2,4];
EXPECTED: [1,2,3,4,8,9,10,10]

    Time Complexity - O(n log n) for the best case.
                      O(n^2/2^p) (p is a number of increment) for average case.
                      O(n^2) for the worst case.
    Space Complexity - O(1)

*/

