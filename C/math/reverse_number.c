// C program to reverse a number.
#include <stdio.h>

// Function to reverse a number.
int reverse(int num)
{
    int rev = 0;
    while (num > 0)
    {
        rev = rev * 10;
        //Extract the last digit of the number.
        int rem = num % 10;
        rev = rev + rem;
        num = num / 10;
    }
    return rev;
}

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    int rev = reverse(num);
    printf("The reverse of the given number is %d.", rev);
    return 0;
}

/*
Time Complexity: O(log(n)), where 'n' is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1
Enter the number: 1234
The reverse of the given number is 4321.

SAMPLE 2
Enter the number: 785487
The reverse of the given number is 784587.
*/
