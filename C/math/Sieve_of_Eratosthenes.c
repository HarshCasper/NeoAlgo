/*Sieve_of_eratosthenes
  Sieve of Eratosthenes is an ancient algorithm for finding all prime numbers up to any given limit.
  It does so by iteratively marking as composite (i.e., not prime) the multiples of each prime, starting with
  the first prime number, 2. The multiples of a given prime are generated as a sequence of numbers starting from that prime,
  with constant difference between them that is equal to that prime.*/

//Header files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Sieve_of_eratosthenes(int n)
{
    // Creating an array for storing prime factors.
    // and if the i is not prime, mark it as 0 else 1
    int prime[n + 1];

    // Initialising all elements as 1
    for (int i = 2; i <= n; i++)
        prime[i] = 1;

    for (int i = 2; i * i <= n; i++)
    {
        // If prime[i] is marked 1, then it is a prime.
        if (prime[i] == 1) 
        {
            // Marking all multiples of i as 0
            for (int j = i * i; j <= n; j += i)
                prime[j] = 0;
        }
    }

    // Printing all the prime numbers
    for (int i = 2; i <= n; i++)
        if (prime[i])
        {
            printf("%d ", i);
        }
}
/**
 * Optimized version of Sieve of Eratosthenes using Dynamic Memory Allocation and using Boolean.
 */
void sieve(int N, bool * isprime) 
{
    isprime[0] = true;
    isprime[1] = true;
  
    // eliminating multiples of i 
    for (int i = 2; i * i <= N; ++i)
    {
        if (!isprime[i]) 
        {
            for (int j = i * i; j <= N; j = j + i) 
            {
                isprime[j] = true;
            }
        }
    }
    // Printing all the prime numbers
    for (int i = 1; i <= N; i++) 
    {
        if (!isprime[i]) 
        {
            printf("%d ", i);
        }
    }
    printf("\n ");
}

// Driver Function
int main() {
    int num;
    printf("Enter the number: \n");
    scanf("%d", & num);
    printf("The prime numbers smaller than or equal to %d are: \n", num);
    Sieve_of_eratosthenes(num);

    //Implementation of Optimized version of Sieve of Eratosthenes
    printf("\n Using optimized version of code: \n");
    bool * isprime = (bool * ) malloc(num * sizeof(bool));
    sieve(num, isprime);
    free(isprime);
    return 0;
}

/*Sample Input:
  Enter the number: 10
  
  Sample Outut:
  The prime numbers smaller than or equal to 10 are: 
  2 3 5 7 
  Using optimized version of code:
  2 3 5 7 
*/
