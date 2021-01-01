// Bulb Swither problem
// link to problem: https://leetcode.com/problems/bulb-switcher/

#include<stdio.h>

int bulbSwitch(int n) {
	int bulb = 1, ans = 0;
	//A bulb is ON if it is toggled odd times
	while (bulb * bulb <= n) {
		ans++;
		bulb++;
	}
	return ans;
}

int main() {
	int n;
	printf("Enter the no. of bulbs: \n");
	scanf("%d", &n);
	printf("%d \n", bulbSwitch(n));
	return 0;
}
/*
 Sample Input:
 Enter the no. of bulbs: 
 4
 Output:
 2 
 Time complexity: O(n)
 Space complexity: O(1)
 */
