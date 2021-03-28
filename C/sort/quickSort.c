/*Quick Sort is a divide and conquer algorithm which works on the basic principle 
of finding a pivot element and dividing the elements in two parts that is, elements
smaller than pivot are kept on one side and the element larger than the pivot element 
are placed on the other side of the pivot element.*/

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
