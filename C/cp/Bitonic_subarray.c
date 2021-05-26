#include <stdio.h>
 
// Function to find the length of the longest bitonic subarray in an array
int findBitonicSubarray(int A[], int n)
{
    // `I[i]` store the length of the longest increasing subarray,
    // ending at `A[i]`
    int I[n + 1];
    I[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        I[i] = 1;
        if (A[i-1] < A[i]) {
            I[i] = I[i-1] + 1;
        }
    }
 
    // `D[i]` store the length of the longest decreasing subarray,
    // starting with `A[i]`
    int D[n + 1];
    D[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        D[i] = 1;
        if (A[i] > A[i+1]) {
            D[i] = D[i+1] + 1;
        }
    }
 
    // consider each element as a peak and calculate LBS
    int lbs_len = 1;
    int beg = 0, end = 0;
 
    for (int i = 0; i <= n; i++)
    {
        if (lbs_len < I[i] + D[i] - 1)
        {
            lbs_len = I[i] + D[i] - 1;
            beg = i - I[i] + 1;
            end = i + D[i] - 1;
        }
    }
 
    // print the longest bitonic subarray
    printf("The length of the longest bitonic subarray is %d\n", lbs_len);
    printf("The longest bitonic subarray is [%d, %d]", beg, end);
 
    return lbs_len;
}
 
int main(void)
{
    int A[] = { 3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4 };
    int n = sizeof(A) / sizeof(A[0]);
 
    findBitonicSubarray(A, n - 1);
 
    return 0;
}


