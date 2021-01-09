/* Counting sort is a sorting algorithm that sorts the elements of an array by 
counting the number of occurrences of each unique element in the array. 
The count is stored in an auxiliary array and the sorting is done by 
mapping the count as an index of the 
auxiliary array.
# The average time complexity for Counting Sort is O(n + k). 
  The worst time complexity is O(n + k).
  where n is the number of elements in input array and k is the range of input.
# The best complexity for Counting Sort is O(n + k). */

/* C Program to sort Elements Using Counting Sort */
#include <stdio.h>  
 
/*  Counting sort function  */
void counting_sort(int A[], int k, int n)
{
    int i, j;
    int B[n], C[k];
    for (i = 0; i <= k; i++)
        C[i] = 0;
    for (j = 1; j <= n; j++)
        C[A[j]] = C[A[j]] + 1;
    for (i = 1; i <= k; i++)
        C[i] = C[i] + C[i-1];
    for (j = n; j >= 1; j--)
    {
        B[C[A[j]]] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    printf("The Sorted array is : ");
    for (i = 1; i <= n; i++)
        printf("%d ", B[i]);
}
/*  End of counting_sort()  */
 
/*  The main() begins  */
int main()
{
    int n, k = 0, A[n], i;
    printf("Enter the number of input : ");
    scanf("%d", &n);
    printf("\nEnter the elements to be sorted :\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
        if (A[i] > k) {
            k = A[i];
        }
    }
    counting_sort(A, k, n);
    printf("\n");
    return 0;
}

/* 
Output:
Enter the number of input : 10
 
Enter the elements to be sorted :
21 4 18 15 24 6 9 1 5 4
The Sorted array is : 1 4 4 5 6 9 15 18 21 24
*/
