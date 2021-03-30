// C Program to find the Factorial of a number
#include <stdio.h>

long long unsigned int factorial(int num)
{
    if (num == 0)
        return 1;
    return num * factorial(num - 1);
}

int main()
{
    int num;
    printf("\nEnter the number: ");
    scanf("%d", &num);

    // Factorials are undefined for negative integers
    if (num < 0)
    {
        printf("Factorials are undefined for negative integers");
    }

    // Call the function
    long long unsigned int fact = factorial(num);
    // Print the obtained factorial
    printf("The factorial of the given number is: %lld", fact);
    return 0;
}

/*

Time Complexity- O(num), where 'num' is the given number
Space Complexity- O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE I

Enter the number: 12
The factorial of the given number is: 479001600

*/
