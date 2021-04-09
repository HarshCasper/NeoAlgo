// C Program to find the Number of Digits of a given number
#include <stdio.h>

int sum_of_digits(int num)
{
    int cnt = 0;
    while (num != 0)
    {
        cnt++;
        // Removing the least significant digit
        num = num / 10;
    }
    return cnt;
}

int main()
{
    int num, cnt;
    printf("\nEnter the number: ");
    scanf("%d", &num);

    // If the number is negative, convert it into positive
    if (num < 0)
    {
        num = num * -1;
    }

    // Call the function
    cnt = sum_of_digits(num);
    // Print the obtained count
    printf("The number of digits in the given number is: %d", cnt);
    return 0;
}

/*
Time Complexity- O(log(num)), where 'num' is the given num
Space Complexity- O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

Enter the number: 1231
The number of digits in the given number is: 4
*/
