// MERGE SORT IN C
#include<stdio.h>
void main()
{
    int arraySize ,  index;
    printf("Please enter the size of the array\n");
    scanf("%d",&arraySize);
    int arr[arraySize];
    printf("Please enter the elements to sort\n");
    for(index=0 ; index<arraySize ; index++)
    {
        scanf("%d",&arr[index]);// You would now fill the array with the numbers you want to sort
    }

    // Now the lower bound and upper bound values would be defined

int lower_bound =0;
int upper_bound = arraySize-1;

// we pass three parameters to the mergeSort function

mergeSort(arr,lower_bound, upper_bound);

printf("SORTED ARRAY\n");

for(index=0 ; index<arraySize ; index++)
    {
        printf("%d\t",arr[index]);
    }

}
int mergeSort(int arr[],int lower_bound, int upper_bound)
{
    // We use recursion to divide the array

    if(lower_bound<upper_bound)
    {
        int mid = (lower_bound+upper_bound)/2;
        mergeSort(arr,lower_bound,mid);
        mergeSort(arr,mid+1,upper_bound);

        // Now we use merge function to join the array in a sorted manner
        merge(arr , lower_bound , mid , upper_bound );
    }
}
int merge(int arr[],int lower_bound , int mid , int upper_bound )
{
    int variable_a = lower_bound ;
   int variable_b = mid+1;
    int variable_c = lower_bound;
    int size = upper_bound+1 ;
    int arr_new[size]; // we create a new array by arr_new
    while(variable_a<=mid && variable_b<=upper_bound )
    {
        if(arr[variable_a]<=arr[variable_b])
{
    arr_new[variable_c] = arr[variable_a];
    variable_a++;

}
else
{
    arr_new[variable_c] = arr[variable_b];
    variable_b++ ;

}
variable_c++;
    }

    if(variable_a>mid)
    {
        while(variable_b<=upper_bound)
        {
            arr_new[variable_c] = arr[variable_b];
            variable_b++ ;
            variable_c++;

        }

    }
else
{
    while(variable_a<= mid )
    {
        arr_new[variable_c] = arr[variable_a];
        variable_a++ ;
        variable_c++ ;

    }
}
for(variable_c=lower_bound; variable_c<=upper_bound ; variable_c++)
    // Copying the sorted values from array_new to arr
    {
       arr[variable_c] = arr_new[variable_c];
    }

}



