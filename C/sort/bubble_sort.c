#include <stdio.h>
#define MAX 100

/*Bubble sort is an algorithm that compares the adjacent elements and swaps 
their positions if they are not in the intended order. 
The order can be ascending or descending.
*/

//prototyping the bubble sort function
void bubble_sort(int a[], int len); //utility function to sort
void print_array(int a[], int n);   //utility function for printiong an array
//initializing main function

int main(int argc, char const *argv[])
{
    //initial array to store elements for sorting.
    int A[MAX];

    //size element to define the size of the array.
    int size, i, j;

    printf("enter the size of array you want:");
    scanf("%d", &size);

    //taking the elements in the array

    for (i = 0; i < size; i++)
    {
        /* take the elements from user */
        printf("\n");
        printf("enter the element of the array:");
        scanf("%d", &A[i]);
    }

    printf("\n");
    printf("the initial unsorted array:");
    print_array(A, size);

    bubble_sort(A, size);

    printf("\n\n");
    printf("The final sorted array:");
    print_array(A, size);

    return 0;
}

void bubble_sort(int a[], int n)
{

    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        j = i;
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                /* code */
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        /* code */
        printf(" %d ", a[i]);
    }
}