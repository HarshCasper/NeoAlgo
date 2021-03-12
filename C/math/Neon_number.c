/* C Program to check whether a number is Neon or not.
 A neon number is a number where the sum of digits of square of the number is equal to the number. 
 */

#include <stdio.h>
#include <math.h>
void neon(int n)
{
	int i, sum = 0, t = 1;
	t = pow(n, 2);
	while (t != 0)
	{
		sum = sum + (t % 10);
		t = t / 10;
	}
	if (sum == n)
	{
		printf("Neon number.\n");
	}
	else
	{
		printf("Not a neon number\n");
	}
}
int main()
{
	int n;
	printf("Enter a number ");
	scanf("%d", &n);
	neon(n);
}
/* Sample Input/output
Example 1-
Enter a number 9
Neon number.
Example 2-
Enter a number 144
Not a neon number

Space Complexity O(1)
Time Complexity  O(log(n))
*/
