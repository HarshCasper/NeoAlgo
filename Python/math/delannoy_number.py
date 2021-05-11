"""
Python program to find the Delannoy number for a given rectangular grid.
A Delannoy number describes the number of paths from the southwest corner 
(0, 0) of a rectangular grid to the northeast corner (m, n) using only single steps north, northeast, or east.
Delannoy number is named after the French mathematican Henri Delannoy.
"""

def delannoy_number(r, c):

    # Initialize the dp array with '0' as value.
    dp = [[0 for k in range(r+1)] for k in range(c+1)]

    for i in range(c):
        dp[0][i] = 1

    for i in range(1, c+1):
        dp[i][0] = 1

    # From Each point calculate the number of paths, to the north-east point, that can be reached by
    # traversing through the immediate right or immediate top or immediate top-right point.
    for i in range(1, c+1):
        for j in range(1, r+1):
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i][j-1]

    return dp[c][r]


if __name__ == '__main__':
    print("Enter the co-ordinates of the north-east corner.\nEnter the row co-ordinate: ", end="")
    x = int(input())
    print("Enter the column co-ordinate: ", end="")
    y = int(input())
    res = delannoy_number(x, y)
    print("The Delannoy number of the given grid is {}.".format(res))


"""
Time Complexity - O(x * y), where `x`, `y` is the given co-ordinates.
Space Complexity - O(1)

SAMPLE INPUT AND OUTPUT

SAMPLE I

Enter the co-ordinates of the north-east corner.
Enter the row co-ordinate: 5
Enter the column co-ordinate: 6
The Delannoy number of the given grid is 3653.
"""
