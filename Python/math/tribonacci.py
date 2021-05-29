"""
Python program to find the n'th number in the tribonacci series
Tribonacci series is a generalization of the Fibonacci sequence, in which the current term
is the sum of the previous three terms.
"""

def find_tribonacci(n):
    dp = [0] * n
    dp[0] = 0
    dp[1] = 0
    dp[2] = 1

    # Compute the sum of the previous three terms
    for i in range(3,n):
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3]

    return dp[n-1]

if __name__ == '__main__':
    print("Enter the value of n?, where you need the n'th number in the tribonacci sequence. ", end="")
    n = int(input())
    if (n <= 0):
        print("The given value of n is invalid.", end="")
        exit()
res = find_tribonacci(n)
print("The {}'th term in the tribonacci series is {}.".format(n, res))


"""
Time Complexity - O(n)
Space Complexity - O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE I
Enter the value of n?, where you need the n'th number in the tribonacci sequence. 12
The 12'th term in the tribonacci series is 149.

SAMPLE II
Enter the value of n?, where you need the n'th number in the tribonacci sequence. 1254
The 1254'th term in the tribonacci series is 4020147461713125140.
"""
