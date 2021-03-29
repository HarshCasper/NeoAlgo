#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

// the swap function will swap two integers
void swap(int *num1, int *num2)
{
    int temp;
    temp = *num1; // storing the value in a temporary variable
    *num1 = *num2; //storing the data at address2 in address1
    *num2 = temp; // storing the data in temp variable(initial data at address1) in address2
}

//display_array function will display the contents of the array
void display_array(int *a, long long int size){
    int i;
    for (i=0;i<size ;i++)
        printf("%d ", *(a+i));
    printf("\n");
    return ;
}



// function for implementing shaker sort which sorts the elemnts in ascending order
void cocktail_shaker_sort_ascending(long long int size, int *arr){
    long long int i,j,k,index;
    index = 0;
    bool flag = true;
    while(flag)
            {
                flag=false;
                //forward traversing the array , swapping the elements whenever required
                for(j=index;j<size-1;j++){
                    if (arr[j]>arr[j+1])
                    {
                        swap(arr+j,arr+j+1);
                        flag=true;      //we set flag= true to keep a track of the swapping operation performed
                    }
                }
                
                //checking if flag==true which means than no two values were swapped indicating that the array is already sorted
                //if already sorted, we need not perform any operation on the array now. 
                 if (flag==false)
                    break;
                 
                flag=false;
                //if array is not already sorted, reverse traverse the array swapping the elements whenever required
                for(k=j;k>index;k--){
                    if (arr[k]<arr[k-1])
                    {
                        swap(arr + k -1, arr + k );
                        flag=true;      //we set flag= true to keep a track of the swapping operation performed
                    }
                }
                index++;
                size--;
            }
    return;        
}

// function for implementing shaker sort which sorts the elemnts in descending order
void cocktail_shaker_sort_descending(long long int size, int *arr){
    long long int i,j,k,index;
    index=0;
    bool flag;
    flag= true;
    while(flag)
            {
                flag=false;
                //forward traversing the array , swapping the elements whenever required
                for(j=index;j<size-1;j++){
                    if (arr[j]<arr[j+1])
                    {
                        swap(arr+j,arr+j+1);
                        flag=true;     //we set flag= true to keep a track of the swapping operation performed
                    }
                }
                 
                 //checking if flag==true which means than no two values were swapped indicating that the array is already sorted
                //if already sorted, we need not perform any operation on the array now.
                if (flag==false)
                    break;
                 
                 //reverse traversing the array , swapping the elements whenever required
                for(k=j;k>index;k--){
                    if (arr[k]>arr[k-1])
                    {
                        swap(arr + k -1, arr + k );
                        flag=true;     //we set flag= true to keep a track of the swapping operation performed
                    }
                }
                index++;
                size--;
            }
    return;        
}

int main(){
    
    int i,j,k,inp;
    long long int size;//large sized array can also be sorted
    
    printf("enter the size of the array\n");
    scanf("%lli",&size);// user input size of the array
    
    int *arr= malloc(size*sizeof(int));//creating a dynamic array
    
    printf("enter the array\n");
    for(i=0;i<size;i++)
    {
        scanf("%lli",arr + i ); // user input elements of the array.
    }
    
    printf("enter\n 1 -> if you want to sort the array in ascending order\n ");
    printf("2 -> if you want to sort the array in descending order\n ");
    scanf("%d",&inp);
    
    clock_t start= clock(); // storing the initial time when the computation for the programme begins
    
    switch (inp)
    {
        case 1:
        {
            cocktail_shaker_sort_ascending(size,arr);
            display_array(arr,size); // displaying the array after sorting it
            break;
        }
        
        case 2:
        {
            cocktail_shaker_sort_descending(size,arr);
            display_array(arr,size); // displaying the array after sorting it
            break;
        }
    
        default : 
            printf("wrong input\n");
    }
    
    clock_t end= clock(); // storing the time when the computation ended
    float time_taken= (float)(end- start)/CLOCKS_PER_SEC;
    
    printf("\n%f seconds\n",time_taken); // displaying the time taken for our programme to complete executing the algorithm
    
    free(arr);// free the sapce used to store the elements of the array
    
    return(0);
}
// inset check ascending, check descending
