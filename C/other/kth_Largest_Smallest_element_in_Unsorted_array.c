/* Find kth Largest / Smallest element in Unsorted array */

#include<stdio.h>
#include<stdlib.h>

/* Sorting comparing function */
int compare(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


/* Function for finding kth largest element */
int Kth_largest(int a[], int n, int k)
{
    return a[k + 1];
}

/* Function for finding kth Smallest element */
int Kth_smallest(int a[], int n, int k)
{
    return a[k - 1];
}


/* Function for finding kth Largest / Smallest element in Unsorted array */
void solve()
{
    /* Input n = size of array */
    int n;
    scanf("%d", &n);

    /* Create an empty array */
    int a[n];

    /* Input values in array */
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }

    /* Input k */
    int k;
    scanf("%d",&k);

    /* Sort the given array */
    qsort(a, n, sizeof(int), compare);


    int large = Kth_largest(a,n,k);

    printf("kth largest element is : %d", large);

    int small = Kth_smallest(a,n,k);
    
    printf("\nkth smallest element is : %d", small);
}  

int main()
{
    solve();
    return 0;
}

/*
Test cases :
    
    Input 1 :
        
        6
        7 10 4 3 20 15
        3

    Output 1 :

        kth largest element is : 15
        kth smallest element is : 7

    Input 2 :

        5 
        12 3 5 7 19
        2

    Output 2 :
    
        kth largest element is : 12
        kth smallest element is : 5
    
    Time complexity: O(nlogn)
    Space Complexity: O(n)
*/
