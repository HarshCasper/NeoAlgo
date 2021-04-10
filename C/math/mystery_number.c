// C program to Check if a number is a Mystery Number or Not.
/*
A mystery number is that number which can be expressed as a sum of two 
numbers and those two numbers must be the reverse of each other
*/
#include <stdio.h>
#include <stdbool.h>

// Helper function to reverse a number.
int reverse(int n)
{
    int rev = 0;
    for (; n > 0; n /= 10)
    {
        rev = rev * 10;
        rev = rev + (n % 10);
    }
    return rev;
}

bool check_mystery_num(int n)
{
    /* Let us iterate from 1 upto n/2, to check if there is any pair, such that thier
       sum equals the given number and check if the pair are reverse of each other  */
    for (int i = 1; i <= n / 2; i++)
    {
        if (reverse(i) == n - i)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    bool res = check_mystery_num(n);
    if (res)
    {
        printf("The given number %d is a Mystery Number.", n);
    }
    else
    {
        printf("The given number %d is not a Mystery Number.", n);
    }
    return 0;
}

/*
Time Complexity: O(n*log(n)), where 'n' is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
Enter the number: 43234
The given number 43234 is a Mystery Number.

SAMPLE 2
Enter the number: 1234
The given number 1234 is not a Mystery Number.

*/
