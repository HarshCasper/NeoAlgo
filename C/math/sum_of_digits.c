// C Program to find the Sum of Digits of a given number
#include <stdio.h>

int sum_of_digits(int num)
{
    int S = 0;
    while (num != 0)
    {
        // Extracting the digits from the number
        int rem = num % 10;
        S += rem;
        // Removing the extracted digit
        num = num / 10;
    }
    return S;
}

int main()
{
    int num, sum;
    printf("\nEnter the number: ");
    scanf("%d", &num);

    // If the number is negative, convert it into positive
    if (num < 0)
    {
        num = num * -1;
    }

    // Call the function
    sum = sum_of_digits(num);
    // Print the obtained sum
    printf("The sum of the digits of the given number is: %d", sum);
    return 0;
}

/*

Time Complexity- O(log(num)), where 'num' is the given num
Space Complexity- O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

Enter the number: 1231
The sum of the digits of the given number is: 7
*/
