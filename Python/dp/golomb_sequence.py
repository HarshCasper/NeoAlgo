"""
Python program to print the n'th term in the Golomb sequence
Golomb sequence is a non-decreasing integer sequence where n'th
term is  equal to the number of times n appears in the sequence
"""


def golomb_sequence(n):

    # Create a dp array, with value initialized as 0.
    dp = [0 for i in range(n+1)]

    dp[1] = 1
    # Identify the previous term 'prev' and go prev terms behind and find a number.
    # Now assign the current element with an incremented value of that element.
    for i in range(2, n + 1):
        prev = dp[i - 1]
        back_index = i - dp[prev]
        dp[i] = 1 + dp[back_index]
    return dp[n]

if __name__ == '__main__':
    print("Enter the value of n?, where you need the n'th number in the golomb sequence. ", end="")
    num = int(input())
    if num <= 0:
        print("The given value of n is invalid.")
        exit()
    res = golomb_sequence(num)
    print("The {}'th term in the golomb sequence is {}.".format(num, res))

"""
Time Complexity: O(n), where 'n' is the given number
Space Complexity: O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE 1

Enter the value of n?, where you need the n'th number in the golomb sequence. 5
The 5'th term in the golomb sequence is 3.

SAMPLE 2

Enter the value of n?, where you need the n'th number in the golomb sequence. 867
The 867'th term in the golomb sequence is 79.
"""
