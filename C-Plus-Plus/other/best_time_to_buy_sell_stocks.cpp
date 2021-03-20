/* C++ program to solve best time to buy and sell stocks problem. An array of integers are given which
represent the prices of stock. prices[i] is the price of the ith stock. We need to find the maximum profit 
which can be achieved if we can buy stocks on any particular day and sell on any day in future. */

#include<bits/stdc++.h>
using namespace std;

int maxProfit(int price[] , int n ){
	// if number of prices is 0 then return 0
	if(n == 0){
		return 0;
	}
	else{
		// initialise minimum price
		int minPrice = price[0];
		int maxProfit = 0;
		// traverse the array to find minPrice and maxProfit
		for(int i = 1 ; i < n ; i++){
			if(price[i] < minPrice)
				minPrice = price[i];
			if(price[i] - minPrice > maxProfit)
				maxProfit = price[i] - minPrice;
		}
		// returns the maximum profit achieved
		return maxProfit;
	}
}

int main(){
	int n;
	// input for number of stocks
	cin >> n;
	int price[n];
	for(int i = 0 ; i < n ; i++){
		// input for prices of stocks
		cin >> price[i];
	}
	cout << maxProfit(price , n);
	return 0;
}

/*

Input-

n = 5
price[n] = {1,4,7,3,2}

Output-

6

Explanation-
Buy stock at index 0 when price is 1 and sell at index
2 when price is 7

Time Complexity- O(n)
Space Complexity- O(1)

*/
