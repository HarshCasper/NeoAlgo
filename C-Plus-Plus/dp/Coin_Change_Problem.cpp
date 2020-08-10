/*Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum number of
coins to make the change?
Examples:

Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents 

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents */

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, coin[100], tot, i, j;
	cout << "Enter number of coins" << endl;
	cin >> n;
	cout << "Enter denominations of coins" << endl;
	for(i = 0; i < n; i++){
		cin >> coin[i];
	}
	cout << "Enter value" << endl;
	cin >> tot;
	int dp[tot + 1] = {0};
	for(i = 1; i <= tot; i++)
	{
		int num = INT_MAX;
		for(j = 0; j < n; j++)
		{
			if(coin[j] <= i)
			num = min(num, dp[i - coin[j]] + 1);    /*bottom-down approach*/
		}
		dp[i] = num;
	}
	cout << dp[tot];
	return 0;
}
