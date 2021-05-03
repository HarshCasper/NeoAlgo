/*
Given a number.
Check whether the number has odd divisor or not except 1.
For example, the divisors of 20 is 1,2,4,5,10,20.
Since, 5 is odd, 20 has odd divisor in it's divisor list.
*/

#include <bits/stdc++.h>
using namespace std;

// this function will check whether the number has odd divisor or not except 1.
bool get_check_number_has_odd_divisor(int number)
{
    /* while a number is even, it will divided by 2.
    and if the number becomes odd, the loop will break.
    */
    while(number % 2 == 0)
    {
        number = number / 2;

    }
    /* here if the number is greater than 1, then input number has a odd divisor
    in it's divisor list.
    But, if the number is 1, then input number has not any odd divisor
    in it's divisor list.
    */
    if(number > 1)
    {
        return true;
    }
    else if(number == 1)
    {
        return false;
    }
}

int main()
{
    cout << "Enter the number : ";
    int number;
    cin >> number;
    bool check_number_has_odd_divisor = get_check_number_has_odd_divisor(number);

    if(check_number_has_odd_divisor)
    {
        cout << "Yes. The number has odd divisor in it's divisor \n";
    }
    else
    {
        cout << "No. The number has not any odd divisor in it's divisor \n";

    }
}

/*
Standard Input and Output

Enter the number : 64
No. The number has not any odd divisor in it's divisor

Enter the number : 456
Yes. The number has odd divisor in it's divisor

Time Complexity : O( 1 )
Space Complexity : O( 1 )

*/
