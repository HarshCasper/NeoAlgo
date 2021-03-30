""" Length of Longest Common Substring problem in Python

Given two strings, we have to find the length of the longest common substring in Python

The problem can be solved using Dynamic Programming
"""


def lengthoflongestcommonsubstring(S1, S2):
    # Build a 2D matrix in Bottom-Up manner. Every element
    # dp[i][j] contains the length of the longest common substring
    # of S1[0 .. i] and S2[0 .. j].
    n = len(S1)
    m = len(S2)
    ans = 0
    # Fill every element of the 2D matrix with 0 as value
    dp = [[0 for i in range(m+1)] for j in range(n+1)]

    for i in range(0, n + 1):
        for j in range(0, m + 1):

            # length of LCS when one of the string is empty is zero
            if 0 in (i, j):
                dp[i][j] = 0

            # If the elements of both the strings match, then
            # the value of LCS increments by one.
            # Also Check if the value of lcs has reached the max till now.
            elif S1[i-1] == S2[j-1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
                ans = max(ans, dp[i][j])
            else:
                dp[i][j] = 0
    return ans


if __name__ == '__main__':
    s1 = input("Enter the first string: ")
    s2 = input("Enter the second string: ")
    res = lengthoflongestcommonsubstring(s1, s2)
    print("The length of the longest common substring is " + str(res))


# Time Complexity: O(n * m), where n, m are the size of the given strings
# Space Complexity: O(n * m)

# SAMPLE INPUT AND OUTPUT

# Enter the first string: runner
# Enter the second string: run
# The length of the longest common substring is 3
