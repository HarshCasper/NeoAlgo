'''
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to 
sell that stock.Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Note: You may not engage in multiple transactions at the same time(i.e., you must sell the stock before you buy again).
'''
def best_transaction(arr):
    #if the arr is smaller than 2 max profit is 0 
    if len(arr) < 2:
        return 0

    size = len(arr)

    hold = [0] * size   
    unhold = [0] * size

    hold[0] = 0 - arr[0]
    unhold[0] = 0
    hold[1] = max(-arr[0], -arr[1])  #find when is maximum profit 
    unhold[1] = max(arr[1] - arr[0], 0)  #find when is the minimum  profit  

    for i in range(2, size):
        #checking the which time buy and sell in every element(price) in array  
        hold[i] = max(hold[i - 1], unhold[i - 2] - arr[i])
        unhold[i] = max(hold[i - 1] + arr[i], unhold[i - 1])
    #result
    return unhold[-1]


if __name__ == "__main__":
    arr = list(map(int,input("Enter the prices: ").split()))
    print("Maximum Profit is ",best_transaction(arr))

'''
Time complexcity : O(n)
Space Complexcity : O(n)

Input:
Enter the prices: 7 1 5 3 6 4

Output:
Maximum Profit is  5

'''
