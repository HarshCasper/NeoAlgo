"""
Python Program to implement the Cutting a Rod problem

We are given a rod of length 'n' and the cost of the rod of different length from
1 to n. We need to find the maximum sell price that can be obtained by cutting the rod
at any lengths.

This problem can be solved by using Dynamic Programming
"""

# Build a dp Table in Botom-Up manner, such that the n'th element stores
# the maximum price obtained by a rod of length 'n'


def max_sell_price(m, cost):
    dp = [0 for i in range(n+1)]

    for i in range(1, n + 1):
        curr_max = -1
        for j in range(i):
            curr_max = max(cost[j] + dp[i-j-1], curr_max)
        #  Stores the maximum cost obtainable for a rod of length i
        dp[i] = curr_max
    return dp[n]


if __name__ == '__main__':
    print("What is the length of the rod? ", end="")
    n = int(input())
    if (n <= 0):
        print("The given rod length is Invalid!!!")
        exit()
    print("Enter the cost of the rod for length 1 to {} :  ".format(n), end="")
    cost = [int(x) for x in input().split(' ')]
    max_price = max_sell_price(n, cost)
    print("The maximized sell price of the: {}".format(max_price))


"""
Time Complexity- O(n^2), where 'n' is the length of the rod
Space Complexity- O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

What is the length of the rod? 5
Enter the cost of the rod for length 1 to 5: 2 5 7 8 10
The maximized sell price of the: 12 

SAMPLE 2

What is the length of the rod? -3
The given rod length is Invalid!!!
"""
