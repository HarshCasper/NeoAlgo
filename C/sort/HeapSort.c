/* 
Heap Sort 
Heap Sort is treated as the best sorting technique in the category of selection sorting .
It uses a heap tree as an underlying data structure to soer an array of elements
This is an inplace sorting algorithm as it does not require any extra storage space other 
than the input storage list. This algorithm requires 3 basic steps 
Create heap : Create the initial heap tree with n elements stored in the array A
Remove max : Select the value in the root node and swap with the value in the i'th 
location
Rebuild heap : Rebuild the heap for elements A[1,2,3,..., i - 1]
The first operation is done once , the second and third are done n times 
*/
#include <stdio.h>
#include <stdlib.h>

/* removeMax function is to remove the maximum element, 
which is at the root of the Max heap */

void removeMax(int *b, int n)
{
    int temp = b[n];
    b[n] = b[1];
    b[1] = temp;
}

/* swap function swaps the position of the given two numbers
in the sequence */

void swap(int *b, int a, int c)
{
    int temp = b[a];
    b[a] = b[c];
    b[c] = temp;
}

/* 
reBuildHeap function rebuilds the heap from which the root element was 
removed.
*/

void reBuildHeap(int *b, int i)
{
    if (i == 1)
    {
        return;
    }
    int j = 1;
    int flag = 1;
    while (flag == 1)
    {
        int left = 2 * j, right = (2 * j) + 1;
        if (right <= i)
        {
            if (b[j] <= b[left] && b[left] >= b[right])
            {
                swap(b, left, j);
                j = left;
            }
            else
            {
                if (b[j] <= b[right] && b[right] >= b[left])
                {
                    swap(b, right, j);
                    j = right;
                }
                else
                {
                    flag = 0;
                }
            }
        }
        else
        {
            if (left <= i)
            {
                if (b[j] <= b[left])
                {
                    swap(b, left, j);
                    j = left;
                }
                else
                {
                    flag = 0;
                }
            }
            else
            {
                flag = 0;
            }
        }
    }
}

/*
createHeap function creates a MAX heap from the given sequence of numbers
*/

int *createHeap(int *ar, int n)
{
    int i = 1;
    int *b = (int *)malloc(sizeof(int) * (n + 1));
    while (i <= n)
    {
        int x = ar[i];
        b[i] = x;
        int j = i;
        while (j > 1)
        {
            if (b[j] > b[j / 2])
            {
                int temp = b[j];
                b[j] = b[j / 2];
                b[j / 2] = temp;
                j = j / 2;
            }
            else
            {
                j = 1;
            }
        }
        i++;
    }
    return b;
}

/*
heap_sort function sort the given array of digits 
*/

void heap_sort(int *ar, int n)
{
    int *b = createHeap(ar, n);
    for (int i = n; i > 1; i--)
    {
        removeMax(b, i);
        reBuildHeap(b, i - 1);
    }
    for (int i = 1; i <= n; i++)
    {
        ar[i] = b[i];
    }
}

int main()
{
    int n;
    printf("Enter the number of elements to sort\n");
    scanf("%d", &n);
    int *ar = (int *)malloc(sizeof(int) * (n + 2));
    printf("Enter the elements to sort\n");
    for (int i = 1; i < n + 1; i++)
        scanf("%d", &ar[i]);

    heap_sort(ar, n);
    printf("The sorted list :\n");
    for (int i = 1; i < n + 1; i++)
        printf("%d ", ar[i]);
    return 0;
}

/*
Sample I/O :
Enter the number of elements to sort
5
Enter the number of elements to sort
4 3 2 5 1
The sorted list :
1 2 3 4 5

Time Complexity : O(n log n)
Space Complexity : O(1) 
*/
