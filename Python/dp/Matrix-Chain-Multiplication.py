'''
Problem statement-
Given a chain of matrices A1, A2, A3,.....An, we have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.

You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You will have to find the minimum number of multiplications needed to multiply the chain.

Logical Intuition-
We place out paranthesis in all possible positions and calculate the cost to multiply the matrices. We will store them in the array 'dp'.
Then we will choose the minimum cost required to multiply the matrices.
'''


import sys


def mcm(arr, i, j, dp):
    '''
    Summary line:
        This function helps us to find the minimum cost
        required to multiply matrices.

    Args:
        arr: array of dimensions of matrices
        i: starting index of arr
        j: length of arr
        dp: python list used for memoization

    Returns:
        Minimum cost to multiply.

    '''
    if i >= j: #base case
        return 0
    ans = sys.maxsize
    for k in range(i, j):
        if dp[i][k] != -1:
            ans1 = dp[i][k]
        else:
            ans1 = mcm(arr, i, k, dp)
            dp[i][k] = ans1
        if dp[k+1][j] != -1:
            ans2 = dp[k+1][j]
        else:
            ans2 = mcm(arr, k+1, j, dp)
            dp[k+1][j] = ans2
        ans3 = arr[i-1]*arr[k]*arr[j] #calculating the cost
        cost = ans1+ans2+ans3 #taking sum of cost calculated for a particular position of paranthesis
        ans = min(ans, cost) # returning the min cost
    return ans

if __name__ == "__main__":
    n = int(input())
    arr = [int(i) for i in input().split()]
    dp = [[-1 for j in range(n+1)]for i in range(n+1)] #initalizing dp array of size nXn with -1
    print(mcm(arr, 1, n, dp))


'''
Sample input-
3
10 15 20 25

Sample output-
8000
'''
