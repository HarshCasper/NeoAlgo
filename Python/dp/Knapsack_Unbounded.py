"""
Unbounded Knapsack problem using dp (Unbounded means all the given weights are available in infinite quantity)
Given weights and their corresponding values,
We fill knapsack of capacity W to obtain maximum possible value(or profit). We can pick same weight more than once.
N: Number of (items)weight elements
W: Capacity of knapsack
Time Complexity: O(N*W) (Optimizing knapsack at capacities from 0 to W gradually using all N items)
Space Complexity: O(W) (knapsack array)
"""


def unbounded_knapsack(capacity, weights, values):

    # 'items' variable represents number of weight elements
    items = len(values)

    # Initializing 1-d array knapsack values as 0
    knapsack = [0 for x in range(capacity + 1)]

    # Iterating to given capacity from 0
    for current_capacity in range(capacity + 1):

        # Iterating through all the items
        for i in range(items):

            # If the weight of item is less then current_capacity, it can be used in knapsack
            if (weights[i] <= current_capacity):

                knapsack[current_capacity] = max(
                    # Current item is not utilised
                    knapsack[current_capacity],
                    knapsack[current_capacity - weights[i]] + values[i])
                # Current item is utilised, so knapsack value for current_capacity changes to
                # value of current item + knapsack value when capacity is current_capacity-weight of utilised item

    return knapsack[capacity]


if __name__ == '__main__':

    print("Enter capacity:")
    capacity = int(input())
    print("Enter weights:")
    weights = list(map(int, input().split()))
    print("Enter values:")
    values = list(map(int, input().split()))

    print(unbounded_knapsack(capacity, weights, values))

"""
Sample Input:
capacity = 50
weights = 1 5 10
values = 10 50 100

Sample Output:
500
"""
