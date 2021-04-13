/*
Seive of Eratosthenes is a famous algorithm to find prime numbers by marking all non-prime numbers.
This algorithm takes O(n * log(log n)) time complexity.
It does so by iteratively marking as composite (i.e., not prime) the multiples of each prime,
starting with the first prime number.
The multiples of a given prime are generated as a sequence of numbers starting from that prime,
with constant difference between them that is equal to that prime.
This is the sieve's key distinction from using trial division to sequentially test each candidate number for divisibility by each prime.
Once all the multiples of each discovered prime have been marked as composites, the remaining unmarked numbers are primes.
*/

#include <bits/stdc++.h>
using namespace std;

void PrimeSieve(int n)
{
    int Prime[100] = {0};
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[i] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    PrimeSeive(n);
    return 0;
}

/*
=============
Test cases:-

1)Input : 30
1)Output: 2 3 5 7 11 13 17 19 23 29

2)Input : 50
2)Output: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47

=============
Time complexity: O(n * log(log n))