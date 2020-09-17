/*
Euler's totient function, also known as phi-function ϕ(n), counts the
numberof integersbetween 1 and n inclusive, which are coprime to n.
*/

#include <stdio.h>

int main(){
	int n;
	printf("Enter an integer: ");
	scanf("%d", &n);
	int phi[n+1];
	for (int i = 0; i <= n; ++i) {
		phi[i] = i;
	}
	for (int i = 2; i <= n; ++i) {
		if (phi[i] == i) {
			for (int j = i; j<=n; j+=i) {
				phi[j] = phi[j] - phi[j]/i;
			}
		}
	}
	printf("The euler totient function for %d is: %d",n,phi[n]);
	return 0;
}

/*
Time Complexity: O(N loglogN)

OUTPUT
Enter an integer: 10
The euler totient function for 10 is: 4


-----
(1,3,7,9) are coprime to 10
*/
