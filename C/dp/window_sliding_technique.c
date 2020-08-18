/* This program will give you the Maximum sum of k consecutive elements of an array
   Gives the result in O(n) time complexity
*/

#include <stdio.h>
#define max(a,b) ((a>b)?a:b)

// Returns the Maximum sum
int maxSum(int a[], int n, int k) 
{ 
  
    // Calculate the sum of first k elements
    int max_sum = 0; 
    for (int i = 0; i < k; i++) 
        max_sum += a[i]; 
  
    // store the max_sum into win_sum
    // Calculate next window sum by adding next element and 
    // subtracting one element kth position back
    // then compare max_sum and win_sum and store the Maximum
    
    int win_sum = max_sum; 
    for (int i = k; i < n; i++) { 
        win_sum += a[i] - a[i - k]; 
        max_sum = max(max_sum, win_sum); 
    } 
  
    return max_sum; 
}

// Driver Code
int main()
{
    int i,n,k;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int a[n];
    
    printf("Enter the elements of array: ");
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
        
    printf("Enter the size of subarray: ");
    scanf("%d", &k);
    
    if(k>n)
        printf("The size of subarray must be less than or equal to the size of main array.");
    else
        printf("Maximum sum of %d consecutive elements= %d", k, maxSum(a,n,k));

    return 0;
}
