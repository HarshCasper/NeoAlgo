/*
A number is said to be a Harshad Number if it is divisible by the sum of its digits.
For example: The number 84 is divisible by the sum (12) of its digits (8, 4).
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check whether the Number is Harshad Number or Not.

bool isHarshad(int number)
{
    int sum = 0;
    int copy = number;
    while (number > 0)
    {
        int digit = number % 10;
        number = number / 10;
        sum += digit;
    }
    return copy % sum == 0;
}

int main()
{
    cout << "Enter a Number:" << endl;
    int input;
    cin >> input;
    if (isHarshad(input))
        cout << input << " is a Harshad Number." << endl;
    else
        cout << input << " is not a Harshad Number." << endl;
    return 0;
}

/*
Time Complexity: O(log(n))
Space Complexity: O(1)

Sample Input/Output
Enter a Number:
84
84 is a Harshad Number.

Enter a Number:
16
16 is not a Harshad Number.

*/
