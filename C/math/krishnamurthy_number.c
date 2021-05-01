/* C program to check if a number is a Krishnamurthy number or not.
Krishnamurthy Number is a number whose sum of the factorial of digits
is equal to the number itself. The Number is named after Jiddu Krishnamurti */

#include <stdio.h>
#include <stdbool.h>


// Helper function to return the factorial of a number
long int factorial(int num)
{
    if (num == 1 || num == 0)
        return 1;
    return num * factorial(num - 1);
}

bool check_krishnamurthy_number(int num)
{
    // Store the given number in a temporary variable.
    int temp = num;
    long int sum = 0;
    // Find the sum of the factorial of the individual digits.
    while (temp > 0)
    {
        int rem = temp % 10;
        sum = sum + factorial(rem);
        temp = temp / 10;
    }
    if (sum == num)
        return true;
    else
        return false;
}

int main()
{
    int num;
    printf("Enter the number: ");
    scanf("%d", &num);
    bool res = check_krishnamurthy_number(num);
    if (res)
    {
        printf("The given number %d is a Krishnamurthy Number. ", num);
    }
    else
    {
        printf("The given number %d is not a Krishnamurthy Number.", num);
    }
}

/*
Time Complexity - O(n * log(n)), where 'n' is the given number
Space Complexity - O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE I

Enter the number: 145
The given number 145 is a Krishnamurthy Number. 

SAMPLE II

Enter the number: 1234
The given number 1234 is not a Krishnamurthy Number.
*/
