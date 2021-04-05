#include <stdio.h>
#define MAX 100

/*Bubble sort is sorting algorithm in which adjacent elements are compared and swaps 
the elements if they are not in the wrong order. 
The order can be ascending or descending.
*/

//prototyping the bubble sort function
void bubble_sort(int a[], int len); 

// prototype of print array function
void print_array(int a[], int n);   

// main function
int main()
{
    //initial array to store elements for sorting.
    int A[MAX];

    //size element to define the size of the array.
    int size, i;

    printf("enter the size of array you want [max size 100]:");
    scanf("%d", &size);

    //taking the elements by the user in the array

    for (i = 0; i < size; i++)
    {
        printf("\n");
        printf("enter the element of the array:");
        scanf("%d", &A[i]);
    }

    printf("\n");
    printf("the initial unsorted array:");
    print_array(A, size);
// calling of bubble sort function
    bubble_sort(A, size);

    printf("\n\n");
    printf("The final sorted array:");
    print_array(A, size);

    return 0;
}
//function  definition of bubble sort 
void bubble_sort(int a[], int n)
{

    int i, j,flag=0;
    for (i = 0; i < n - 1; i++)
    {
    
        for (j = 0; j < n - i - 1; j++)
        { //compare the adjacent element
            if (a[j] > a[j + 1])
            {
                // swap them 
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag=1;
            }
        }
        /*condition to check any swapping occurs or not.
        if no swapping occurs then the array is already sorted.
         */
        if(flag==0)
        break;
    }
}

void print_array(int a[], int n)
{  int i;
    for ( i = 0; i < n; i++)
    {
        
        printf(" %d ", a[i]);
    }
}

