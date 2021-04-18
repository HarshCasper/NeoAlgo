/*
Quick sort algorithm starts by choosing a pivot element around which other elements are
arranged by moving the elements smaller to the left while the larger elements are moved to the right.
*/

#include <stdio.h>

int partitionArray(int a[], int low, int high){

    //selecting the pivot as the highest element
    int pivot = a[high];
    int i = low - 1;

    
    for(int j = low; j < high; j++){
        //check for current element with reference to pivot
        if(a[j] < pivot){
            //if less then increase the position
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    //returning the correct position of the index
    return (i + 1);
}
void quickSort(int a[], int low, int high){
    if(low < high){
        //storing the correct position of the pivot in indexPos
        int indexPos = partitionArray(a, low, high);

        //iterating on the left partition
        quickSort(a, low, indexPos-1);
        //iterating on the right partition
        quickSort(a, indexPos + 1, high);
    }
}
void printArray(int a[], int size){
    printf("The sorted array: ");
    int  i;
    for(i = 0; i < size; i++){
        printf("%d ",a[i]);
    }
}
int main(){
    //array to hold elements for sorting
    int A[100];

    int size,i,j;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    //Entering the elements of the array
    printf("Enter the array elements : ");
    for(i = 0; i <size; i++){
        scanf("%d",&A[i]);
    }

    printf("\n");

    quickSort(A, 0, size - 1);

    printArray(A, size);
}

/*Sample Output:
Enter the size of the array: 5
Enter the array elements : 4 6 8 3 1
The sorted array: 1 3 4 6 8
*/
/*
Space complexity: O(N log N)
Time Complexity:
Best Case: Ω(N log N)		
Average Case: Θ(N log N)
Worst Case: O(N^2)
*/
