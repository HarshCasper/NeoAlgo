
/*
Shaker sort (aka bidirectional bubble sort) is an algorithm used to sort a given array of numbers.The algorithm consists of four steps 
for every forward iteration we have a starting index(named index in this code) , a terminating index(named size in this code). 
STEP 1->Before each forward treversal flag is set to false.
STEP 2->Forward traverse the list and compare every two consecutive elements and perform swap operation if required.(similar to bubble sort)
STEP 3->Update the flag pointer and set it true whenever a swap operation is performed. This is done to keep a track of the swap operation performed.
STEP 4->If no swap operation was done in STEP 1,skip reverse traversal of the list otherwise set the flag to false and reverse traverse the list (reverse traversal starts from index size-1).(similar to bubble sort on reversed array)
we are sorting the list in forward as well as in the backward direction. 
i.e If the user choose to sort in ascending order, the forward traversal brings the largest element in the list at last index of forward traversal(size)and the reverse traversal brings the smallest element at the first index (index).
Similarly for sorting in descending order the smallest element is popped at the last index of forward iteration(size) of the list and the largest element is popped at the first index (index) of the array.
STEP 5->update the value of first index and last index for next traversal (index = index+1, size =size-1) and start again with step 1 till flag pointer becomes false for any traversal of the array .(which means if for one forward or reverse traversal there were no consecutive values which were swapped then the list is sorted)

PSEUDO CODE FOR SORTING AN ARRAY IN ASCENDING ORDER 
index=0;
size=length(array);
flag=false;
while(flag)
{
    for (int i=index;i<size-1;i++)
        if (array(i)<array(i+1))
            swap(array(i),array(i+1))
            flag=true;
    if (flag)
        flag=false;
        for (int j=i;j++;j>index)
            if(array(j)<array(j-1))
                swap(array(j),array(j-1));
                flag=true;
     index++;
     size--;
}
*/


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
                        flag=true;      //we set flag= true to keep a track of the swapping operation performed of the array 
                    }
                }
                /*checking if flag==true which means than no two values were swapped indicating that the array is already sorted
                if already sorted, we need not perform any operation on the array now. */
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

// function for implementing shaker sort which sorts the elements in descending order
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
                 /*checking if flag==true which means than no two values were swapped indicating that the array is already sorted
                if already sorted, we need not perform any operation on the array now.*/
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
    clock_t start= clock(); 
    // storing the initial time when the computation for the program begins
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
    clock_t end= clock(); 
    // storing the time when the computation ended
    float time_taken= (float)(end- start)/CLOCKS_PER_SEC;
    printf("\n%f seconds\n",time_taken); 
    // displaying the time taken for our programme to complete executing the algorithm
    free(arr);// free the space used to store the elements of the array
    return(0);
}
/* 
Time complexity
Average case time complexity - O(n*n)
Worst case time complexity- O(n)

Space complexity-
shaker sort is an inplace sorting algorithm .
space complexity = O(1)

run the code using the following commands
$gcc filename.c
$./a.out

input format 
first line should be the size of the array
second line should be the array elements (they should be integers)
third line should be the order in which you want to sort the array choose 1 for ascending order and 2 for descending order

sample input output 
input-
10
1 2 3 -5 -5 69 23 8 6 10 
1
output - -5 -5 1 2 3 6 8 10 23 69 
time_taken=0.000008 seconds
*/

