/* To print the occurrence of the given number in the list/array using Binary Search Technique */

#include <stdio.h>
int Binary_search_algo_for__finding_occurrence(int array[], int sizeOf_array, int number, int found)
{
    int start = 0, end = sizeOf_array - 1;

// initializing value
    int value = -1;

    while (start <= end)
    {
        int middle = (start + end) / 2;

        /*** CASE : number equals middle element ***/
        if (number == array[middle]) // if both are equal then we update the 'value'
        {
            value = middle;
            if (found) { // searching in left side
                end = middle - 1;
            }
            else { // searching in right side
                start = middle + 1;
            }
        }

        /*** CASE : number less than middle element ***/
        else if (number < array[middle])
        {
            end = middle - 1;
        }

        /*** CASE : number greater than middle element (last case) ***/
        else
        {
            start = middle + 1;
        }
    }
    return value;
}

int quickSort(int array[] , int lower_bound , int  upper_bound)
{
    int temp ;

    if (lower_bound < upper_bound)
    {
        temp = partition(array , lower_bound , upper_bound );// as partition function would return end index which would be used further
        quickSort(array , lower_bound , temp - 1);
        quickSort(array , temp + 1, upper_bound);
    }
}

int partition(int array[], int lower_bound, int upper_bound)
{
    int pivot , start , end , t;
    pivot = array[lower_bound];
    start = lower_bound ;
    end = upper_bound ;

    while (start < end)
    {
        while (array[start] <= pivot)
        {
            start++;
        }
        while (array[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {   //swap
            t = array[start];
            array[start] = array[end];
            array[end] = t;
        }
    }
    //if the condition is not followed then we replace the 'end' with 'pivot' element and return end
    //swap
    t =  array[lower_bound];
    array[lower_bound] = array[end];
    array[end] = t ;

    return end ;
}

int main()
{
//declaring the size of array
    int sizeOf_array;
    printf("The size of array is:\n");
    scanf("%d", &sizeOf_array);

// defining the array
    int array[sizeOf_array];
    printf("Please input the elements in array:\n");

// storing elements in array
    for (int i = 0 ; i < sizeOf_array; i++) {
        scanf("%d", &array[i]);
    }
    printf("\n");

    int number; // we would input the number whose occurrence must be returned.
    printf("The number whose occurrence must be found : ");
    scanf("%d", &number);

// we would sort the array using quickSort
    int lower_bound = 0 , upper_bound = sizeOf_array - 1;

    quickSort(array , lower_bound , upper_bound);

// now we have sorted the array

// we pass 1 for the first occurrence of the number
    int first_occurrence_of_number = Binary_search_algo_for__finding_occurrence(array, sizeOf_array, number, 1);

// we pass 0 for the first occurrence of the number
    int last_occurrence_of_number = Binary_search_algo_for__finding_occurrence(array, sizeOf_array, number, 0);

// now we would subtract the first & last occurrence to get the total occurrences of the number
    int total_occurrences_of_number = last_occurrence_of_number - first_occurrence_of_number + 1;

    if (first_occurrence_of_number != -1) {
        printf("The number: %d occurs %d times in the given array.", number, total_occurrences_of_number);
    }
    else {
        printf("Error! The number is not present in the array.");
    }

    return 0;
}
