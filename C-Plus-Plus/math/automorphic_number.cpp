/**
 * Given a number and you need to check if a number is Automorphic or not. 
 * A number is called Automorphic if the square of the number ends
 * with the number itself.
 * Input:
 * First line of input contains a number of integer data type.
 * Output:
 * A single line telling whether a number is Automorphic or not.
 *
*/

#include <bits/stdc++.h>

using namespace std;

int Check_Automorphic(int n)
{
    int square, temp, remainder, no_digits = 0;
    temp = n;
    square = n * n;
    int flag = 10;

    while (n != 0)
    {
        n = n / 10;
        no_digits++;
    }

    flag = pow(10, no_digits);
    remainder = square % flag;

    if (remainder == temp)
        return 1;
    else
        return 0;
}

int main()
{

    long long int num;
    cout << "Enter the number: " << endl;
    cin >> num;

    int result = Check_Automorphic(num);

    if (result == 1)
        cout << num << " is a Automorphic number. " << endl;

    else
        cout << num << " is not a Automorphic number. " << endl;
}

/*
 * Example:
 * Input:
 * 3
 * Output:
 * 3 is not a Automorphic number.
 * 
 * Input:
 * 25
 * Output:
 * 25 is a Automorphic number.
*/
/*
*Time complexity : O(n) 
*Space complexity : O(1)
*/
