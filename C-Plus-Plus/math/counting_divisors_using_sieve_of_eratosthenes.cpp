/*
Given a positive integer, count the number of its divisors.

A divisor is a number that divides another number either completely or with a remainder.

Approach used: Extract the prime factors of the given number along with their
respective contributing powers using the sieve of Eratosthenes and then calculate
the divisors by applying basic permutation and combination on these powers.

Explanation : Suppose the prime factorization of the number is a^x1+b^x2+c^x3...and so
on, where a,b,c,etc are its prime factors and x1,x2,x3 their respective powers.
Then, the divisor count is equal to (x1+1)*(x2+1)*(x3+1)....
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> prime_sieve(int P[], int n)
{
    P[0] = P[1] = 0;
    P[2] = 1;
    // Mark all odd numbers as prime as even numbers can't be prime.
    for (int i = 3; i < n; i += 2)
    {
        P[i] = 1;
    }
    // Sieve
    for (int i = 3; i < n; i += 2)
    {
        // If the current number is marked 1,it is prime.
        // Hence,its multiples can't be prime.
        if (P[i] == 1)
        {
            // Marking multiples of i, not prime.
            for (int j = i * i; j < n; j += 2 * i)
            {
                P[j] = 0;
            }
        }
    }
    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i < n; i += 2)
    {
        if (P[i] == 1)
        {
            primes.push_back(i);
        }
    }
    return primes;
}

int count_of_divisors(vector<int> primes, int num)
{
    int i = 0, final_ans = 1;
    int flag = primes[0];
    while (flag * flag <= num)
    {
        if (num % flag == 0)
        {
            // Counting powers of prime factors
            int count = 0;
            while (num % flag == 0)
            {
                count++;
                num = num / flag;
            }
            final_ans = final_ans * (count + 1);
        }
        i++;
        flag = primes[i];
    }
    // If the number is not equal to 1,then it itself is a prime.
    if (num != 1)
    {
        final_ans = final_ans * 2;
    }
    return final_ans;
}

int main()
{
    // Precomputational step
    // Use a helper array to extract prime numbers into a vector using prime sieve.
    int helper_arr[10000] = { 0 };
    vector<int> primes = prime_sieve(helper_arr, 10000);

    int num;
    cout << "Enter the number whose divisor count is to be found : " << endl;
    cin >> num;
    cout << "Count of divisors : " << endl;
    cout << count_of_divisors(primes, num) << endl;

    return 0;
}


/*Example

Sample input: Enter the number whose divisor count is to be found : 60
Sample Output: Count of divisors : 12

Explanation: 60=2^2+3^1+5^1
             Divisor count=(2+1)*(1+1)*(1+1)=12

Time complexity : O(log N)(If we ignore the precomputation time complexity of O(N log(log N))
Space complexity : O(N) (Due to sieve preparation)
*/
