'''
The Knapsack Problem is a pretty famous DSA Problem. It goes as follows:
Given a set of items, each with a weight and a profit margin, determine the amount (weight)
of each item to include in a collection so that the total weight is less than
or equal to a given limit and the total profit is as large as possible. The items can be
further divided into parts (Example - Fruits/Vegetables).

The following is the solution to the Knapsack Problem in Python.
'''

def Knapsack(profits, weights, Total_Weight_Limit):
    profit_weight_ratio = []
    profits_gained = []
    weight_added = []
    # Finding p/w ratio of each item
    for i in range(len(profits)):
        profit_weight_ratio.append(profits[i]/weights[i])
    # Adding items to the Knapsack according to p/w ratio
    while Total_Weight_Limit != 0:
        x = max(profit_weight_ratio)
        i = profit_weight_ratio.index(max(profit_weight_ratio))
        if(weights[i] <= Total_Weight_Limit):
            Total_Weight_Limit -= weights[i]
            profits_gained.append(profit_weight_ratio[i])
            weight_added.append(weights[i])
        else:
            weight_added.append(Total_Weight_Limit)
            Total_Weight_Limit = 0
            profits_gained.append(profit_weight_ratio[i])
        profit_weight_ratio[i] = -1
    total_prof = 0
    # Calculating total profit
    for i in range(len(profits_gained)):
        total_prof += profits_gained[i] * weight_added[i]
    return total_prof

profits = []
weights = []
Total_Weight_Limit = 0

# Number of Items
n = int(input("Enter number of items: "))

# Profits
print("Enter the profit for each item")
for i in range(n):
    profits.append(int(input()))

# Weights
print("Enter the weight for each item")
for i in range(n):
    weights.append(int(input()))

#Total Weight Limit (Constraint)
print("Enter the total weight limit: ")
Total_Weight_Limit = int(input())

#Output
total_profit = Knapsack(profits, weights, Total_Weight_Limit)
print(total_profit)

'''
Sample Input 1:
p = [10, 5, 15, 7, 6, 18, 3]
w = [2, 3, 5, 7, 1, 4, 1]
TW = 15
Sample Output 1:
55.333333333333336
'''
