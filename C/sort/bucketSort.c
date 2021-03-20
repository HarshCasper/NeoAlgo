/* Bucket Sort in C - Bucket Sort is a sorting algorithm, which is commonly used in 
computer science. Bucket Sort works by distributing the elements of an array into 
a number of buckets. Each bucket is then sorted individually, either using a 
different sorting algorithm, or by recursively applying the bucket 
sorting algorithm. 
# The average time complexity for Bucket Sort is O(n + k). 
  The worst time complexity is O(n²).
# The space complexity for Bucket Sort is O(n+k). */

/* C Program to sort Elements Using Bucket Sort */
#include <stdio.h>

// bucket sort function
void Bucket_Sort(int array[], int n, int max, int min)
{
    int i, j = 0;
    int cpos[max+1], cneg[-(min-1)];
    for (i = 0; i <= max; i++)
        cpos[i] = 0;
    for (i = 0; i <= -(min-1); i++)
        cneg[i] = 0;

    for (i = 0; i < n; i++)
    {
        if (array[i] >= 0)
            (cpos[array[i]])++;
        else
            (cneg[-array[i]])++;
    }

    for (i = -min; i > 0; i--)
        for (; cneg[i] > 0; (cneg[i])--)
            array[j++] = -i;

    for (i = 0; i <= max; i++)
        for (; cpos[i] > 0; (cpos[i])--)
            array[j++] = i;
}

//main fucntion
int main()
{
    int array[100], i, num, max = 0, min = 0;
    printf("Enter the size of array : ");
    scanf("%d", &num);
    printf("Enter the %d elements to be sorted:\n",num);
    for (i = 0; i < num; i++)
        scanf("%d", &array[i]);
    for (i = 0; i < num; i++)
    {
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];
    }
    if (min >= 0)min = 0;
    printf("\nThe array of elements before sorting : \n");
    for (i = 0; i < num; i++)
        printf("%d ", array[i]);
    printf("\nThe array of elements after sorting : \n");
    Bucket_Sort(array, num, max, min);
    for (i = 0; i < num; i++)
    {
        printf("%d ", array[i]);
    }

    return 0;
}

/* 
Output:
Enter the size of array : 8
Enter the 8 elements to be sorted:
5
12
61
1
8
90
37
18
The array of elements before sorting :
5 12 61 1 8 90 37 18
The array of elements after sorting :
1 5 8 12 18 37 61 90 
*/
