// C program to toggle the k-th bit of a number.

#include <stdio.h>

int toggle_k_bit(int n, int k)
{
    return n ^ (1 << (k - 1));
}

int main()
{
    int n, k;

    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Enter the value of k(where you need to toggle the k'th bit) ");
    scanf("%d", &k);

    printf("The given number, after toggling the k-th bit is %d", toggle_k_bit(n, k));

    return 0;
}

/*
Time Complexity: O(1)
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
Enter the number: 24
Enter the value of k(where you need to toggle the k'th bit): 3
The given number, after toggling the k-th bit is 28.

SAMPLE 2
Enter the number: 33
Enter the value of k(where you need to toggle the k'th bit): 12
The given number, after toggling the k-th bit is 2081.
*/
