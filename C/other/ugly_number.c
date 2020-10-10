/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5.
The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15 ..…
shows the first 11 ugly numbers.
Your Task is to find nth Ugly number
Time Complexity:O(n)
Space Complexity: O(n)
Example 1:
Sample Input:
10
Sample Output:
12
Example 2:
Sample Input:
4
Sample Output:
4
Language: C
*/

#include <stdio.h>

//return the minimum among x and y
#define MIN(X, Y)(((X) < (Y)) ? (X) : (Y))

//this function return nth ugly number
int get_ugly_no(int n)
{
	int ugly[n], i2 = 0, i3 = 0, i5 = 0;
	int nxt_mul_2 = 2, nxt_mul_3 = 3;
	int nxt_mul_5 = 5, nxt_ugly = 1;
	ugly[0] = 1;
	for (int i = 1; i < n; i++)
	{
		nxt_ugly = MIN(nxt_mul_2, MIN(nxt_mul_3, nxt_mul_5));
		ugly[i] = nxt_ugly;
		if (nxt_ugly == nxt_mul_2)
		{
			i2++;
			nxt_mul_2 = ugly[i2] * 2;
		}

		if (nxt_ugly == nxt_mul_3)
		{
			i3++;
			nxt_mul_3 = ugly[i3] * 3;
		}

		if (nxt_ugly == nxt_mul_5)
		{
			i5++;
			nxt_mul_5 = ugly[i5] * 5;
		}
	}

	return nxt_ugly;
}

int main()
{
	//find the nth ugly number
	int n;
	scanf("%d", &n);
	//calls the get_ugly_no function
	printf("%d", get_ugly_no(n));
	return 0;
}
