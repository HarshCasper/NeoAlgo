/*
A number is said to be Magic Number, when the recursive sum of the digits is 1.
For example 1729
    1+7+2+9=19
    1+9=10
    1+0=1
So, it comes out be 1. Hence, 1729 is a Magic Number.
*/

#include <bits/stdc++.h>
using namespace std;

// Function for finding Sum of digits of a number.
int sum_of_digits(int num)
{
    int sum = 0;
    while (num > 0) {
        int rem = num % 10;
        sum = sum + rem;
        num = num / 10;
    }
    return sum;
}

// Function to check whether the Number is Magic Number or Not.
bool is_magic(int num)
{
    while (num > 9) {
        num = sum_of_digits(num);
    }
    return num == 1;
}

int main()
{
    int num;
    cout << "Enter the Number to check whether it is Magic Number or Not:" << endl;
    cin >> num;
    if (is_magic(num))
        cout << num << " is Magic Number." << endl;
    else
        cout << num << " is Not Magic Number." << endl;
    return 0;
}

/*
Sample I/0

Input:
Enter the Number to check whether it is Magic Number or Not:
1234
Output:
1234 is Magic Number.

*/
