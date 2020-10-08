// C++ Program to calculate last digit number of fibonacci series

#include <iostream>
using namespace std;

int get_fibonacci_last_digit(long long n)
{
    int first = 0; // first integer of fibonacci series
    int second = 1; // second integer of fibonacci series

    int result;

    for (int i = 2; i <= n; i++)
    {
        result = (first + second) % 10; // storing the remainder in result instead of whole fibonacci series
        first = second;
        second = result;
    }

    return result;
}

int main()
{
    int number;
    cin >> number;
    int result = get_fibonacci_last_digit(number);
    cout << result << '\n';

    return 0;
}

/*
Sample I/O:
Input:
200
Output:
5

Time Complexity: O(n)
Space Complexity : O(n)

*/