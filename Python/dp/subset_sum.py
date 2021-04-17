""" Subset Sum Problem in Python

Given a set of integers, and a value, we have to check if there exist a subset such that
its sum is equal to the given value

The problem can be solved using Dynamic Programming
"""


def subsetSum(arr, size, S):
    # A 2D List containing boolean values, True and False
    # Fill every element of the 2D list with False as value
    dp = ([[False for i in range(S + 1)] for i in range(n + 1)])

    for i in range(0, size + 1):
        for j in range(0, S + 1):

            # Sum = 0 is always possible, by taking no elements in the subset
            if j == 0:
                dp[i][0] = True

            if i > 0:
                # If the value of current element is less than sum j, then either
                # include it and the current element or leave it and take previous best
                if arr[i - 1] <= j:
                    dp[i][j] = dp[i - 1][j] or dp[i - 1][j - arr[i - 1]]
                # Else take the previous best
                else:
                    dp[i][j] = dp[i - 1][j]

    return dp[size][S]


if __name__ == '__main__':
    print("How many numbers are there in the set? ", end="")
    n = int(input())
    print("Enter the numbers in the set: ", end="")
    a = [int(x) for x in input().split(' ')]
    print("Enter the sum value: ", end="")
    s = int(input())
    res = subsetSum(a, n, s)
    if res is False:
        print("No subset adds upto given sum")
    else:
        print("Subset with given sum is present")


# Time Complexity: O(sum * size of array)
# Space Complexity: O(sum * size of array)

# SAMPLE INPUT AND OUTPUT

# How many numbers are there in the set? 6
# Enter the numbers in the set: 3 34 4 12 5 2
# Enter the sum value: 9
# Subset with given sum is present
