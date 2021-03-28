/*
Given a number. find it's smallest prime factor.
we have to get the smallest factor of that number and
the smallest factor has to be a prime number.
*/

#include <bits/stdc++.h>
using namespace std;

bool check_prime(int number)
{
    /* check whether number is prime or not */
    for(int i = 3; i * i <= number; i += 2)
    {
        if(number % i == 0)
            return false;
    }
    return true;
}

int get_smallest_prime_factor(int number)
{
    int get_factor = 0;
    /*
    loop runs till sqrt( number )
    for not getting precision errors
    use i * i <= number
    */
    for(int i = 3 ; i * i <= number; i += 2)
    {
        if(number % i == 0)
        {
            get_factor = 1;
            int prime = check_prime(i);
            if(prime)
            {
                /* that means the number is smallest prime factor */
                return i;
            }
        }
    }
    if(!get_factor)
    {
        /*
        that means the number itself it's smallest prime factor.
        Ex : 17
        so we can return the number.
        */
        return number;
    }
}

int main()
{
    cout << "Enter the number : \n";
    int number;
    cin >> number;
    /*
    if the number is even, we can say that the smallest prime factor
    is 2 for any even number.
    because 2 is prime and it's a factor of
    every even number.
    */
    if(! (number & 1) )
    {
        cout << "Smallest prime factor for this number is : " << "2" << endl;
    }
    else if(number & 1)
    {
        int smallest_prime_factor = get_smallest_prime_factor(number);
        cout << "Smallest prime factor for this number is : " << endl;
        cout << smallest_prime_factor << endl;
    }
}

/*
Standard Input and Output

1. Even number
Enter the number :
435346
Smallest prime factor for this number is : 2

2. Odd Number
Enter the number :
35345
Smallest prime factor for this number is :
5

3. Odd Prime Number :
Enter the number :
23
Smallest prime factor for this number is :
23

Time Complexity : O(sqrt (N) )
Space Complexity : O( 1 )

*/
