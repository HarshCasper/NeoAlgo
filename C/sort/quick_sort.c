#include <stdio.h>
#define MAX 100
int partation(int array[], int beg, int end);
void quick_sort(int array[], int beg, int end);

int main()
{
    int arr[MAX], index , arrSize;
    printf("\nEnter the number of elements in array:");
    scanf("%d",&arrSize);
     printf("\nEnter the elements in array:");
    for (index=0; index<arrSize; index++){
        scanf("%d", &arr[index]);
    }
    quick_sort(arr, 0, arrSize-1);
    printf("\nThe sorted array is: \n");
    for (index=0;index<arrSize;index++){
        printf("%d \t", arr[index]);
    }
    
    return 0;
}

int partation(int array[], int beg, int end)
{
    int left, right, temp, loc, flag=0;
    loc= left= beg;
    right= end;
    while(flag != 1){
        while((array[loc] <= array[right]) && (loc!=right)){
            right --;
        }
        if(loc==right){
            flag=1;
        }
        else if (array[loc] > array[right]){
            temp = array[loc];
            array[loc] = array[right];
            array[right] = temp;
            loc =right;
        }
        if(flag!=1){
            while((array[loc]>=array[left]) && (loc!=left)){
                left ++;
            }
            if(loc==left){
                flag=1;
            }
            else if (array[loc] < array[left]){
                temp = array[loc];
                array[loc] = array[left];
                array[left] = temp;
                loc=left;
            }
        }
    }
    return loc;

}

void quick_sort(int array[], int beg, int end){
    int loc;
    if(beg<end){
        loc= partation(array,beg,end);
        quick_sort(array,beg,loc-1);
        quick_sort(array,loc+1,end);
    }
}