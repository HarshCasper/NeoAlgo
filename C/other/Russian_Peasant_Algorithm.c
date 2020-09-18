/*
In this algorithm we keep halving one number and doubling the 2nd one.
While halving, if we get an odd number, we add the 2nd doubled number to the result.
This goes on until the halving makes the first reach 0.
It is also known as the Ancient Egyptian Multiplication, used by
scribes to do multiplication without using the multiplication table.
*/

#include <stdio.h>

int main() {
	int a, b;
	printf("Enter the first number: ");
	scanf("%d", &a);
	printf("\nEnter the second number: ");
	scanf("%d", &b);
	int ans = 0;
	while(b) {
		if (b%2) {
			ans += a;
		}
		a*=2;
		b/=2;
	}
	printf("\nThe product of the given number is %d\n", ans);
	return 0;
}

/*
Time Complexity: O(log2(max(no of digits in a, no of digits in b)))
OUTPUT
Enter the first number: 4
Enter the second number: 5
The product of the given number is 20
*/
