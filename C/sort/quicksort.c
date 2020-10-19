#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int partition(int* arr,int l,int h){
    int pivot=arr[h];
    int i=l-1,j;
    for(j=l;j<=h-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }

    }
    swap(&arr[i+1],&arr[h]);
    return i+1;
}

void quickSort1(int* arr,int l,int h){
    if(l<h){
        int poi=partition(arr,l,h);
        quickSort1(arr,l,poi-1);
    quickSort1(arr,poi+1,h);
    }

}

void quickSort(int* input, int size){
    quickSort1(input,0,size-1);
}
int main(){
    int n,i;
    int *input;
    printf("Enter the number of elements:\n" );
    scanf("%d",&n);

    input =(int*)malloc(n*sizeof(int));
    printf("Enter the elements: \n");
    for(i = 0; i < n; i++) {
        scanf("%d",&input[i]);
    }

    quickSort(input, n);
    printf("The sorted elements are: \n");
    for(i = 0; i < n; i++) {
        printf("%d ",input[i]);
    }
	return 0;
}