/*
Sum of all the possible divisors of a natural number

You will be given a natural number and your task is
to find all possible divisors of the given number and
return their sum as the output.
*/

#include <bits/stdc++.h>

using namespace std;

//function to sum up all the possible divisors of a natural number
int divisorSum(int number)
{
    int ans = 0;
    for(int pass = 2; pass <= sqrt(number); pass++)
    {
        //for i is a divisor then remainder must be 0
        if(number % pass == 0)
        {
            //if the divisors are same we count only one of 
            //them in sum
            if(pass == (number / pass))
            {
                ans = ans + pass;
            }
            //otherwise we count both for sum
            else
            {
                ans = ans + (pass + (number / pass));
            }
        }
    }
    return (ans + 1);
}

//driver code
int main()
{
    int number;
    cout << "Enter a natural number: ";
    cin >> number;
    cout << "Sum of all possible divisors of " << number << " is: " << divisorSum(number);
    return 0;
}

/*
EXAMPLE:-

Example 1:-
Input--
Enter a natural number: 40
Output--
Sum of all possible divisors of 40 is: 90

Example 2:-
Input--
Enter a natural number: 1
Output--
Sum of all possible divisors of 1 is: 1

TIME COMPLEXITY--> O(sqrt(N))
SPACE COMPLEXITY--> O(1)
*/
