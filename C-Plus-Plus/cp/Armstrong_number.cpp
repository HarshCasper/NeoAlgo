/*
Description :
           Armstrong number is a number that is equal to the sum of cubes of its digits.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // original number
    int num;
    cout << "Enter the number : " << endl;
    cin >> num;

    // storing the original value
    int duplicate = num;

    while (num > 0)
    {
        int last_digi = n % 10;
        sum += pow(last_digi, 3);
        n = n / 10;
    }
    if (sum == duplicate)
    {
        cout << "It is an Armstrong Number  " << endl;
    }
    else
    {
        cout << "It is not an Armstrong Number  " << endl;
    }
    return 0;
}

/*
Time complexity : O(n)
Space complexity : O(n)
*/

/*
Test Cases :
 Input :
 Enter the number : 
 153

 Output :
 It is an Armstrong Number 
*/
