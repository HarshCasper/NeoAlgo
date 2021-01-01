/*
Bulb Swither problem

There are n bulbs that are initially off. You first turn on all the bulbs, then you turn off every second bulb.
On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the ith round, you toggle every i bulb.
For the nth round, you only toggle the last bulb.

Return the number of bulbs that are on after n rounds.

Link to problem: https://leetcode.com/problems/bulb-switcher/
*/

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
