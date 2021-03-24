'''
Purpose : 
In a trading system a product is bought in the morning and sold out on the same day. 
If a person can make only 2 transactions a day with a condition that second transaction is followed only after first then find the maximum profit the person could get.

Input formate : 
Line1 : Number of test cases
Line2 : Length of the prices array
Line3 : prices array separated with a space

Output formate : 
The maximum profit

Method :
Dynamic programming 

Intuition : 
Storing the maximum possible profit of every subarray in a table named profit 
Finally returning the profit[n-1]


Argument: Array 
return : int 

'''


def maxProfit(price, n):

	# Create profit array and initialize it as 0
	profit = [0]*n

	''' Get the maximum profit with only one transaction allowed.
	After this loop,profit[i] contains maximum profit from price[i..n-1] using at most one trans.
	max_price = price[n-1] '''
	
	for i in range(n-2, 0, -1):

		if price[i] > max_price:
			max_price = price[i]

		''' we can get profit[i] by taking maximum of:
		a) previous maximum,i.e., profit[i+1]
		b) profit by buying at price[i] and selling at max_price'''
		
		profit[i] = max(profit[i+1], max_price - price[i])

	'''Get the maximum profit with two transactions allowed
	After this loop, profit[n-1] contains the result'''
	
	min_price = price[0]

	for i in range(1, n):

		if price[i] < min_price:
			min_price = price[i]

		'''Maximum profit is maximum of:
		a) previous maximum,i.e., profit[i-1]
		b) (Buy, Sell) at (min_price, A[i]) and 
		profit of other trans.stored in profit[i]'''
		
		profit[i] = max(profit[i-1], profit[i]+(price[i]-min_price))

	result = profit[n-1]

	return result

# Driver function
def main():
    for _ in range(int(input())):
        price = []
        length=int(input())
        price=list(map(int,input().split()))
        print ("Maximum profit is", maxProfit(price,length),"\n")

	
if __name__=="__main__":
    main()
	
	
	
'''
Case : 1
Sample Input :
2
6
[90, 80, 70, 60, 50]
6
[10, 22, 5, 75, 65, 80]
Sample Output :
0
87
Reason :
1)No possible earn only loss if transactions takes place
2)Buy at 10, sell at 22, Buy at 5 and sell at 80. [12+75]

Time complexity : O(N)
Space Complexity : O(N)
'''
