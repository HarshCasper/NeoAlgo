"""
Consider the matrix chain algorithm in the following example.

We have a example matrix chain: [10, 100, 5, 50]
which represents a multiplication of three matrix
first matrix A1 with shape [10 x 100], second A2 [100 x 5], third A3 [5 x 50]
For this example, we have only 2 possible combinations
for matrix multiplication,
first multiply (A1 x A2) and then (A1A2 x A3)
the second (A2 x A3) and then (A1 x A2A3)

The computational cost of these operations is:
- (A1 x A2) x A3 = (10 * 100 * 5) + (10 * 5 * 50) = 7500
- A1 x (A2 x A3) = (10 * 100 * 50) + (100 * 5 * 50) = 75000

The matrix chain algorithm select operation with lower computational cost.

Time Complexity: O(n^3)
Auxiliary Space: O(n^2)

"""


import sys

def chain_matrix_multiplication(matrices, i, j):
    if i == j:
        return 0

    cMin = sys.maxsize
    
    for k in range(i, j):
        count = chain_matrix_multiplication(matrices, i, k) + chain_matrix_multiplication(matrices, k + 1, j) + (
            matrices[i - 1] * matrices[k] * matrices[j])

        if count < cMin:
            cMin = count

        k += 1
    return cMin


arr = [5,2,4,9,1]
print(chain_matrix_multiplication(arr, 1, len(arr) - 1))


def matrix(m, n):
    return [[0] * n for _ in range(m)]

def matrix_chain_order(p):
    n = len(p) - 1  # number of matrices in input
    costs = matrix(n, n)  # an empty nxn cost matrix
    s = matrix(n, n)  # length: number of matrices to consider
   
    for length in range(2, n + 1):  # start from 2 because we don't need to calculate multiplication for one matrix
        # since its 0 (default value)
        # i: the 0-index of the matrix
        for i in range(n - length + 1):
            # j: the 0-index of the j matrix
            j = i + length - 1
            costs[i][j] = float('inf')
            # k: the 0-index of the matrix whose right edge is considered
            # the k. Note: this is not the same as the actual index to
            # the right edge (which is k + 1).
            for k in range(i, j):
                possible_cost = costs[i][k] + costs[k + 1][j] + p[i] * p[k + 1] * p[j + 1]
                if possible_cost < costs[i][j]:
                    costs[i][j] = possible_cost
                    s[i][j] = k
    return costs, s


def print_matrix_chain(S, i, j):
    if i == j:
        return " A_" + str(i) + " "
    else:
        s = "("
        k = S[i][j]
        s += print_matrix_chain(S, i, k)
        s += print_matrix_chain(S, k + 1, j)
        s += ")"
        return s

t, s = matrix_chain_order(arr)
print(print_matrix_chain(s, 1, 3))
