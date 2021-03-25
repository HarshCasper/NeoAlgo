/**
 * Given a number and you need to check if a number is T-prime or not. 
 * A number is called T-prime if it has exactly three factors.
 * Input:
 * First line of input contains a number of integer data type.
 * Output:
 * A single line telling whether a number is T-prime or not.
 *
*/

#include <bits/stdc++.h>

using namespace std;

int Check_T_Prime(int n)
{
    if (n <= 3)
    {
        return 0;
    }
    else
    {
        long long int square_root = sqrt(n);
        int perfect_square_prime = 0, i;

        //to check if number is perfect square or not.
        if (square_root * square_root == n)
        {
            for (i = 2; i <= sqrt(square_root); i++)
            {
                
                /* If the square root of the 
                user input number (num) is prime then it's T-prime otherwise it's not.
                Because for T-prime number should have 3 factors(one the number itself)
                and other 2 from square root as it prime number.  
                */
                if (square_root % i == 0)
                {
                    perfect_square_prime = 1;
                    break;
                }
            }
            if (perfect_square_prime == 0)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
}

int main()
{

    long long int num;
    cout << "Enter the number: " << endl;
    cin >> num;

    int result = Check_T_Prime(num);

    if (result == 1)
        cout << num << " is T-prime. " << endl;
    else
        cout << num << " is not T-prime. " << endl;
}

/*
 * Example:
 * Input:
 * 3
 * Output:
 * 3 is not T-prime.
 * 
 * Input:
 * 49
 * Output:
 * 49 is T-prime;
*/

/*
*Time complexity : O(sqrt(n)) 
*Space complexity : O(1)
*/
