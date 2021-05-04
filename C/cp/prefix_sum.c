/*
Given an array of N elements , find it's prefix sum array. In Competitive Programming, many times we need to calculate prefix sum array to solve our problem.
*/

#include <stdio.h>

void prefix_sum_array(int ar[] ,int N)
{
    int pref_ar[N + 1];
    pref_ar[0] = ar[0];
    int i = 0;
    /* we will add the current element of ar[] array
    and previous element of pref_ar [] array */
    for(i = 1; i < N; i++)
    {
        pref_ar[i] = ar[i] + pref_ar[i - 1];
    }
    printf("The New Prefix sum array is \n");
    for(int i = 0; i < N; i++)
    {
        printf("%d ",pref_ar[i] );
    }
    printf("\n");
    return;
}

int main()
{
    printf("Enter the size of array \n");
    int N;
    scanf("%d", &N);
    int ar[N + 1];
    printf("Enter array elements \n");
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &ar[i]);
    }
    prefix_sum_array(ar , N);
}
/*
Standard Input and Output

Enter the size of array 
7
Enter array elements
10 4 16 34 23 5 90

The New Prefix sum array is
10 14 30 64 87 92 182

Time Complexity : O(N)
Space Complexity : O(N)

*/
