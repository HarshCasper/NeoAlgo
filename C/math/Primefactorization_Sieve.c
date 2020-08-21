#include <stdio.h>
#include <math.h>

void primeFactors(int number) /* Program to print all prime factors of a number using prime sieve*/
{
	int primes[number + 1];
	int i, j;
	for (i = 2; i <= number; i++)
	{
		primes[i] = i;
	}
	i = 2;
	while ((i * i) <= number)
	{
		if (primes[i] != 0)
		{
			for (j = 2; j < number; j++)
			{
				if (primes[i] * j > number)
					break;
				else
					primes[primes[i] * j] = 0; /* marking the elements as 0*/
			}
		}
		i++;
	}
	while (number % 2 == 0) /* check if the input number is even*/
	{
		printf("%d ", 2);
		number = number / 2;
	}
	for (int i = 3; i <= sqrt(number); i = i + 2) /*the number must be odd*/
	{
		while (number % i == 0)
		{
			printf("%d ", i);
			number = number / i;
		}
	}
	if (number > 2) /* a condition to check if number is a prime number greater than 2*/
		printf("%d ", number);
}

int main() /* driver function*/
{
	int number;
	printf("Enter a number to find its prime factors\n");
	scanf("%d", & number);
	printf("The prime factors of the number %d are :", number);
	primeFactors(number);
	return 0;
}

/* THIS CODE IS CONTRIBUTED BY KASHIKA JAIN
SAMPLE INPUT: 39
SAMPLE OUTPUT: The prime factors of the number 39 are :3 13
Time complexity: O(log n)
Space complexity: O(n)
*/
