/*
Given a Number. Find it's Number of Divisors.

The Number can be big such as 10^6 to 10^9
So, If we do this in O(N) we will get Time Limit Exceeded [TLE]
Better Approach is run a loop till sqrt(Number)
Example square root of 10^9 is 31622 (approx), so iteration optimized a lot.
*/

#include <bits/stdc++.h>
using namespace std;

// this get_number_of_divisors will count the number of divisors of the number
int get_number_of_divisors(int Number)
{
    int number_of_divisors = 0;
    int limit = (int) sqrt(Number);
    for(int i = 1; i < limit; i++)
    {
        if(Number % i == 0)
        {
            /* Here i is a divisor of that number
            ( Number / i ) is also a divisor
            */
            number_of_divisors += 2;
        }
    }

    if(Number % limit == 0)
    {
        if(limit * limit == Number)
        {
            //means perfect square number
            number_of_divisors++;
        }
        else
        {
            number_of_divisors += 2;
        }
    }
    return number_of_divisors;
}

int main()
{
    cout << "Enter the number : \n";
    int Number;
    cin >> Number;
    int number_of_divisors = get_number_of_divisors(Number);
    cout << "Number of Divisors of this Number is : ";
    cout << number_of_divisors << endl;
}

/*
Standard Input and Output

Enter the number :
1000000000
Number of Divisors of this Number is : 100

Enter the number :
4567323
Number of Divisors of this Number is : 16

Time Complexity : O( sqrt(N) )
Space Complexity : O( 1 )

*/
