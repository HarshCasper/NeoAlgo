// C++ program to check if a number is a palindrome or not
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num, temp, rev = 0;
    cout << "Enter the number:  ";
    cin >> num;
    temp = num;
    /*To check if a number is palindrome, we reverse the number
    and then compare it with the given number */
    while (temp)
    {
        int rem = temp % 10;
        rev = rev * 10 + rem;
        temp = temp / 10;
    }
    if (rev == num)
    {
        cout << "The given number is a palindrome number";
    }
    else
    {
        cout << "The given number is not a palindrome number";
    }
    return 0;
}

/*
Time Complexity: O(log(num)), where 'num' is the given number
Space Complexity: O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

Enter the number:  14321
The given number is not a palindrome number

SAMPLE 2

Enter the number:  43234
The given number is a palindrome number

*/
