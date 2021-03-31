/*
Given a Number. Find it's Sum of Divisors.

The Number can be big such as 10^6 to 10^9
So, If we do this in O(N) we will get Time Limit Exceeded [TLE]
Better Approach is run a loop till sqrt(Number)
Example square root of 10^9 is 31622 (approx), so iteration optimized a lot.
*/

#include <bits/stdc++.h>
using namespace std;

// this get_sum_of_divisors will count the sum of divisors of the number
long long int get_sum_of_divisors(int Number)
{
    /* Sum of Divisors may not fit in int range
    so better take long long int */
    long long int sum_of_divisors = 0;
    int limit = (int) sqrt(Number);
    for(int i = 1; i < limit; i++)
    {
        if(Number % i == 0)
        {
            /* Here i is a divisor of that number
            ( Number / i ) is also a divisor
            */
            sum_of_divisors += i;
            sum_of_divisors += (Number / i);
        }
    }

    if(Number % limit == 0)
    {
        if(limit * limit == Number)
        {
            //means perfect square number
            sum_of_divisors += limit;
        }
        else
        {
            sum_of_divisors += limit;
            sum_of_divisors += (Number / limit);
        }
    }
    return sum_of_divisors;
}

int main()
{
    cout << "Enter the number : \n";
    int Number;
    cin >> Number;
    long long int sum_of_divisors = get_sum_of_divisors(Number);
    cout << "Sum of Divisors of this Number is : ";
    cout << sum_of_divisors << endl;
}

/*
Standard Input and Output

Enter the number :
1000000000
Sum of Divisors of this Number is : 2497558338

Enter the number :
456723
Sum of Divisors of this Number is : 681408

Time Complexity : O( sqrt(N) )
Space Complexity : O( 1 )

*/
