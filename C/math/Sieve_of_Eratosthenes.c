/*Sieve_of_eratosthenes
  Sieve of Eratosthenes is an ancient algorithm for finding all prime numbers up to any given limit.
  It does so by iteratively marking as composite (i.e., not prime) the multiples of each prime, starting with
  the first prime number, 2. The multiples of a given prime are generated as a sequence of numbers starting from that prime,
  with constant difference between them that is equal to that prime.*/

//Header files
#include <stdio.h>
#include <stdlib.h>

void Sieve_of_eratosthenes(int n)
{
    // Creating an array for storing prime factors.
    // and if the i is not prime, mark it as 0 else 1
    int prime[n + 1];

    // Initialising all elements as 1
    for(int i = 2; i <= n; i++)
        prime[i] = 1;

    for(int i = 2; i * i <= n; i++)
    {
        // If prime[i] is marked 1, then it is a prime.
        if(prime[i] == 1)
        {
            // Marking all multiples of i as 0
            for(int j = i * i; j <= n; j += i)
                prime[j] = 0;
        }
    }

    // Printing all the prime numbers
    for(int i = 2; i <= n; i++)
       if(prime[i])
       {
           printf("%d ", i);
       }
}

// Driver Function
int main()
{
    int num;
    printf("Enter the number: \n");
    scanf("%d", &num);
    printf("The prime numbers smaller than or equal to %d are: \n", num);
    Sieve_of_eratosthenes(num);
    return 0;
}

/*Sample Input:
  Enter the number: 10
  
  Sample Outut:
  The prime numbers smaller than or equal to 10 are: 
  2 3 5 7 
*/
