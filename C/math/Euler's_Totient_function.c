/*
Euler's totient function, also known as phi-function ϕ(n), counts the
numberof integers between 1 and n inclusive, which are coprime to n.
*/
#include <stdio.h>

void Euler_Totient(int, int[]);
int main()
{
	int n, phi[100];
	printf("Enter an integer: ");
	scanf("%d", &n);
	Euler_Totient(n, phi);
	printf("\nThe euler totient function for all integers from 1 to %d is:\n", n);
	for (int i = 1; i <= n; ++i)
	{
		printf("%d: %d\n", i, phi[i]);
	}

	return 0;
}

// Function whuch counts number of integers between 1 to n which are co-prime to n
void Euler_Totient(int n, int phi[])
{
	int temp = n;
	//This gives euler totient function for N
	// Time Complexity: O(N*root(N))
	int ans = n;
	for (int i = 2; i <= n; ++i)
	{
		if (n % i == 0)
		{
			ans = ans - ans / i;
			while (n % i == 0)
				n /= i;
		}
	}

	if (n > 1)
	{
		ans = ans - ans / n;
	}

	n = temp;
	printf("\nThe euler totient function for %d is: %d", n, ans);

	//This gives euler totient function from 1 to N
	// Time Complexity: O(N loglogN) - same as Sieve of Eratosthenes
	for (int i = 0; i <= n; ++i)
	{
		phi[i] = i;
	}

	for (int i = 2; i <= n; ++i)
	{
		if (phi[i] == i)
		{
			for (int j = i; j <= n; j += i)
			{
				phi[j] = phi[j] - phi[j] / i;
			}
		}
	}
}

/*
Time Complexity: O(N loglogN)

OUTPUT
Enter an integer: 10
The euler totient function for 10 is: 4
The euler totient function for all integers from 1 to 10 is:
1: 1
2: 1
3: 2
4: 2
5: 4
6: 2
7: 6
8: 4
9: 6
10: 4

-----
(1,3,7,9) are coprime to 10
*/

