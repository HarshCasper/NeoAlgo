def sum(array, initial, to):
    total = 0
    for i in range(initial, to + 1):
        total += array[i]
    return total


def partition(array, N, K):
    if K == 1:
        return sum(array, 0, N - 1)
    if N == 1:
        return array[0]
    best = 100000000
    for i in range(1, N + 1):
        best = min(best,
                   max(partition(array, i, K - 1),
                       sum(array, i, N - 1)))
    return best
N, K, T = map(int, input("Enter array size, number
                         of painters and time: ").split())
x = list(map(int, input("Enter board sizes:").split()))
res = partition(x, N, K)
print("Minimum time required to paint all the boards: " + str(res * T))

"""
Example 1:
Sample Input:
Enter array size, number of painters and time: 2 2 5
Enter board sizes: 1 10
Minimum time required to paint all the boards: 50

Time complexityL O(k*N^3) (Exponential)
"""
