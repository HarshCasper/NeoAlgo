/*
Description : 
    Given two integers num1 and num2. Find the sum of 
    two numbers without using arithmetic operators.
*/

#include <bits/stdc++.h>
using namespace std;

// function to find the sum
int get_sum(int num1, int num2)
{
    int carry;
    while (num2 != 0)
    {
        carry = num1 & num2;
        num1 = num1 ^ num2;
        num2 = carry << 1;
    }
    return num1;
}

int main()
{
    int num1, num2;
    cout << "Enter the first number : " << endl;
    cin >> num1;
    cout << "Enter the second number : " << endl;
    cin >> num2;

    cout << "Addition is : " << endl;
    cout << get_sum(num1, num2);
    return 0;
}

/*
Time complexity : O(max bits of(num1 and num2))
Space complexity :O(1)
*/

/*
Test Case :
Input :
    Enter the first number :
    5
    Enter the second number :
    2

Output
    Addition is :
    7
*/