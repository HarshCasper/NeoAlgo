'''
Tiling problem 2xN
Problem Statement:
Given a 2 x n board and tiles of dimension 2 x 1,
count the number of ways to tile the given board using the 2 x 1 tiles.
A tile can either be placed horizontally, as a 1 x 2 tile or vertically, as 2 x 1 tile.
'''


def numberOfWays(num):
    # base cases
    if num < 1:
        return 0
    if num < 2:
        return 1
# temporary list to stores the number of ways to fill 2xi grid
    ways = [None] * (num + 1)
    ways[1] = ways[2] = 1
# storing the ways in the temporary list using dynamic programming
    for i in range(3, num+1):
        ways[i] = ways[i-1] + ways[i-2]
    return ways[num]

if __name__ == '__main__':
    n = int(input())  # taking input from the user
    # calling the function to calculate number of ways and printing it
    print("Number of ways is:", numberOfWays(n))


'''
Test Case 1:
Input: 4
Output: Number of ways is: 3

Test Case 2:
Input: 10
Output: Number of ways is: 55

Time Complexity: O(n)
Space Complexity: O(n)
'''
