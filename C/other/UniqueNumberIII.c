#include<stdio.h>

main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n], i;
    printf("\nEnter %d elements: ", n);
    for(i = 0 ;i < n ;i++)
    {
        scanf("\n%d",&arr[i]);
    }
    int one = 0;
    int two = 0;
    int n_t, x;
    for(i = 0; i < n; i++)
    {
        x = arr[i];
        two |=one & x;
        one ^= x;
        n_t  =~(one & two);
        one &= n_t;
        two &= n_t;
    }
    printf("\nThe number that occurs only once is %d \n", one);
}

/*
Time complexity: O(n)
Space complexity: O(n)

Example 1:
Sample input:
Enter number of elements: 7
Enter 7 elements: 6 
2
5
2
2
6
6 
Output: The number that occurs only once is 5

Example 2:
Sample Input: 
Enter number of elements: 4
Enter 4 elements: 3 
3
1
3 
Output: The number that occurs only once is 1 
*/
