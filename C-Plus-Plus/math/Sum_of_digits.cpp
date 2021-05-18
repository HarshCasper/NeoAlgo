// C++ PROGRAM TO COMPUTE THE SUM OF DIGITS OF A NUMBER

#include <iostream>
using namespace std;

// Function to calculate the sum of digits
int sum_of_digits(int N)
{
    int sum = 0;
    while(N != 0)
    {
        // Adding the last digit of the number to the sum
        int rem = N % 10;
        sum += rem;
        // Removing the last digit
        N = N / 10;
    }
    return sum;
}

int main()
{
    int N;
    cout << "Enter any integer:";
    cin >> N;
    
    cout << "Sum of the digits of a number:" << sum_of_digits(N) << endl;
    return 0;
}

/*
Example 1:
Input : N = 453
Output: 12
Explanation: Sum of digits of number = (4+5+3) = 12

Example 2:
Input : N = 101
Output: 2
Explanation: Sum of digits of number = (1+0+1) = 2
*/
