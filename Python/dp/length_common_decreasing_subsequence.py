""" Python program to find the Length of Longest Decreasing Subsequence

Given an array we have to find the length of the longest decreasing subsequence that array can make.
The problem can be solved using Dynamic Programming.
"""


def length_longest_decreasing_subsequence(arr, n):
    max_len = 0
    dp = []
    # Initialize the dp array with the 1 as value, as the maximum length
    # at each point is atleast 1, by including that value in the sequence
    for i in range(n):
        dp.append(1)

    # Now Lets Fill the dp array in Bottom-Up manner
    # Compare Each i'th element to its previous elements from 0 to i-1,
    # If arr[i] < arr[j](where j = 0 to i-1), then it qualifies for decreasing subsequence and
    # If dp[i] < dp[j] + 1, then that subsequence  qualifies for being the longest one

    for i in range(0, n):
        for j in range(0, i):
            if(arr[i] < arr[j] and dp[i] < dp[j] + 1):
                dp[i] = dp[j] + 1

    # Now Find the largest element in the dp array
    max_len = max(dp)
    return max_len

if __name__ == '__main__':
    print("What is the length of the array? ", end="")
    n = int(input())
    if n <= 0:
        print("No numbers present in the array!!!")
        exit()
    print("Enter the numbers: ", end="")
    arr = [int(x) for x in input().split(' ')]
    res = length_longest_decreasing_subsequence(arr, n)
    print("The length of the longest decreasing subsequence of the given array is {}".format(res))


"""
Time Complexity - O(n^2), where 'n' is the size of the array
Space Complexity - O(n)

SAMPLE INPUT AND OUTPUT

SAMPLE I

What is the length of the array? 5
Enter the numbers: 5 4 3 2 1
The length of the longest decreasing subsequence of the given array is 5

SAMPLE II

What is the length of the array? 10
Enter the numbers: 15 248 31 66 84 644 54 84 5 88
The length of the longest decreasing subsequence of the given array is 4
"""
