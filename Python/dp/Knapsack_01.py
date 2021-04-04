"""
Knapsack 0-1 problem using dp (0-1 means we either choose it or we don't, no fractions)
Given weights and their corresponding values,
We fill knapsack of capacity W to obtain maximum possible value in bottom-up manner.
N: Number of (items)weight elements 
W: Capacity of knapsack
Time Complexity: O(N*W)(Looping through the matrix)
Space Complexity: O(N*W)(Space taken by matrix - knapsack_table)
"""


def knapsack(capacity, weights, values):
    # 'items' variable represents number of weight elements
    items = len(weights)

    # Initializing knapsack_table values as 0
    knapsack_table = [[0 for x in range(capacity + 1)]
                      for x in range(items + 1)]

    # Updating knapsack_table[][] in bottom up manner
    for i in range(items + 1):

        # Note that list is 0-based, so to get i_th item we do i-1
        for j in range(capacity + 1):

            # i=0 means no items available to put
            # j=0 means no capacity remains to be filled
            if i == 0 or j == 0:
                knapsack_table[i][j] = 0

            # Weight of item is greater than current capacity, so we cannot use it
            # So knapsack value here is the best we can do without this item ie. with the (i-1)th item
            elif weights[i-1] > j:
                knapsack_table[i][j] = knapsack_table[i-1][j]

            # Weight of item is less than current capacity, so we can use it to optimize knapsack
            else:
                knapsack_table[i][j] = max(
                    # If i_th item is included,
                    # knapsack value is equal to it's value + best we can do(ie. value of knapsack_table):
                    # 1) without this item(with the previous one) and
                    # 2) capacity being current capacity(j) - weight of i_th item
                    values[i-1] + knapsack_table[i-1][j-weights[i-1]],
                    knapsack_table[i-1][j])  # i_th item is not included

    return knapsack_table[items][capacity]


if __name__ == '__main__':

    print("Enter Capacity:")
    capacity = int(input())
    print("Enter weights:")
    weights = list(map(int, input().split()))
    print("Enter values:")
    values = list(map(int, input().split()))

    print(knapsack(capacity, weights, values))

"""
Sample Input:
capacity = 50
weights = 1 5 10
values = 10 50 100
Sample Output:
160
"""
