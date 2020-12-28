"""
example:

grid = [['.', '.', '.'], ['.', '*', '.'], ['.', '.', '.']]
n = len(grid)
m = len(grid[0])

answer: 8
All Ways:
1. (1,1),(1,2),(1,3),(2,3),(3,3)
2. (1,1),(1,2),(1,3),(3,3)
3. (1,1),(1,3),(2,3),(3,3)
4. (1,1),(1,3),(3,3)
5. (1,1),(2,1),(3,1),(3,2),(3,3)
6. (1,1),(3,1),(3,2),(3,3)
7. (1,1),(2,1),(3,1),(3,3)
8. (1,1),(3,1),(3,3)
"""


MOD = int(1e9 + 7)
def num_of_ways_with_obstacles(grid, n, m):
    dp = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if i == 0 and j == 0:
                dp[i][j] = 1
            elif grid[i][j] == '.':
                for k in range(i - 1, -1, -1):
                    if grid[k][j] != '.':
                        break
                    dp[i][j] = (dp[i][j] + dp[k][j]) % MOD
                for k in range(j - 1, -1, -1):
                    if grid[i][k] != '.':
                        break
                    dp[i][j] = (dp[i][j] + dp[i][k]) % MOD
    return dp[n - 1][m - 1]
