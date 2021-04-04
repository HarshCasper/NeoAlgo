// Unique BSTs using DP
// Given n, how many structurally unique BST's that store values 1 ... n?

#include <stdio.h>

int max(int num1, int num2) {
	return (num1 > num2) ? num1 : num2;
}

int uniqueBST(int n) {
	int count[n + 1];
	for (int i = 0; i < n + 1; i++)
		count[i] = 0;
	// for each 'i' number of nodes
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			// No. of trees if j is a root
			count[i] += max(count[j], 1) * max(count[i - j - 1], 1);
		}
	}
	return count[n];
}

int main() {
	int n;
	printf("Enter the number: \n");
	scanf("%d", &n);
	int num = uniqueBST(n);
	printf("Number of Unique BSTs %d is: \n", num);
	return 0;
}

/*
input:
Enter value:3
output:
Number of Unique BSTs 5
Time complexity : O(n^2)
*/
